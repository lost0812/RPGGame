#ifndef __MAPHANDLER_H__
#define __MAPHANDLER_H__

#include "Singleton.h"

#include "Cmd.h"
#include "Req.h"
#include "Rsp.h"
#include "Notify.h"


/**
 * @brief Ұ��
 */
class MapHandler:public Singleton<MapHandler>
{
public:
    MapHandler();
    ~MapHandler();

public:
    /**
     * @brief չʾ��ͼ�б�
     */
    int HandlerShowMap(const cmd::Command eCmd, const  req::Req &oReq, rsp::Rsp &oRsp);
    /**
     * @brief չʾ��ͼ����
     */
    int HandlerShowMapAction(const cmd::Command eCmd, const  req::Req &oReq, rsp::Rsp &oRsp);
    /**
    * @brief �ҹ�
    */
    int HandlerMeetMonster(const cmd::Command eCmd, const  req::Req &oReq, rsp::Rsp &oRsp);
};



#endif // __MAPHANDLER_H__

