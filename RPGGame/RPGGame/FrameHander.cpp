#include "FrameHander.h"
#include "ArrowManager.h"
#include "Cmd.h"
#include "FrameLoader.h"


#include "PropertyFrame.h"

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

int FrameHander::HandleIdle(req::Req &oReq)
{
	return 1;
}

int FrameHander::HandleStart(req::Req &oReq)
{
	FrameLoader &oFrameLoader = FrameLoader::GetInstance();
	FrameWithOption *pFrame = oFrameLoader.GetFrameByID(0);
	m_lsFrames.push_back(pFrame);


	int iFrameID;
	bool bFlash = true;
	int iSelected;

	bool bIsRuning = true;

    PropertyFrame &oPropertyFrame = PropertyFrame::GetInstance();
    data::FrameData stFrameData;
    oPropertyFrame.Init(stFrameData);
    oPropertyFrame.Show();

	while (bIsRuning)
	{
		pFrame = m_lsFrames.back();
		//ˢ����ͼ
		//if (bFlash)
		if(true)
		{
//			clear();
//			list<Frame*>::const_iterator cpIt;
//			for (cpIt = m_lsFrames.begin();cpIt != m_lsFrames.end();++cpIt)
//				(*cpIt)->Show();
		}
		pFrame->Show();

		ArrowManager &oArrowManager = ArrowManager::GetInstance();
        data::Position stArrawPosition;
        pFrame->GetArrawDefaultPosition(stArrawPosition);
		oArrowManager.Init(
			pFrame->GetDirection( ), 
            stArrawPosition,
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
                pFrame = NULL;
				bFlash = true;
				break;
			}
			//ѡ��ѡ���к����˵�
			else
			{
				req::Req oReq;
				rsp::Rsp oRsp;
				//��������;
				pFrame->PrepareReq(iSelected, oReq);
                Forword(oReq.GetCmd(), oReq, oRsp);
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

int FrameHander::Handle(cmd::Command eCmd, req::Req &oReq, rsp::Rsp &oRsp)
{
	switch (eCmd)
	{
	case cmd::COMMAND_START:
		return HandleStart(oReq);
		break;
	}
	return 0;
}

void FrameHander::Handle(const cmd::Notify eNotify, const rsp::Rsp &stRsp)
{
    switch (eNotify)
    {
    case cmd::NOTIFY_UPDATE_PROPERTY:
    {
        PropertyFrame &oPropertyFrame = PropertyFrame::GetInstance();
        if (stRsp.HasInt(rsp::i_PropertyFrame_Hp))
            oPropertyFrame.SetHp(stRsp.GetInt(rsp::i_PropertyFrame_Hp));
        if (stRsp.HasInt(rsp::i_PropertyFrame_MaxHp))
            oPropertyFrame.SetMaxHp(stRsp.GetInt(rsp::i_PropertyFrame_MaxHp));
        if (stRsp.HasInt(rsp::i_PropertyFrame_Money))
            oPropertyFrame.SetMoney(stRsp.GetInt(rsp::i_PropertyFrame_Money));
        if (stRsp.HasInt(rsp::i_PropertyFrame_Level))
            oPropertyFrame.SetLevel(stRsp.GetInt(rsp::i_PropertyFrame_Level));
        if (stRsp.HasInt(rsp::i_PropertyFrame_Exp))
            oPropertyFrame.SetExp(stRsp.GetInt(rsp::i_PropertyFrame_Exp));
        if (stRsp.HasInt(rsp::i_PropertyFrame_TotalExp))
            oPropertyFrame.SetTotalExp(stRsp.GetInt(rsp::i_PropertyFrame_TotalExp));
        if (stRsp.HasInt(rsp::i_PropertyFrame_Bag))
            oPropertyFrame.SetBag(stRsp.GetInt(rsp::i_PropertyFrame_Bag));
        if (stRsp.HasInt(rsp::i_PropertyFrame_Bag))
            oPropertyFrame.SetTotalBag(stRsp.GetInt(rsp::i_PropertyFrame_TotalBag));
        break;
    }
    case cmd::NOTIFY_UPDATE_INFORMATION:
        break;
    }

}
