#ifndef __BAGFRAME_H__
#define __BAGFRAME_H__


#include "Frame.h"

/**
* @brief ��������
*/
class BagFrame :public Frame
{
public:
	BagFrame();
	~BagFrame();
private:
	/**
	* @brief ������������
	*/
	virtual void PrepareReq(req::Req &oReq);

	/**
	* @brief ������Ӧ����
	*/
	virtual void PrepareRsp(const rsp::Rsp &oRsp);
};


#endif // __BAGFRAME_H__
