#ifndef __CREATEFILE_H__
#define __CREATEFILE_H__
 
#include <stdarg.h>
 
#include "ParseXML.h"
 
 
/**
* @brief ����c++Դ�ļ�
*/
class CreateFile
{
public:
    CreateFile();
    ~CreateFile();

public:
    class TranslateClass
    {
	public:
		bool Translate(const XMLElement *cpXmlElement, const ParseXML::Data &stData, map<string, string> &mapBase);
		bool Translate2(const XMLElement *cpXmlElement, const ParseXML::Data &stData, map<string, string> &mapBase);
    private:
        bool ConvertParam(string &sValue, const char * csParam);

        bool TranslateBase(const XMLElement *cpXmlElement, const map<string, string> &mapData, map<string, string> &mapBase);
		bool TranslateAttr(const XMLElement *cpXmlElement, const map<string, string> &mapData, map<string, string> &mapBase);
        bool TranslateBaseList(
            const XMLElement *cpXmlElement,
            const vector<map<string, string>> vecData,
            vector<map<string, string>> &vecBaseList);
		bool TranslateList(
			const XMLElement *cpXmlElement,
			const vector<ParseXML::Data> vecData,
			vector<map<string, string>> &vecBaseList);
		bool TranslateCompose(const XMLElement *cpXmlElement, map<string, string> &mapBase);
		bool TranslateCompose2(const XMLElement *cpXmlElement, map<string, string> &mapBase);
    private:
        void Replace(string &sSrcStr, const string sOldStr, const string sNewStr)const;
        void Replace(string &sSrcStr, const map<string, string> &mapReplace)const;
    private:
        //��������
        map<string, string> m_mapBase;

		vector<map<string, string>> m_vecProperty;
		vector<map<string, string>> m_vecEnum;
		vector<map<string, string>> m_vecStruct;
		vector<map<string, string>> m_vecClass;
        //��������
        map<string, vector<map<string, string>>> m_vecBaseList;
    };
public:
    /**
    * @brief ����Դ�ļ�
    */
    bool Create(const string sTemplateFile, const ParseXML::Data &stData);
 
private:
    bool Create(const XMLElement *cpXmlElement, const ParseXML::Data &stData);
//    bool CreateClass(const XMLElement *cpXmlElement, const ParseXML::Data &stData, ReplaceMap &stReplaceMap);
//     bool CreateEnum(const XMLElement *cpXmlElement, const ParseXML::Data &stData);
//     bool CreateStruct();

    bool TranslateParam(string &sValue, const char * csParam);
    bool TranslateBase(const XMLElement *cpXmlElement, const map<string, string> &mapData, map<string, string> &mapBase);
    bool TranslateBaseList(
        const XMLElement *cpXmlElement, 
        const vector<map<string, string>> vecData, 
        vector<map<string, string>> &vecBaseList);
    bool TranslateCompose(const XMLElement *cpXmlElement, map<string, string> &mapBase);
    bool TranslateEnum(const XMLElement *cpXmlElement, const ParseXML::Data &stData, map<string, string> &mapBase);
    bool TranslateFile(const XMLElement *cpXmlElement, map<string, string> &mapBase);

    string Format(const char *csFormat, ...);
 
    void Replace(string &sSrcStr, const string sOldStr, const string sNewStr)const;
    void Replace(string &sSrcStr, const map<string, string> &mapReplace)const;

private:

    //��������
    map<string, string> m_mapBase;

    //��������
    map<string,vector<map<string, string>>> m_vecBaseList;

    //�ϳ����
    map<string, string> m_mapCompose;

    //�ļ�
    map<string, string> m_mapFile;
};
 
 
 
#endif // __CREATECPPFILE_H__
