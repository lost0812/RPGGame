#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Struct.h"
#include "Container.h"
#include "Equipment.h"

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


public://-�������Ի�ȡ----------------------------------------------------//
       /**
       * @brief ��ȡ������
       */
    int GetHp();

    /**
    * @brief ��ȡ����������
    */
    int GetMaxHp();

    /**
    * @brief ��ȡ�ܹ�����
    */
    int GetAttack();

    /**
    * @brief ��ȡ�ܷ�����
    */
    int GetDefance();

    /**
    * @brief ��ȡ�ӳɵ���������
    */
    int GetExtendMaxHp();

    /**
     * @brief ��ȡ�ӳɵĹ�����
     */
    int GetExtendAttack();

    /**
     * @brief ��ȡ�ӳɵķ�����
     */
    int GetExtendDefance();


public://-ģ�����ݻ�ȡ----------------------------------------------------//
    /**
     * @brief ��ȡ����
     */
    const Container& GetBag()const;

public:
    SET_GET(int, i, BaseID, m_stPlayerData.stActorData.iID);
    SET_GET(string, s, BaseName, m_stPlayerData.stActorData.sName);
    SET_GET(int, i, BaseHp, m_stPlayerData.stActorData.iHp);
    SET_GET(int, i, BaseMaxHp, m_stPlayerData.stActorData.iMaxHp);
    SET_GET(int, i, BaseAttack, m_stPlayerData.stActorData.iAttack);
    SET_GET(int, i, BaseDefance, m_stPlayerData.stActorData.iDefance);
    SET_GET(int, i, Money, m_stPlayerData.stActorExternData.iMoney);
protected:
    /*!< ������� */
    data::PlayerData m_stPlayerData;

    /*!< װ��״̬���� */
    EquipmentState m_ayEquipments[EquipmentType::EQUIPMENT_TYPE_MAX];

    /*!< ���� */
    Container m_oBag;
};


#endif // __PLAYER_H__
