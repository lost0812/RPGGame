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
	int Forword(int iCmd, Req &oReq, Rsp &oRsp);
public:
	/**
	* @brief ·�����������
	*/
	virtual int Handle(int iCmd, Req &oReq, Rsp &oRsp) = 0;
protected:
	/**
	* @brief ע�ᴦ����
	*/
	void RegisterCmd(int iCmd);

	/**
	* @brief ע��������
	*/
	void UnRegisterCmd(int iCmd);
};


#endif // __MANAGER_H__

