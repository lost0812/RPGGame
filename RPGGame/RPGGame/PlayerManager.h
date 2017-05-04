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

    /**
     * @brief ����
     */
    virtual bool Save(const string sFile);

    /**
     * @brief ����
     */
    virtual bool Load(const string sFile);
public:
	/**
	* @brief ��ȡ����
	*/
	const Bag &GetBag();

     /**
      * @brief ����
      */
    bool Buy(const int iItemID, const int iPrice);

    /**
    * @brief ������
    */
    bool Sell(const int iItemID, const int iPrice);

    /**
     * @brief ��ȡ���
     */
    const Player & GetPlayer();
private:
	/*!< ��� */
	Player m_oPlayer;
};

#endif // __PLAYERMANAGER_H__
