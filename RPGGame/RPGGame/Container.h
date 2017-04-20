#ifndef __BAG_H__
#define __BAG_H__

#include "Item.h"

/**
 * @brief ������
 */
class Container
{
public:
    typedef vector<data::ContainerUnitData>                         VecContainerUnit;
    typedef vector<data::ContainerUnitData>::iterator               VecContainerUnitIt;
    typedef vector<data::ContainerUnitData>::const_iterator         VecContainerUnitCIt;
    typedef vector<data::ContainerUnitData>::reverse_iterator       VecContainerUnitRevIt;
    typedef vector<data::ContainerUnitData>::const_reverse_iterator VecContainerUnitCRevIt;
public:
    Container();
    Container(const int iID, const int iCapacity);
	virtual ~Container();
public:
    /**
     * @brief ��ʼ��
     */
    bool Init(const int iID, const int iCapacity);

    /**
     * @brief ��Ԫ��������
     */
    int GetUnitMaxCapacity() const;

	/**
	 * @brief ��ȡ��ʹ�ø���
	 */
	int GetUsedCapacity()const;

	/**
	 * @brief �����Ʒ
	 */
    bool Add(const int iItemID, const int iNumber);

    /**
    * @brief �����Ʒ�����������������
    */
    void AddForce(const int iItemID, const int iNumber);

    /**
     * @brief �Ƿ��������Ʒ
     */
    bool CanAdd(const int iItemID, const int iNumber)const;

    /**
    * @brief �Ƴ���Ʒ
    */
    bool Remove(const int iItemID, const int iNumber);

    /**
    * @brief �Ƴ���Ʒ�������Ʒ����������
    */
    void RemoveForce(const int iItemID, const int iNumber);

    /**
    * @brief �Ƴ���Ʒ
    */
    bool CanRemove(const int iItemID, const int iNumber);

	/**
	 * @brief ��ȡ��Ʒ���
	 */
	int GetItemID(const int iIndex)const;

	/**
	 * @brief ��ȡ��Ʒ����
	 */
    int GetItemNum(const int iItemID)const;

    
public:
    SET_GET(int, i, Capacity, m_stContainerData.iCapacity)
private:
    const static int g_iUnitMaxCapacity;
	/*!< ��Ʒ */
	VecContainerUnit m_vContainerUnits;

    data::ContainerData m_stContainerData;
};


#endif // __BAG_H__

