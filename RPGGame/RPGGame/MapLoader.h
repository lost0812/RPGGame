#ifndef __MAPLOADER_H__
#define __MAPLOADER_H__

#include <map>

#include "Singleton.h"

#include "Loader.h"
#include "Map.h"

using std::map;
using std::make_pair;

/**
 * @brief ��ͼ���ü���
 */
class MapLoader :public Singleton<MapLoader>,public Loader
{
public:
    MapLoader();
    ~MapLoader();
public:
    /**
     * @brief ���������ļ�
     */
    virtual bool Load() override;

public:
    /**
     * @brief ��ȡ����
     */
    const Map &GetMapByID(const int iID)const;

private:
    /*!< ������ͼӳ�� */
    map<int, Map> m_mapMaps;
};


#endif // __MAPLOADER_H__


