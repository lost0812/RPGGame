#ifndef __PARSEXML_H__
#define __PARSEXML_H__

#include <string>
#include <vector>

using std::string;
using std::vector;

#include "tinyxml2.h"

using namespace tinyxml2;

/**
 * @brief ����xml
 */

class ParseXML
{
public:
    /**
     * @brief �ṹ����ö��
     */
    enum Type
    {
        /*!< δ֪���� */
        UNKNOWN,

        /*!< �� */
        CLASS,

        /*!< �ṹ�� */
        STRUCT,

        /*!< ö�� */
        ENUM,
    };
    /**
     * @brief �ṹ���ݽṹ
     */
    struct StructureData
    {
        /*!< �ṹ���� */
        Type type;

        /*!< �ṹ���� */
        string name;
    };
    /**
     * @brief �������ݽṹ
     */
    struct VariableData
    {
        /*!< ������ */
        string name;

        /*!< �������� */
        string type;

        /*!< ����ǰ׺ */
        string prefix;

        /*!< ���͸�ʽ����� */
        string format;

        /*!< ע�� */
        string comment;
    };


public:
    ParseXML();
    ~ParseXML();

public:
    /**
     * @brief ����xml
     */
    bool Parse( const XMLElement *cpXmlElement);
    
    /**
     * @brief ��ȡ����
     */
    const ParseXML::Type GetType() const;

    /**
     * @brief ��ȡ�ṹ����
     */
    const StructureData &GetStructureData()const;


    /**
     * @brief ��ȡ��������
     */
    int GetVariableDataNum()const;


    /**
     * @brief ��ȡ��������
     */
    const VariableData *GetVariableData(int iIndex)const;

private:
    /**
    * @brief ������
    */
    bool ParseClass(const XMLElement *cpXmlElement);
    
    /**
     * @brief �����ṹ��
     */
    bool ParseStruct(const XMLElement *cpXmlElement);
    
    /**
     * @brief ����ö��
     */
    bool ParseEnum(const XMLElement *cpXmlElement);

    /**
     * @brief �жϱ��������Ƿ���ȷ
     */
    bool CheckVariableType(const string type);

    /**
     * @brief ���ݱ������ͻ�ȡǰ׺
     */
    string GetPrefixByVariableType(const string type);

    /**
     * @brief ���ݱ������ͻ�ȡ��ʽ���
     */
    string GetFormatByVariableType(const string type);
private:
    /*!< �ṹ���� */
    StructureData m_stStructureData;

    /*!< �������� */
    vector<VariableData> m_vVariables;


};

#endif // __PARSEXML_H__

