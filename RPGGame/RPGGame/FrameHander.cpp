#include "FrameHander.h"
#include "ArrowManager.h"
#include "Cmd.h"
#include "FrameLoader.h"


#include "PropertyFrame.h"
#include "TipsFrame.h"



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

    RegisterNotify(cmd::NOTIFY_UPDATE_PROPERTY);
    RegisterNotify(cmd::NOTIFY_UPDATE_INFORMATION);
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
    bool bIsRuning = true;
    //���Կ�
    PropertyFrame &oPropertyFrame = PropertyFrame::GetInstance();
    data::FrameData stFrameData;
    oPropertyFrame.Init(stFrameData);
    oPropertyFrame.Show();

    //��ʾ��
    TipsFrame &oTipsFrame = TipsFrame::GetInstance();
    oTipsFrame.Init();
    oTipsFrame.Show();

    //ѡ���
    FrameLoader &oFrameLoader = FrameLoader::GetInstance();
    FrameWithOption *pFrame = oFrameLoader.GetFrameByID(0);
    m_lsFrames.push_back(pFrame);

	while (bIsRuning)
    {
		pFrame = m_lsFrames.back();
		pFrame->Show();

        int iIndex = pFrame->GetSelectIndex();
		
		if (iIndex < 0 )
		{
		    //ȡ��ѡ��
            if (m_lsFrames.size() <= 1)
                continue;

            m_lsFrames.pop_back();
            oFrameLoader.ReleaseFrame(pFrame);
            continue;
		}
        else
        {
            //ѡ�к�֪ͨ����
            data::Option  stOption;
            pFrame->GetOptionByIndex(iIndex, stOption);
            if (stOption.eNotify != cmd::COMMAND_IDLE)
            {
                notify::Notify oNotify;
                oNotify.Add(notify::i_Index, iIndex);
                Notify(stOption.eNotify, oNotify);
            }

            //ѡ�к����
            if (stOption.iFrameID != -1)
            {
                pFrame = FrameLoader::GetInstance().GetFrameByID(stOption.iFrameID);
                if (pFrame)
                {
                    req::Req oReq;
                    rsp::Rsp oRsp;
                    //��������;
                    pFrame->PrepareReq(iIndex, oReq);
                    Forword(oReq.GetCmd(), oReq, oRsp);
                    pFrame->PrepareRsp(oRsp);
                     
                    //��ջ
                    m_lsFrames.push_back(pFrame);
                }
            }
        }
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

void FrameHander::Handle(const cmd::Notify eNotify, const notify::Notify &oNotify)
{
    switch (eNotify)
    {
    case cmd::NOTIFY_UPDATE_PROPERTY:
    {
        PropertyFrame &oPropertyFrame = PropertyFrame::GetInstance();
        if (oNotify.HasInt(notify::i_PropertyFrame_Hp))
            oPropertyFrame.SetHp(oNotify.GetInt(notify::i_PropertyFrame_Hp));
        if (oNotify.HasInt(notify::i_PropertyFrame_MaxHp))
            oPropertyFrame.SetMaxHp(oNotify.GetInt(notify::i_PropertyFrame_MaxHp));
        if (oNotify.HasInt(notify::i_PropertyFrame_Money))
            oPropertyFrame.SetMoney(oNotify.GetInt(notify::i_PropertyFrame_Money));
        if (oNotify.HasInt(notify::i_PropertyFrame_Level))
            oPropertyFrame.SetLevel(oNotify.GetInt(notify::i_PropertyFrame_Level));
        if (oNotify.HasInt(notify::i_PropertyFrame_Exp))
            oPropertyFrame.SetExp(oNotify.GetInt(notify::i_PropertyFrame_Exp));
        if (oNotify.HasInt(notify::i_PropertyFrame_TotalExp))
            oPropertyFrame.SetTotalExp(oNotify.GetInt(notify::i_PropertyFrame_TotalExp));
        if (oNotify.HasInt(notify::i_PropertyFrame_Bag))
            oPropertyFrame.SetBag(oNotify.GetInt(notify::i_PropertyFrame_Bag));
        if (oNotify.HasInt(notify::i_PropertyFrame_Bag))
            oPropertyFrame.SetTotalBag(oNotify.GetInt(notify::i_PropertyFrame_TotalBag));
        oPropertyFrame.Update();

        break;
    }
    case cmd::NOTIFY_UPDATE_INFORMATION:
        TipsFrame &oTipsFrame = TipsFrame::GetInstance();
        oTipsFrame.SetDescription(oNotify.GetString(notify::s_TipsFrame_Description));
        oTipsFrame.Show();
        break;
    }

}
