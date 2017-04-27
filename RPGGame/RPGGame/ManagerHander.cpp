#include "ManagerHander.h"

#include "PlayerManager.h"
#include "ItemManager.h"
#include "ShopManager.h"

#include "StrUtil.h"

/*!< ���ʵ�� */
#define g_PlayerManger PlayerManager::GetInstance()

/*!< ��Ʒʵ�� */
#define g_ItemManager  ItemManager::GetInstance()

/*!< �̵�ʵ�� */
#define g_ShopManager ShopManager::GetInstance()

ManagerHander::ManagerHander()
{
}


ManagerHander::~ManagerHander()
{
}

bool ManagerHander::Init(Config *pConfig)
{
	if (!Hander::Init(pConfig))
		return false;

	if (!g_PlayerManger.Init())
		return false;
	if (!g_ItemManager.Init())
		return false;
    if (!g_ShopManager.Init())
        return false;

    RegisterCmd(cmd::COMMAND_SHOW_BAG);
    RegisterCmd(cmd::COMMAND_SHOW_ITEM);
    RegisterCmd(cmd::COMMAND_SHOW_SHOP);
    RegisterCmd(cmd::COMMAND_SHOW_SHOP_ITEM);

    RegisterNotify(cmd::NOTIFY_SHOP_BUY);

	return true;
}

int ManagerHander::Handle(cmd::Command eCmd, req::Req &oReq, rsp::Rsp &oRsp)
{
	switch (eCmd)
	{
	case cmd::COMMAND_SHOW_BAG:
		return HandleShowBag(eCmd, oReq, oRsp);
	case cmd::COMMAND_SHOW_ITEM:
		return HandleShowItem(eCmd, oReq, oRsp);
    case cmd::COMMAND_SHOW_SHOP:
        return HandleShowShop(eCmd, oReq, oRsp);
    case cmd::COMMAND_SHOW_SHOP_ITEM:
        return HandleShowShopItem(eCmd, oReq, oRsp);
	default:
		break;
	}
	return -1;
}

void ManagerHander::Handle(const cmd::Notify eNotify, const notify::Notify &oNotify)
{
    switch (eNotify)
    {
    case cmd::NOTIFY_SHOP_BUY:
        HandleBuyShopItem(eNotify, oNotify);
    default:
        break;
    }
}

int ManagerHander::HandleShowBag(cmd::Command eCmd, req::Req &oReq, rsp::Rsp &oRsp)
{
	const Container &bag = g_PlayerManger.GetBag();

	vector<rsp::Rsp> vRsps;
	for (int i = 0; i < bag.GetCapacity(); ++i)
	{
        int iItemID = bag.GetItemID(i);
        if (iItemID!=0)
        {
            rsp::Rsp tmp;
            tmp.Add("id", iItemID);
            tmp.Add("description", g_ItemManager.GetDescriptionByID(iItemID));
		    vRsps.push_back(tmp);
        }

	}
    if (vRsps.size() == 0)
    {
        oRsp.Add(rsp::i_RetCode, rsp::Rsp::RETCODE_NO_ITEM);
    }
    else
    {
        oRsp.Add(rsp::i_RetCode, 0);
        oRsp.Add("bag", vRsps);
    }

	return 0;
}

int ManagerHander::HandleShowItem(cmd::Command eCmd, req::Req &oReq, rsp::Rsp &oRsp)
{
	int iSelected = oReq.GetInt("selected");
	const Container &bag = g_PlayerManger.GetBag();
	int iID = bag.GetItemID(iSelected);
	string sDescription = g_ItemManager.GetDescriptionByID(iID);

	oRsp.Add("description", sDescription);

	return 0;
}

int ManagerHander::HandleShowShop(cmd::Command eCmd, req::Req &oReq, rsp::Rsp &oRsp)
{
    ShopManager &oShopManager = ShopManager::GetInstance();
    int iSize = oShopManager.GetNumberOfGoodsCategory();

    vector<rsp::Rsp> vRsp;
    for (int i = 0; i < iSize; ++i)
    {
        rsp::Rsp stRspShopItem;
        stRspShopItem.Add(rsp::i_ShopItem_ItemID,oShopManager.GetGoodsItemID(i));
        stRspShopItem.Add(rsp::i_ShopItem_Amount,oShopManager.GetGoodsAmount(i));
        stRspShopItem.Add(rsp::i_ShopItem_Price, oShopManager.GetGoodsPrice(i));
        vRsp.push_back(stRspShopItem);
    }
    oRsp.Add(rsp::i_RetCode, rsp::Rsp::RETCODE_SUCCEED);
    oRsp.Add(rsp::v_ShopItem, vRsp);
    return 0;
}

int ManagerHander::HandleShowShopItem(cmd::Command eCmd, req::Req &oReq, rsp::Rsp &oRsp)
{
    int iIndex = oReq.GetInt(req::i_Index);

    ShopManager &oShopManager = ShopManager::GetInstance();

    int iNum = oShopManager.GetNumberOfGoodsCategory();

    if (iNum > iIndex)
    {
        int iItemID = oShopManager.GetGoodsItemID(iIndex);
        const ItemData stItemData = ItemLoader::GetInstance().GetItemDataByID(iItemID);

        oRsp.Add(rsp::i_RetCode, rsp::Rsp::RETCODE_SUCCEED);
        oRsp.Add(rsp::s_ItemDescription, stItemData.sDescription);
        oRsp.Add(rsp::i_ShopItem_Price, oShopManager.GetGoodsPrice(iIndex));
        oRsp.Add(rsp::i_ShopItem_Amount, oShopManager.GetGoodsAmount(iIndex));
    }
    else
    {
        oRsp.Add(rsp::i_RetCode, rsp::Rsp::RETCODE_NO_ITEM);
    }

    return 0;
}

void ManagerHander::HandleBuyShopItem(const cmd::Notify eNotify, const notify::Notify &oNotify)
{
    //�������
    notify::Notify oRspNotify;
    if (oNotify.HasInt(notify::i_Index))
    {
        oRspNotify.Add(notify::s_TipsFrame_Description, "��ѡ����Ʒ");
        Notify(cmd::NOTIFY_UPDATE_INFORMATION, oRspNotify);
        return;
    }

    //��ȡ��Ʒ
    int i_Index = oNotify.GetInt(notify::i_Index);
    const ShopManager::VecGoods &vGoods = ShopManager::GetInstance().GetAllGoods();
    int iSize = vGoods.size();
    if (i_Index < 0 || i_Index >iSize)
    {
        oRspNotify.Add(notify::s_TipsFrame_Description, "ѡ����Ʒ������");
        Notify(cmd::NOTIFY_UPDATE_INFORMATION, oRspNotify);
        return;
    }

    //��ҹ���
    const Goods &oGoods = vGoods.at(i_Index);
    if (!PlayerManager::GetInstance().Buy(oGoods))
    {
        oRspNotify.Add(notify::s_TipsFrame_Description, "��ҹ���ʧ��");
        Notify(cmd::NOTIFY_UPDATE_INFORMATION, oRspNotify);
        return;
    }

    //�ر�
    string sItemName = ItemManager::GetInstance().GetDescriptionByID(oGoods.GetItemID());
    oRspNotify.Add(
        notify::s_TipsFrame_Description, 
        StrUtil::Format(
            "����:%s*%d,���ѣ�%d", 
            sItemName.c_str(),
            oGoods.GetAmount(),
            oGoods.GetPrice()));
    Notify(cmd::NOTIFY_UPDATE_INFORMATION, oRspNotify);
    return;
}
