#ifndef __SHOWFRAME_H__
#define __SHOWFRAME_H__

#include "Frame.h"

/**
 * @brief �̵����
 */
class ShopFrame :public Frame
{
public:
    /**
    * @brief ������������
    */
    virtual void PrepareReq(const int iSelected, req::Req &oReq);

    /**
    * @brief ������Ӧ����
    */
    virtual void PrepareRsp(const rsp::Rsp &oRsp);
};


#endif // __SHOWFRAME_H__

