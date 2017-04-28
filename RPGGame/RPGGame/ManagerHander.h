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
    virtual void Handle(const cmd::Notify eNotify, const notify::Notify &oNotify);
private:
	/**
	* @brief չʾ����
	*/
	int HandleShowBag(cmd::Command eCmd, req::Req &oReq, rsp::Rsp &oRsp);

	/**
	* @brief չʾ��Ʒ
	*/
	int HandleShowItem(cmd::Command eCmd, req::Req &oReq, rsp::Rsp &oRsp);

    /**
     * @brief չʾ�̵�
     */
    int HandleShowShop(cmd::Command eCmd, req::Req &oReq, rsp::Rsp &oRsp);

    /**
    * @brief չʾ��Ʒ
    */
    int HandleShowShopItem(cmd::Command eCmd, req::Req &oReq, rsp::Rsp &oRsp);

    /**
    * @brief ����Ʒ
    */
    void HandleBuyShopItem(const cmd::Notify eNotify,const notify::Notify &oNotify);

};



#endif