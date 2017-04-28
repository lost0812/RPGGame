#ifndef __ITEMDATA_H__
#define __ITEMDATA_H__

namespace dataD
{
    enum ItemType
    {
        ITEM_TYPE_EQUIPMENT,
        ITEM_TYPE_MAX
    };

    enum EquipmentTYPE
    {
        EQUIPMENT_TYPE_WEAPON,
        EQUIPMENT_TYPE_MAX
    };

    struct ItemData
    {
        /*<! ��� */
        int iID;

        /*<! ���� */
        ItemType eType;

        /*<! ���� */
        string sName;

        /*<! ���� */
        string sDescripition;
    }

    struct EquipmentData
    {
        /*<! ��Ʒ */
        ItemData stItem;

        /*<! ���� */
        int eType;

        /*<! ������������ */
        int iMaxHp;

        /*<! ���ӹ����� */
        int iAttack;

        /*<! ���ӷ����� */
        int iDefance;
    };
}


#endif // __ITEMDATA_H__
