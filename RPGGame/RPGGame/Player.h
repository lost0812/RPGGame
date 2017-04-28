#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Struct.h"
#include "Container.h"
#include "Equipment.h"
#include "Goods.h"

/**
* @brief �����
*/
class Player
{
    /**
     * @brief װ������
     */
    enum EquipmentOperator
    {
        /*!< װ�� */
        EQUIPMENT_OPERATOR_PUTON,
        /*!< ж�� */
        EQUIPMENT_OPERATOR_GETOFF,
        /*!< �滻 */
        EQUIPMENT_OPERATOR_CHANGE
    };

    /**
     * @brief �ж�װ��λ��״̬
     */
    struct EquipmentState
    {
        /*!< �Ƿ���װ����true��װ����false ��װ�� */
        bool bIsEquip;
        /*!< װ����Ϣ */
        Equipment oEquipment;
    };
public:
	Player();
	~Player();
public://-����----------------------------------------------------//
       /**
       * @brief ��ʼ������
       */
    bool Init(int iID, int iHp, int iMaxHp, int iAttack, int iDefance);

    /**
    * @brief ��������ֵ
    */
    void Reset();

    /**
    * @brief װ��װ������ж��װ��
    */
    EquipmentOperator Equip(
        const EquipmentOperator eEquipmentOperator,
        const Equipment &oNewEquipment,
        Equipment &oOldEuipment);

    /**
    * @brief �����˺�
    */
    void Defance(int iDamage);

    /**
    * @brief �չ��˺�
    */
    int Attack();

    /**
     * @brief �ж��Ƿ�����
     */
    bool IsDie();

    /**
     * @brief ��ӵ�����
     */
    bool AddItemToBag(const int iItemID, const int iNumber);

    /**
     * @brief ��ӵ�������������Ķ���
     */
    void AddItemToBagFocus(const int iItemID, const int iNumber);

    /**
     * @brief �Ƿ������ӵ�����
     */
    bool CanAddItemToBag(const int iItemID, const int iNumber);

    /**
     * @brief ��Ǯ
     */
    bool Pay(const int iMoney);

    /**
     * @brief ����
     */
    bool Buy(const Goods &oGoods);
public://-�������Ի�ȡ----------------------------------------------------//
    /**
     * @brief ��ȡ������
     */
    int GetHp()const;

    /**
    * @brief ��ȡ����������
    */
    int GetMaxHp()const;

    /**
    * @brief ��ȡ�ܹ�����
    */
    int GetAttack()const;

    /**
    * @brief ��ȡ�ܷ�����
    */
    int GetDefance()const;

    /**
    * @brief ��ȡ�ӳɵ���������
    */
    int GetExtendMaxHp()const;

    /**
     * @brief ��ȡ�ӳɵĹ�����
     */
    int GetExtendAttack()const;

    /**
     * @brief ��ȡ�ӳɵķ�����
     */
    int GetExtendDefance()const;


public://-ģ�����ݻ�ȡ----------------------------------------------------//
    /**
     * @brief ��ȡ����
     */
    const Container& GetBag()const;

public:
    SET_GET(int,    i, ID,          m_stPlayerData.stActorData.iID);
    SET_GET(string, s, Name,        m_stPlayerData.stActorData.sName);
    SET_GET(int,    i, BaseHp,      m_stPlayerData.stActorData.iHp);
    SET_GET(int,    i, BaseMaxHp,   m_stPlayerData.stActorData.iMaxHp);
    SET_GET(int,    i, BaseAttack,  m_stPlayerData.stActorData.iAttack);
    SET_GET(int,    i, BaseDefance, m_stPlayerData.stActorData.iDefance);
    SET_GET(int,    i, Money,       m_stPlayerData.stActorExternData.iMoney);
    SET_GET(int,    i, Level,       m_stPlayerData.stActorExternData.iLevel);
    SET_GET(int,    i, Exp,         m_stPlayerData.stActorExternData.iExp);
    SET_GET(int,    i, TotalExp,    m_stPlayerData.stActorExternData.iTotalExp);
protected:
    /*!< ������� */
    data::PlayerData m_stPlayerData;

    /*!< װ��״̬���� */
    EquipmentState m_ayEquipments[EquipmentType::EQUIPMENT_TYPE_MAX];

    /*!< ���� */
    Container m_oBag;
};


#endif // __PLAYER_H__
