
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
	//-ö�ٽṹ----------------------------------------------------//
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
	 * @brief װ������
	 */
	enum EquipmentType
	{
		/*!< ���� */
		EQUIPMENT_TYPE_WEAPON = 0,
		/*!< ���� */
		EQUIPMENT_TYPE_AEMOR = 1,
		/*!< ��Ʒ */
		EQUIPMENT_TYPE_ACCESSORY = 2,
		/*!< �������ֵ */
		EQUIPMENT_TYPE_MAX = 3,
	};




	//-�򵥽ṹ----------------------------------------------------//
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
	 * @brief ѡ��
	 */
	struct Option
	{
		/*!< �������� */
		string sDescription;

		/*!< λ�� */
		//Position oPosition;

		/*!< ѡ�к��Ӧ��ı�� */
		int iFrameID;
	};

	


	//-���ݽṹ----------------------------------------------------//
	/**
	 * @brief ������
	 */
	struct FrameData
	{
		/*!< ��� */
		int iID;

		/*!< λ�� */
		Position oPosition;

		/*!< ��С */
		Size oSize;

		/*!< �������� */
		string sDescription;

		/*!< ѡ��� */
		Direction eDirection;

		/*!< ������ */
		int iHandlerID;

		/*!< ѡ������ */
		vector<Option> vOptions;
	};

	/**
	* @brief ��Ʒ����
	*/
	struct ItemData
	{
		/*!< ��� */
		int iID;

		/*!< ���� */
		string sDescription;
	};

	/**
	 * @brief �ж�������
	 */
	struct ActorData
	{
		/*!< ��� */
		int iID;
		/*!< ���� */
		string sName;
		/*!< ���� */
		int iHp;
		/*!< �������� */
		int iMaxHp;
		/*!< ������ */
		int iAttack;
		/*!< ������ */
		int iDefance;
	};


	/**
	 * @brief װ������
	 */
	class EquipmentData
	{
		/*!< ��� */
		int iID;
		/*!< ���� */
		EquipmentType eType;
		/*!< ������������ */
		int iMaxHp;
		/*!< ���ӹ����� */
		int iAttack;
		/*!< ���ӷ����� */
		int iDefance;
	};
};


#define SET_GET(type,abbr_type,name,field)\
inline const type Get##name( )const\
{\
	return field;\
}\
inline void Set##name( const type abbr_type##name )\
{\
	field = abbr_type##name;\
}



#endif
