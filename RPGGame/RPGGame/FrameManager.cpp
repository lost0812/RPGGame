#include "FrameManager.h"

#include <iostream>

using namespace std;

FrameManager::FrameManager()
{

}

FrameManager::~FrameManager()
{

}

bool FrameManager::Init(App* pApp, Config *pConfig)
{
	bool bRet = Manager::Init(pApp, pConfig);
	if (!bRet)
		return false;


	RegisterCmd(cmd::COMMAND_IDLE);
	RegisterCmd(cmd::COMMAND_START);

	return true;
}

int FrameManager::Start()
{
	int iRet = Manager::Start();
	if (iRet != 0)
		return iRet;
	//todo
	return 0;
}

int FrameManager::Stop()
{
	int iRet = Manager::Stop();
	if (iRet != 0)
		return iRet;
	//todo
	return 0;
}

void FrameManager::Finish()
{

}

int FrameManager::HandleIdle(Req &oReq)
{
	return 1;
}

int FrameManager::HandleStart(Req &oReq)
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

		OptionsArrow &oOptionsArrow = OptionsArrow::GetInstance();
		oOptionsArrow.Init( 
			pFrame->GetDirection(), 
			pFrame->GetOptionPosition(), 
			pFrame->GetOptions() );
		iSelected = oOptionsArrow.GetSelectIndex();
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
			iFrameID = oOptionsArrow.GetOptionByIndex(iSelected).iFrameID;
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
				pFrame->PrepareData(iSelected);
				m_lsFrames.push_back(pFrame);
				bFlash = false;
				break;
			}
		} while (false);
	}

	return 0;
}

int FrameManager::Handle(int iCmd, Req &oReq, Rsp &oRsp)
{
	switch (iCmd)
	{
	case cmd::COMMAND_START:
		return HandleStart(oReq);
		break;
	}
	return 0;
}
