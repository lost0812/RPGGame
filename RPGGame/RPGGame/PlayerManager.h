#ifndef __PLAYERMANAGER_H__
#define __PLAYERMANAGER_H__

#include "Actor.h"
#include "Singleton.h"


/**
* @brief ��ҹ���
*/
class PlayerManager:public Singleton<PlayerManager>
{
public:
	PlayerManager();
	~PlayerManager();
public:
	/**
	* @brief ��ʼ��
	*/
	virtual bool Init();
public:
	/**
	* @brief ��ȡ����
	*/
	const Bag &GetBag();

private:
	/*!< ��� */
	Actor m_oActor;
};

#endif // __PLAYERMANAGER_H__
