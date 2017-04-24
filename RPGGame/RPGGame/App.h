#ifndef __RPGAPP_H__
#define __RPGAPP_H__

#include <map>

using std::multimap;
using std::pair;

#include "Cmd.h"
#include "Singleton.h"
#include "FrameHander.h"
#include "ManagerHander.h"


/*!< ��ʵ�� */
#define g_FrameHander FrameHander::GetInstance()

/*!< ����ʵ�� */
#define g_ManagerHander ManagerHander::GetInstance()

/*!< Ӧ��ʵ�� */
#define g_App App::GetInstance()

/**
* @brief Ӧ���࣬�����������ģ��
*/
class App : public Singleton<App>
{
public:
	/**
	* @brief ��ʼ��
	*/
	virtual bool Init();
	/**
	* @brief ����Ӧ�÷���
	*/
	virtual int Start();
	/**
	* @brief ֹͣӦ�÷���
	*/
	virtual int Stop();
	/**
	* @brief ����Ӧ�÷���
	*/
	virtual void Finish();

public:
	/**
	* @brief �������Ĵ�����
	*/
	int AddCmdHandle(cmd::Command eCmd, Hander& oManager);

	/**
	* @brief �Ƴ�����Ĵ�����
	*/
	int RemoveCmdHandle(cmd::Command eCmd, Hander& oManager);

	/**
	* @brief ��������
	*/
	int Handler(cmd::Command eCmd, req::Req &oReq, rsp::Rsp &oRsp);

    /**
    * @brief ����֪ͨ
    */
    void Notify(cmd::Notify eNotify, const rsp::Rsp &oRsp);
private:
	typedef multimap <cmd::Command, Hander&>::const_iterator MMapIt;
	/*!< ����ʹ�������ӳ���ϵ */
	multimap<cmd::Command, Hander&> m_mmapCmdToHanders;

	/*!< �Ƿ����� */
	bool m_bIsRuning;
};




#endif // __RPGAPP_H__
