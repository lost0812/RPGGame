#ifndef __EVENTMANAGER_H__
#define __EVENTMANAGER_H__

#include <time.h>
#include <conio.h>

#include "Manager.h"
#include "UIBase.h"
#include "Event.h"

//��С����ʱ����(ms)
#define TIMEGAP_MIN 10
//��ʱ������ʱ����(ms)
#define TIMEGAP_TIMER 100
//���̼���ʱ����(ms)
#define TIMEGAP_KEYBOARD 10

//ÿ�μ���ʱ��(ms)
#define TIMEGAP_MAX 10000

class EventManager :public Manager
{
public:
	EventManager();
	~EventManager();
public:
	virtual bool Init(App* pApp, Config *pConfig);

private:
	virtual int Handle(int iCmd, Req &oReq);
private:
	int m_iTimerCount;
};


#endif // __EVENTMANAGER_H__

