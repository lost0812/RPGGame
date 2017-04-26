#ifndef __NOTIFY_H__
#define __NOTIFY_H__

#include <map>
#include <string>
#include <vector>

#include "Cmd.h"

using std::map;
using std::vector;
using std::string;
using std::pair;

/**
* @brief ֪ͨ�����ռ�
*/
namespace notify
{

    const static string i_Index = "i_Index";
    /**
     * @brief ֪ͨ��
     */
    class Notify
    {
    public:
        Notify();
        ~Notify();
    public:
        /**
        * @brief ��ʼ��
        */
        virtual bool Init(cmd::Command eCmd);

        /**
        * @brief ��ȡָ��
        */
        cmd::Command GetCmd();

        /**
        * @brief ������Ͳ���
        */
        void Add(string sKey, int iValue);

        /**
        * @brief ����ַ�������
        */
        void Add(string sKey, string sValue);

        /**
        * @brief ����������
        */
        void Add(string sKey, vector<Notify> vValue);

        /**
        * @brief ��ȡָ�����Ͳ���
        */
        const int GetInt(string sKey)const;

        /**
        * @brief ��ȡָ���ַ�������
        */
        const string GetString(string sKey)const;

        /**
        * @brief ��ȡָ���������
        */
        const vector<Notify> GetVector(string sKey)const;

        /**
        * @brief �Ƿ���ָ�����Ͳ���
        */
        const bool HasInt(string sKey)const;

        /**
        * @brief �Ƿ���ָ���ַ�������
        */
        const bool HasString(string sKey)const;

        /**
        * @brief �Ƿ���ָ���������
        */
        const bool HasVector(string sKey)const;
    private:
        /*!< ָ�� */
        cmd::Command m_eCmd;
        /*!< ���Ͳ���ӳ�� */
        map<string, int> m_mapIntArg;
        /*!< �ַ�������ӳ�� */
        map<string, string> m_mapStringArg;
        /*!< �������ӳ�� */
        map<string, vector<Notify>> m_mapVectorArg;

    };
};

#endif // __NOTIFY_H__
