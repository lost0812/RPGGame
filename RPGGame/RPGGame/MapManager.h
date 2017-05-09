#ifndef __MAPMANAGER_H__
#define __MAPMANAGER_H__

#include "Manager.h"
#include "Singleton.h"
#include "Drop.h"
#include "Monster.h"
#include "MapAction.h"
#include "Map.h"

/**
 * @brief ��ͼ����
 */
class MapManager :public Manager,public Singleton<MapManager>
{
public:
    MapManager();
    ~MapManager();
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
    const Drop &GetDropByID(const int iID);
    
    /**
     * @brief ��ȡ��������
     */
    int GetDropTotalNum()const;

    /**
     * @brief ��ȡ����
     */
    const Monster &GetMonsterByID(const int iID);

    /**
     * @brief ��ȡ��������
     */
    int GetMonsterTotalNum();
    
    /**
     * @brief ��ȡ��ͼ����
     */
    const MapAction &GetMapActionByID(const int iID);
    /**
     * @brief ��ȡ��ͼ����
     */
    int GetMapActionTotalNum();

    /**
     * @brief ��ȡ��ͼ
     */
    const Map &GetMapByID(const int iID);

    /**
     * @brief ��ȡ��ͼ����
     */
    int GetMapTotalNum();

public:
    /**
     * @brief ���Ұ��
     */
    const Monster &MeetMonster(const int iMapActionID);
private:
    /*!< �����Ĺ��� */
    Monster m_oCurrentMonster;
};




#endif // __MAPMANAGER_H__
