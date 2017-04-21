#ifndef __FRAME_H__
#define __FRAME_H__


#include <string>
#include <vector>
#include "Struct.h"
#include "UIBase.h"

#include "Req.h"
#include "Rsp.h"


using std::string;
using std::vector;

using data::Size;
using data::Position;
using data::Direction;
using data::Option;
using data::FrameData;
using data::Option;


/**
* @brief ����
*/
class Frame
{
public:
	Frame(void);
	~Frame(void);
public:
	/**
	* @brief ��ʼ��
	*/
	virtual bool Init( const FrameData &oFrameData );

	/**
	* @brief ������������
	*/
	virtual void PrepareReq(const int iIndex, req::Req &oReq);

	/**
	 * @brief ������Ӧ����
	 */
	virtual void PrepareRsp(const rsp::Rsp &oRsp);

public:
	/**
	* @brief ��ȡ��һ��ѡ��λ��
	*/
	const Position GetOptionPosition();

	/**
	* @brief չʾ��
	*/
	void Show()const;

    /**
     * @brief ���ر���Ӧ��
     */
    bool CheckRsp(const rsp::Rsp &oRsp);
public:
	SET_GET(int,                   i, ID,          m_oFrameData.iID);
	SET_GET(data::FrameType,       e, Type,        m_oFrameData.eType);
	SET_GET(data::Position&,       o, Position,    m_oFrameData.oPosition);
	SET_GET(data::Size&,           o, Size,        m_oFrameData.oSize);
	SET_GET(string,                s, Description, m_oFrameData.sDescription);
	SET_GET(data::Direction,       e, Direction,   m_oFrameData.eDirection);
	SET_GET(int,                   i, Handler,     m_oFrameData.iHandlerID);
	SET_GET(vector<data::Option>&, v, Options,     m_oFrameData.vOptions);
private:
	FrameData m_oFrameData;
};



#endif // __FRAME_H__
