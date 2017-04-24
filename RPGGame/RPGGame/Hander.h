#ifndef __MANAGER_H__
#define __MANAGER_H__

#include "Config.h"
#include "Cmd.h"
#include "Req.h"
#include "Rsp.h"


class App;
/**
* @brief ������
*/
class Hander
{
public:
	Hander();
	virtual ~Hander();
public:
	/**
	* @brief ��ʼ��
	*/
	virtual bool Init(Config *pConfig);
	/**
	* @brief ����ģ��
	*/
	virtual int Start();
	/**
	* @brief ֹͣģ��
	*/
	virtual int Stop();
	/**
	* @brief �ͷ�ģ��
	*/
	virtual void Finish();
public:
    /**
    * @brief ת�����͵�����
    */
    int Forword(const cmd::Command eCmd, req::Req &oReq, rsp::Rsp &oRsp);

    /**
    * @brief ת�����͵�֪ͨ
    */
    void Notify(const cmd::Notify eNotify, const rsp::Rsp &oRsp);
public:
	/**
	* @brief ·�����������
	*/
	virtual int Handle(const cmd::Command eCmd, req::Req &oReq, rsp::Rsp &oRsp) = 0;

    /**
    * @brief ·��֪ͨ��������
    */
    virtual void Handle(const cmd::Notify eNotify, const rsp::Rsp &stRsp) = 0;
protected:
	/**
	* @brief ע�ᴦ����
	*/
	void RegisterCmd(const cmd::Command eCmd);

	/**
	* @brief ע��������
	*/
	void UnRegisterCmd(const cmd::Command eCmd);
};


#endif // __MANAGER_H__

