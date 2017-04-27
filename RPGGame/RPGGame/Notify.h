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

    const string i_Index = "i_Index";



    const string i_PropertyFrame_Hp = "i_PropertyFrame_Hp";
    const string i_PropertyFrame_MaxHp = "i_PropertyFrame_MaxHp";
    const string i_PropertyFrame_Money = "i_PropertyFrame_Money";
    const string i_PropertyFrame_Level = "i_PropertyFrame_Level";
    const string i_PropertyFrame_Exp = "i_PropertyFrame_Exp";
    const string i_PropertyFrame_TotalExp = "i_PropertyFrame_TotalExp";
    const string i_PropertyFrame_Bag = "i_PropertyFrame_Bag";
    const string i_PropertyFrame_TotalBag = "i_PropertyFrame_TotalBag";

    const string s_TipsFrame_Description = "s_TipsFrame_Description";


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
