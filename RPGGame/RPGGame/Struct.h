
#ifndef __STRUCT__H__
#define __STRUCT__H__



#include <vector>
#include <string>

using std::vector;
using std::string;

#define FrameCorner     "+"
#define FrameHorizontal "-"
#define FrameVertical   "|"

#define OptionArrow      "->"
#define OptionClearArrow "  "

namespace data
{
	/**
	 * @brief ����ö��
	 */
	enum Direction
	{
		/*!< ���� */
		DIRECTION_HORIZONTAL,
		/*!< ���� */
		DIRECTION_VERTICAL,
		/*!< ��� */
		DIRECTION_LEFT,
		/*!< �ұ� */
		DIRECTION_RIGHT,
		/*!< �ϱ� */
		DIRECTION_UP,
		/*!< �±� */
		DIRECTION_DOWN,
		/*!< ���� */
		DIRECTION_TOP,
		/*!< �׶� */
		DIRECTION_BOTTOM
	};


	/**
	 * @brief λ��
	 */
	struct Position
	{
		/*!< ������ */
		int iX;
		/*!< ������ */
		int iY;
	};

	/**
	 * @brief ��С
	 */
	struct Size
	{
		/*!< ��� */
		int iWidth;
		/*!< �߶� */
		int iHeigth;
	};



	struct OptionsPosition
	{
		Direction direction;
		vector< Position > positions;
	};

	struct OptionsData
	{
		unsigned int frame_id;
		string option_discription;
	};

	struct OptionData
	{
		int index;
		string description;
		int frame_id;
	};

	struct FrameData
	{
		unsigned int id;
		Position postion;
		Size size;
		string discription;
		Direction direction;
		int gap;
		vector<OptionsData> options;
	};
};

#endif
