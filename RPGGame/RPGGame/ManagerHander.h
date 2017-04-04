#ifndef __HANDERIMPLEMENT_H__
#define __HANDERIMPLEMENT_H__


#include "Cmd.h"
#include "Singleton.h"
#include "Hander.h"

using cmd::Command;



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
public:
	/**
	* @brief �ַ��������������
	*/
	virtual int Handle(int iCmd, Req &oReq, Rsp &oRsp);

private:
	/**
	* @brief չʾ����
	*/
	int HandleShowBag(int iCmd, Req &oReq, Rsp &oRsp);

	/**
	* @brief չʾ��Ʒ
	*/
	int HandleShowItem(int iCmd, Req &oReq, Rsp &oRsp);
};



#endif