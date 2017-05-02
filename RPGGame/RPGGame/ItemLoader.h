#ifndef __ITEMLOADER_H__
#define __ITEMLOADER_H__

#include <map>

using std::map;
using std::pair;


#include "Singleton.h"
#include "Struct.h"
#include "Item.h"


/**
* @brief ��Ʒ������
*/
class ItemLoader :public Singleton<ItemLoader>
{
public:
	ItemLoader();
	~ItemLoader();
public:
	/**
	* @brief ��ʼ��
	*/
	bool Init();
public:
	/**
	* @brief ͨ����Ŵ�����Ʒ
	*/
	Item *GetItemByID(int iID);

	/**
	* @brief �ͷ���Ʒ
	*/
	void ReleaseItem(Item *pItem);
private:
	/**
	* @brief ͨ�����ʹ�����Ʒ
	*/
	Item *CreateItemInstanceByType(const int iType);
private:
	/*!< �������Ʒ����ӳ�� */
	map<int, Item> m_mapItemDatas;
};


#endif