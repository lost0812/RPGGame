
#ifndef __STRUCT__H__
#define __STRUCT__H__



#include <vector>
#include <string>

using std::vector;
using std::string;


/*!< ����߿� */
#define FrameCorner     "+"

/*!< ����߿� */
#define FrameHorizontal "-"

/*!< ����߿� */
#define FrameVertical   "|"



/*!< ��ͷͼ�� */
#define OptionArrow      "->"

/*!< �����ͷ */
#define OptionClearArrow "  "

/*!< ��ͷ��϶ */
#define OptionArrowGap 3


namespace data
{
	/**
	 * @brief ����ö��
	 */
	enum Direction
	{
		/*!< ���� */
		DIRECTION_HORIZONTAL = 0,

		/*!< ���� */
		DIRECTION_VERTICAL = 1,

		/*!< ��� */
		DIRECTION_LEFT = 2,

		/*!< �ұ� */
		DIRECTION_RIGHT = 3,

		/*!< �ϱ� */
		DIRECTION_UP = 4,

		/*!< �±� */
		DIRECTION_DOWN = 5,

		/*!< ���� */
		DIRECTION_TOP = 6,

		/*!< �׶� */
		DIRECTION_BOTTOM = 7
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

	/**
	 * @brief ѡ������
	 */
	struct OptionData
	{
		/*!< �������� */
		string sDescription;

		/*!< λ�� */
		//Position oPosition;

		/*!< ѡ�к��Ӧ��ı�� */
		unsigned int ulFrameID;
	};

	/**
	 * @brief ������
	 */
	struct FrameData
	{
		/*!< ��� */
		unsigned int iID;

		/*!< λ�� */
		Position oPosition;

		/*!< ��С */
		Size oSize;

		/*!< �������� */
		string sDiscription;

		/*!< ѡ��� */
		Direction eDirection;

		/*!< ѡ����� */
		//int iGap;

		/*!< ѡ������ */
		vector<OptionData> vOptions;
	};
};

#endif
