#ifndef __BAG_H__
#define __BAG_H__

#include "Item.h"

/**
 * @brief ������
 */
class Bag
{
public:
	Bag();
	~Bag();
public:
	/**
	 * @brief ��ȡ��Ʒ����
	 */
	int GetItemsNumber()const;

	/**
	 * @brief �����Ʒ
	 */
	bool AddItem(const Item& oItem );

	/**
	 * @brief ��ȡ��Ʒ���
	 */
	unsigned int GetItemID(int iIndex)const;

	/**
	 * @brief ��ȡ��Ʒ����
	 */
	const string GetItemDescription(int iIndex)const;
private:
	/*!< ��Ʒ */
	vector<Item> m_vItems;
};


#endif // __BAG_H__

