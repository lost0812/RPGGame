#ifndef __RPGAPP_H__
#define __RPGAPP_H__

#include <map>

using std::multimap;
using std::pair;

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
	int AddCmdHandle(int iCmd, Hander& oManager);

	/**
	* @brief �Ƴ�����Ĵ�����
	*/
	int RemoveCmdHandle(int iCmd, Hander& oManager);

	/**
	* @brief ��������
	*/
	int Handler(int iCmd, Req &oReq, Rsp &oRsp);

private:
	typedef multimap <int, Hander&>::const_iterator MMIter;
	/*!< ����ʹ�������ӳ���ϵ */
	multimap<int, Hander&> m_mmapCmdToHanders;

	/*!< �Ƿ����� */
	bool m_bIsRuning;
};




#endif // __RPGAPP_H__
