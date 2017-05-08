#ifndef __MAP_H__
#define __MAP_H__

#include "Struct.h"

/**
 * @brief ��ͼ
 */
class Map
{
public:
    /**
     * @brief ��ͼ����
     */
    enum MapType
    {
        /*!< �޵�ͼ */
        MAP_TYPE_NO_MAP = 0,

        /*!< ��Դ��ͼ */
        MAP_TYPE_RESOURCE = 1,

        /*!< �����ͼ */
        MAP_TYPE_MONSTER = 2,
    };
public:
    Map();
    virtual ~Map();
public:
    /**
    * @brief �޵�ͼ
    */
    static const Map &GetNoMap();
public:
    /**
    * @brief ��ʼ��
    */
    virtual bool Init(const Map &oMap);

    /**
    * @brief ��ʼ��
    */
    virtual bool Init(
        const int iID, 
        const Map::MapType eType, 
        const int iMaxTime,
        const int iRecovery,
        const vector<int> &vMonsterID,
        const vector<int> &vDropID);


public:
    SET_GET(int,          i, ID,        m_stMapData.iID)
    SET_GET(Map::MapType, e, Type,      m_stMapData.eType)
    SET_GET(int,          i, MaxTime,   m_stMapData.iMaxTime)
    SET_GET(int,          i, Recovery,  m_stMapData.iRecovery)
    SET_GET(vector<int>&, v, MonsterID, m_stMapData.vMonsterID)
    SET_GET(vector<int>&, v, DropID,    m_stMapData.vDropID)

private:
    /**
     * @brief ��ͼ���ݽṹ��
     */
    struct MapData
    {
        /*!< ��� */
        int iID;

        /*!< ���� */
        Map::MapType eType;

        /*!< ������ */
        int iMaxTime;

        /*!< �ָ��ٶ� */
        int iRecovery;

        /*!< ������ */
        vector<int> vMonsterID;

        /*!< ������ */
        vector<int> vDropID;
    };
private:
    /*!< ��ͼ���� */
    MapData m_stMapData;
};


#endif // __MAP_H__
