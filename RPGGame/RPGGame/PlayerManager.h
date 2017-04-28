#ifndef __PLAYERMANAGER_H__
#define __PLAYERMANAGER_H__

#include "Singleton.h"
#include "Player.h"
#include "Goods.h"

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
	const Container &GetBag();

     /**
      * @brief ����
      */
    bool Buy( const Goods &oGoods );

    /**
     * @brief ��ȡ���
     */
    const Player & GetPlayer();
private:
	/*!< ��� */
	Player m_oPlayer;
};

#endif // __PLAYERMANAGER_H__
