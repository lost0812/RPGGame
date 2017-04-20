#include "Container.h"

const int Container::g_iUnitMaxCapacity = 20;

Container::Container()
{
    m_stContainerData.iID = 0;
    m_stContainerData.iCapacity = 0;
}

Container::Container(const int iID, const int iCapacity)
{
    m_stContainerData.iID       = iID;
    m_stContainerData.iCapacity = iCapacity;

    data::ContainerUnitData stUnit;
    for (int i = 0; i < m_stContainerData.iCapacity; ++i)
    {
        stUnit.iID              = i;
        stUnit.iItemID          = 0;
        stUnit.iItemNum         = 0;
        stUnit.iItemMaxCapacity = g_iUnitMaxCapacity;

        m_vContainerUnits.push_back(stUnit);
    }
}

Container::~Container()
{
}

bool Container::Init(const int iID, const int iCapacity)
{
    m_stContainerData.iID = iID;
    m_stContainerData.iCapacity = iCapacity;

    m_vContainerUnits.clear();
    data::ContainerUnitData stUnit;
    for (int i = 0; i < m_stContainerData.iCapacity; ++i)
    {
        stUnit.iID = i;
        stUnit.iItemID = 0;
        stUnit.iItemNum = 0;
        stUnit.iItemMaxCapacity = g_iUnitMaxCapacity;

        m_vContainerUnits.push_back(stUnit);
    }

    return true;
}

int Container::GetUnitMaxCapacity() const
{
    return g_iUnitMaxCapacity;
}

int Container::GetUsedCapacity() const
{
    int iCount = 0;
    for (VecContainerUnitCIt it = m_vContainerUnits.begin(); it != m_vContainerUnits.end(); ++it)
    {
        if (it->iItemID != 0 && it->iItemNum > 0)
            ++iCount;
    }
    return iCount;

}

bool Container::Add(const int iItemID, const int iNumber)
{
    if (!CanAdd(iItemID, iNumber))
        return false;
    
    AddForce(iItemID, iNumber);
    return true;
}

void Container::AddForce(const int iItemID, const int iNumber)
{
    int iLeft = iNumber;
    VecContainerUnitIt it;

    //�ȷſɵ��ӵĸ�����
    it = m_vContainerUnits.begin();
    for (;it != m_vContainerUnits.end(); ++it)
    {
        if (it->iItemID == iItemID)//�ɵ��Ӹ���
        {
            if (it->iItemMaxCapacity >= it->iItemNum + iLeft)
            {
                //���ڵ��Ӹ���
                it->iItemNum += iLeft;
                return;
            }
            else
            {
                //���Ӹ��Ӳ�����
                iLeft -= it->iItemMaxCapacity - it->iItemNum;
                it->iItemNum = it->iItemMaxCapacity;
            }
        }
    }
    //�ſո�����
    it = m_vContainerUnits.begin();
    for (;it != m_vContainerUnits.end(); ++it)
    {
        if (it->iItemNum <= 0)
        {
            it->iItemID = iItemID;
            if (iLeft < it->iItemMaxCapacity)
            {
                //�ո��ӹ���
                it->iItemNum = iLeft;
                return;
            }
            else
            {
                //�ո��Ӳ�����
                iLeft -= it->iItemMaxCapacity;
                it->iItemNum = it->iItemMaxCapacity;
            }
        }
    }
}

bool Container::CanAdd(int iItemID, int iNumber) const
{
    int iLeft = iNumber;

    if (iItemID == 0 || iNumber == 0)
        return true;

    VecContainerUnitCRevIt it = m_vContainerUnits.rbegin();
    for (;it != m_vContainerUnits.rend(); ++it)
    {
        if (it->iItemID == iItemID)//�ɵ��Ӹ���
            iLeft -= (it->iItemMaxCapacity - it->iItemNum);
        else if( it->iItemNum == 0 )//�ո���
            iLeft -= it->iItemMaxCapacity;

        if (iLeft <= 0)
            return true;
    }
    return false;
}


bool Container::Remove(const int iItemID, const int iNumber)
{
    if (!CanRemove(iItemID, iNumber))
        return false;
    RemoveForce(iItemID, iNumber);
    return true;
}

void Container::RemoveForce(const int iItemID, const int iNumber)
{
    int iLeft = iNumber;
    VecContainerUnitIt it;

    //�ȿ۳�δ���ĸ���
    it = m_vContainerUnits.begin();
    for (; it != m_vContainerUnits.end(); ++it)
    {
        if (it->iItemID == iItemID && it->iItemNum != it->iItemMaxCapacity)
        {
            if (it->iItemNum > iLeft)
            {
                it->iItemNum -= iLeft;
                return;
            }
            else
            {
                iLeft -= it->iItemNum;
                it->iItemNum = 0;
                it->iItemID  = 0;
            }
        }
    }

    //�۳����ĸ���
    it = m_vContainerUnits.begin();
    for (; it != m_vContainerUnits.end(); ++it)
    {
        if (it->iItemID == iItemID && it->iItemNum == it->iItemMaxCapacity)
        {
            if (it->iItemNum > iLeft)
            {
                it->iItemNum -= iLeft;
                return;
            }
            else
            {
                iLeft -= it->iItemNum;
                it->iItemNum = 0;
                it->iItemID = 0;
            }
        }
    }
}

bool Container::CanRemove(const int iItemID, const int iNumber)
{
    int iCount = GetItemNum(iItemID);

    if (iCount >= iNumber)
        return true;
    return false;
}

int Container::GetItemID(const int iIndex)const
{
    if (iIndex >= 0 && iIndex < m_stContainerData.iCapacity)
        return m_vContainerUnits[iIndex].iItemID;
	return 0;
}

int Container::GetItemNum(const int iItemID)const
{
    int iCount = 0;

    VecContainerUnitCIt it = m_vContainerUnits.begin();
    for (; it != m_vContainerUnits.end(); ++it)
    {
        if (it->iItemID == iItemID)
            iCount += it->iItemNum;
    }

    return iCount;
}
