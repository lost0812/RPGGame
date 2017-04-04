#include "FrameHander.h"
#include "ArrowManager.h"
#include "Cmd.h"
#include "FrameLoader.h"

#include <iostream>

using namespace std;

FrameHander::FrameHander()
{

}

FrameHander::~FrameHander()
{

}

bool FrameHander::Init(Config *pConfig)
{
	if (!FrameLoader::GetInstance().Init())
		return false;

	RegisterCmd(cmd::COMMAND_IDLE);
	RegisterCmd(cmd::COMMAND_START);

	return true;
}

int FrameHander::Start()
{
	int iRet = Hander::Start();
	if (iRet != 0)
		return iRet;
	//todo
	return 0;
}

int FrameHander::Stop()
{
	int iRet = Hander::Stop();
	if (iRet != 0)
		return iRet;
	//todo
	return 0;
}

void FrameHander::Finish()
{

}

int FrameHander::HandleIdle(Req &oReq)
{
	return 1;
}

int FrameHander::HandleStart(Req &oReq)
{
	FrameLoader &oFrameLoader = FrameLoader::GetInstance();
	Frame *pFrame = oFrameLoader.GetFrameByID(0);
	m_lsFrames.push_back(pFrame);


	int iFrameID;
	bool bFlash = true;
	int iSelected;

	bool bIsRuning = true;
	while (bIsRuning)
	{
		pFrame = m_lsFrames.back();
		//ˢ����ͼ
		//if (bFlash)
		if(true)
		{
			clear();
//			list<Frame*>::const_iterator cpIt;
//			for (cpIt = m_lsFrames.begin();cpIt != m_lsFrames.end();++cpIt)
//				(*cpIt)->Show();
		}
		pFrame->Show();

		ArrowManager &oArrowManager = ArrowManager::GetInstance();
		oArrowManager.Init(
			pFrame->GetDirection(), 
			pFrame->GetOptionPosition(), 
			pFrame->GetOptions() );
		iSelected = oArrowManager.GetSelectIndex();
		do
		{
			//û��ѡ��
			if (iSelected < 0)
			{
				//�������浯��ջ
				if (m_lsFrames.size() > 1)
				{
					m_lsFrames.pop_back();
					oFrameLoader.ReleaseFrame(pFrame);
					bFlash = true;
				}
				break;
			}
			iFrameID = oArrowManager.GetOptionByIndex(iSelected).iFrameID;
			pFrame   = FrameLoader::GetInstance().GetFrameByID(iFrameID);
			//ѡ��ѡ���޺����˵�
			if (pFrame == NULL)
			{
				m_lsFrames.pop_back();
				oFrameLoader.ReleaseFrame(pFrame);
				bFlash = true;
				break;
			}
			//ѡ��ѡ���к����˵�
			else
			{
				Req oReq;
				Rsp oRsp;
				//��������;
				pFrame->PrepareReq(iSelected, oReq);
				if (0 < Forword(pFrame->GetHandler(), oReq, oRsp))
					return -1;
				pFrame->PrepareRsp(oRsp);

				//��ջ
				m_lsFrames.push_back(pFrame);
				bFlash = false;
				break;
			}
		} while (false);
	}

	return 0;
}

int FrameHander::Handle(int iCmd, Req &oReq, Rsp &oRsp)
{
	switch (iCmd)
	{
	case cmd::COMMAND_START:
		return HandleStart(oReq);
		break;
	}
	return 0;
}
