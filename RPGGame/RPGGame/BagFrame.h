#ifndef __BAGFRAME_H__
#define __BAGFRAME_H__


#include "Frame.h"
class BagFrame :public Frame
{
public:
	BagFrame();
	~BagFrame();
private:
	/**
	* @brief ������������
	*/
	virtual void PrepareReq(Req &oReq);

	/**
	* @brief ������Ӧ����
	*/
	virtual void PrepareRsp(const Rsp &oRsp);
};


#endif // __BAGFRAME_H__
