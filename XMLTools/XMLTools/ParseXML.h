#ifndef __PARSEXML_H__
#define __PARSEXML_H__

#include <string>
#include <map>
#include <vector>

using namespace std;

#include "tinyxml2.h"

using namespace tinyxml2;

/**
 * @brief ����xml
 */

class ParseXML
{
public:
    ParseXML();
    ~ParseXML();

public:
    struct Data
    {
        string node;
        map<string, string> mapClassAttr;
        vector<map<string,string>> vecPropertyAttr;
        vector<Data> vecInner;
    };
public:
    /**
    * @brief ����xml
    */
    bool Parse(const string sFileName);

    /**
    * @brief ����
    */
    void Clear();
private:
    /**
     * @brief ����xml
     */
    bool Parse(const XMLElement *cpXmlElement, Data &stData);
   
    /**
     * @brief ������
     */
    bool ParseClass(const XMLElement *cpXmlElement, Data &stData);
    
    /**
     * @brief �����ṹ��
     */
    bool ParseStruct(const XMLElement *cpXmlElement, Data &stData);
    
    /**
     * @brief ����ö��
     */
    bool ParseEnum(const XMLElement *cpXmlElement, Data &stData);

    /**
     * @brief ������Ա
     */
    bool ParseProperty(const XMLElement *cpXmlElement, Data &stData);

    /**
     * @brief ��������
     */
    bool ParseAttribute(const XMLElement *cpXmlElement, map<string,string> &mapAttr);


private:
    string m_sFileName;

    vector<Data> m_vecData;
};

#endif // __PARSEXML_H__

