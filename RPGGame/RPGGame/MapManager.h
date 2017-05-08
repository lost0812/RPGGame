#ifndef __MAPMANAGER_H__
#define __MAPMANAGER_H__

#include "Manager.h"

/**
 * @brief ��ͼ����
 */
class MapManager :public Manager
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
     * @brief ���Ұ��
     */
    int CreateRandMonster(int iMapID);
private:

};




#endif // __MAPMANAGER_H__
