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
    virtual void PrepareReq(Req &oReq);

    /**
    * @brief ������Ӧ����
    */
    virtual void PrepareRsp(const Rsp &oRsp);
};


#endif // __SHOWFRAME_H__

