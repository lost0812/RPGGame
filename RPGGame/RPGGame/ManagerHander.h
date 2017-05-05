#ifndef __HANDERIMPLEMENT_H__
#define __HANDERIMPLEMENT_H__


#include "Cmd.h"
#include "Singleton.h"
#include "Hander.h"
#include "ItemLoader.h"

/**
* @brief �������࣬��������Ż��ӿ�
*/
class ManagerHander :public Singleton<ManagerHander>,public Hander
{
public:
	ManagerHander();
	~ManagerHander();
public:
	/**
	* @brief ��ʼ��
	*/
	virtual bool Init(Config *pConfig);

    /**
    * @brief ����ģ��
    */
    virtual int Start();
public:
	/**
	* @brief �ַ��������������
	*/
	virtual int Handle(const cmd::Command eCmd, req::Req &oReq, rsp::Rsp &oRsp);

    /**
    * @brief ·��֪ͨ��������
    */
    virtual void Handle(const cmd::NotifyCommand eNotify, const notify::Notify &oNotify);
private:
	/**
	 * @brief չʾ����
	 */
	int HandleShowBag(const cmd::Command eCmd, const  req::Req &oReq, rsp::Rsp &oRsp);

	/**
	 * @brief չʾ��Ʒ
	 */
	int HandleShowItem(const cmd::Command eCmd, const  req::Req &oReq, rsp::Rsp &oRsp);

    /**
     * @brief չʾ�̵�
     */
    int HandleShowShop(const cmd::Command eCmd, const req::Req &oReq, rsp::Rsp &oRsp);

    /**
     * @brief չʾ��Ʒ
     */
    int HandleShowShopItem(const cmd::Command eCmd, const req::Req &oReq, rsp::Rsp &oRsp);

    /**
    * @brief չʾ�ֿ�
    */
    int HandleShowStorage(const cmd::Command eCmd, const req::Req &oReq, rsp::Rsp &oRsp);

    /**
     * @brief չʾ�ֿ���Ʒ
     */
    int HandleShowStorageItem(const cmd::Command eCmd, const req::Req &oReq, rsp::Rsp &oRsp);

    /**
    * @brief �ڼ�չʾ����
    */
    int HandleHomeShowBag(const cmd::Command eCmd, const req::Req &oReq, rsp::Rsp &oRsp);

    /**
    * @brief �ڼ�չʾ������Ʒ
    */
    int HandleHomeShowBagItem(const cmd::Command eCmd, const req::Req &oReq, rsp::Rsp &oRsp);







    /**
     * @brief ����Ʒ
     */
    void HandleBuyShopItem(const cmd::NotifyCommand eNotify,const notify::Notify &oNotify);

    /**
    * @brief ����Ʒ
    */
    void HandleSellShopItem(const cmd::NotifyCommand eNotify, const notify::Notify &oNotify);

    /**
     * @brief ȡ���ֿ�
     */
    void HandleStorageTakeOut(const cmd::NotifyCommand eNotify, const notify::Notify &oNotify);

    /**
     * @brief ��Ųֿ�
     */
    void HandleStorageDeposit(const cmd::NotifyCommand eNotify, const notify::Notify &oNotify);

};



#endif