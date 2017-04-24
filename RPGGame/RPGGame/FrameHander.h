#ifndef __FRAMEMANAGER_H__
#define __FRAMEMANAGER_H__

#include <list>

#include "Singleton.h"
#include "Hander.h"
#include "FrameWithOption.h"


using std::list;

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
	int HandleIdle(req::Req &oReq);

	/**
	 * @brief ����ʼ����
	 */
	int HandleStart(req::Req &oReq);
private:
	/**
	 * @brief ��������·��
	 */
	virtual int Handle(const cmd::Command eCmd, req::Req &oReq, rsp::Rsp &oRsp);

    /**
     * @brief ����֪ͨ·��
     */
    virtual void Handle(const cmd::Notify eNotify, const rsp::Rsp &stRsp);
private:
	/*!< ��ʾ���ջ */
	list<FrameWithOption*> m_lsFrames;
};

#endif // __FRAMEMANAGER_H__
