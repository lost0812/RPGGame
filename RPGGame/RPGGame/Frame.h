#pragma once


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
	* @brief ��ȡ��һ��ѡ��λ��
	*/
	const Position GetOptionPosition();

	/**
	* @brief չʾ��
	*/
	void Show()const;

	/**
	* @brief ������������
	*/
	virtual void PrepareReq(const int iSelected, Req &oReq);

	/**
	 * @brief ������Ӧ����
	 */
	virtual void PrepareRsp(const Rsp &oRsp);

    /**
     * @brief ���ر���Ӧ��
     */
    bool CheckRsp(const Rsp &oRsp);
public:
	SET_GET(int,             i, ID,          m_oFrameData.iID);
	SET_GET(int,             i, Type,        m_oFrameData.iType);
	SET_GET(Position&,       o, Position,    m_oFrameData.oPosition);
	SET_GET(Size&,           o, Size,        m_oFrameData.oSize);
	SET_GET(string,          s, Description, m_oFrameData.sDescription);
	SET_GET(Direction,       e, Direction,   m_oFrameData.eDirection);
	SET_GET(int,             i, Handler,     m_oFrameData.iHandlerID);
	SET_GET(vector<Option>&, v, Options,     m_oFrameData.vOptions);
private:
	FrameData m_oFrameData;
};

