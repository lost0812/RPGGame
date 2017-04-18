#ifndef __FRAMEMANAGER_H__
#define __FRAMEMANAGER_H__

#include <list>

#include "Singleton.h"
#include "Hander.h"
#include "Frame.h"

using std::list;
using cmd::Command;

/**
* @brief ������
*/
class FrameHander : public Singleton<FrameHander>,public Hander
{
public:
	FrameHander();
	virtual ~FrameHander();
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
	 * @brief ������н���
	 */
	int HandleIdle(Req &oReq);

	/**
	 * @brief ����ʼ����
	 */
	int HandleStart(Req &oReq);
private:
	/**
	 * @brief ��������·��
	 */
	virtual int Handle(cmd::Command eCmd, Req &oReq, Rsp &oRsp);

private:
	/*!< ��ʾ���ջ */
	list<Frame*> m_lsFrames;
};

#endif // __FRAMEMANAGER_H__
