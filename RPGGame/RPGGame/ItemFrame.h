#ifndef __ITEMFRAME_H__
#define __ITEMFRAME_H__


#include "Frame.h"

/**
 * @brief ��Ʒ����
 */
class ItemFrame :public Frame
{
public:
	ItemFrame();
	~ItemFrame();
public:
	/**
	* @brief ������������
	*/
	virtual void PrepareReq(req::Req &oReq);

	/**
	* @brief ������Ӧ����
	*/
	virtual void PrepareRsp(const rsp::Rsp &oRsp);
};


#endif // __ITEMFRAME_H__
