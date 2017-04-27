#ifndef __SHOPMANAGER_H__
#define __SHOPMANAGER_H__

#include "Singleton.h"
#include "Goods.h"



class ShopManager :public Singleton<ShopManager>
{
public:
    typedef vector<Goods> VecGoods;
    typedef vector<Goods>::iterator VecGoodsIt;
public:
    ShopManager();
    ~ShopManager();
public:
    /**
    * @brief ��ʼ��
    */
    virtual bool Init();

public:
    /**
     * @brief ��ȡȫ����Ʒ��Ϣ
     */
    const ShopManager::VecGoods &GetAllGoods()const;

    /**
     * @brief ��ȡ��Ʒ��Ϣ
     */
    bool GetGoods(const int iIndex, Goods &stGoods)const;

    /**
     * @brief ������Ʒ
     */
    bool SellGoods( const int iPrice, const int iGoodID );

    /**
     * @brief ��ȡ��Ʒ�������
     */
    int GetNumberOfGoodsCategory()const;

    /**
     * @brief ��ȡ��Ʒ����Ʒ���
     */
    int GetGoodsItemID(const int index)const;

    /**
     * @brief ��ȡ��Ʒ����
     */
    int GetGoodsAmount(const int index)const;

    /**
     * @brief ��ȡ��Ʒ�۸�
     */
    int GetGoodsPrice(const int index)const;
private:
    /*!< ��Ʒ */
    VecGoods m_vGoods;
};



#endif // __SHOPMANAGER_H__


