#ifndef __ITEMFRAME_H__
#define __ITEMFRAME_H__


#include "FrameWithOption.h"

/**
 * @brief 物品框类
 */
class ItemFrame :public FrameWithOption
{
public:
	ItemFrame();
	~ItemFrame();
public:
	/**
	* @brief 生成请求数据
	*/
	virtual void PrepareReq(const int iIndex, req::Req &oReq);

	/**
	* @brief 处理响应数据
	*/
	virtual void PrepareRsp(const rsp::Rsp &oRsp);
};


#endif // __ITEMFRAME_H__
