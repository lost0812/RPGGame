#ifndef __SHOPITEMFRAME_H__
#define __SHOPITEMFRAME_H__

#include "Frame.h"
/**
 * @brief ��Ʒ��
 */
class ShopItemFrame :public Frame
{
public:
    /**
    * @brief ������������
    */
    virtual void PrepareReq(const int iIndex, req::Req &oReq);

    /**
    * @brief ������Ӧ����
    */
    virtual void PrepareRsp(const rsp::Rsp &oRsp);
};

#endif // __SHOPITEMFRAME_H__
#include "Frame.h"

