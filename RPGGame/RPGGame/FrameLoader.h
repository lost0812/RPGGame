#ifndef __FRAMELOADER_H__
#define __FRAMELOADER_H__

#include <map>

using std::map;
using std::pair;

#include "dataconfig_frame.pb.h"

#include "Platform.h"
#include "Singleton.h"
#include "Struct.h"
#include "Frame.h"
#include "BagFrame.h"
#include "ItemFrame.h"


#define FRAMEFIEL "proto/data/dataconfig_frame.data"

using dataconfig::FRAME;
using dataconfig::FRAMEArray;

using data::FrameType;
using data::Direction;
using platform::UTF_82ASCII;

/**
* @brief �������
*/
class FrameLoader : public Singleton<FrameLoader>
{
public:
	/**
	* @brief ��ʼ��
	*/
	bool Init();
public:
	/**
	* @brief ��������ȡ��
	*/
	Frame *GetFrameByID(int iID);

	/**
	* @brief �ͷſ�
	*/
	void ReleaseFrame(Frame *pFrame);
private:
	/**
	* @brief ������
	*/
	Frame *CreateFrameInstanceByType(const int iType);
private:
	/*!< ������ӳ�� */
	map<int, FrameData> m_mapFrameDatas;
};




#endif // __FRAMELOADER_H__
