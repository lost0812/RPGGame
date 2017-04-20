#ifndef __ACTOR__H__
#define __ACTOR__H__

#include "Struct.h"

#include "Item.h"
#include "Container.h"
#include "Equipment.h"


using data::ActorData;

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

/**
 * @brief �ж���
 */
class Actor
{
public:
	Actor();
	~Actor();
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
	bool AddItemToBag(const Item &oItem);

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
	SET_GET(int,    i, BaseID,      m_oActorData.iID);
	SET_GET(string, s, BaseName,    m_oActorData.sName);
	SET_GET(int,    i, BaseHp,      m_oActorData.iHp);
	SET_GET(int,    i, BaseMaxHp,   m_oActorData.iMaxHp);
	SET_GET(int,    i, BaseAttack,  m_oActorData.iAttack);
	SET_GET(int,    i, BaseDefance, m_oActorData.iDefance);
protected:
	/*!< �ж������� */
	ActorData m_oActorData;
	/*!< װ��״̬���� */
	EquipmentState m_ayEquipments[EquipmentType::EQUIPMENT_TYPE_MAX];
	/*!< ���� */
	Container m_oBag;
};



#endif