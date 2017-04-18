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
	int Forword(cmd::Command eCmd, req::Req &oReq, rsp::Rsp &oRsp);
public:
	/**
	* @brief ·�����������
	*/
	virtual int Handle(cmd::Command eCmd, req::Req &oReq, rsp::Rsp &oRsp) = 0;
protected:
	/**
	* @brief ע�ᴦ����
	*/
	void RegisterCmd(cmd::Command eCmd);

	/**
	* @brief ע��������
	*/
	void UnRegisterCmd(cmd::Command eCmd);
};


#endif // __MANAGER_H__

