#ifndef __RSP_H__
#define __RSP_H__

#include <map>
#include <vector>
#include <string>

using std::map;
using std::vector;
using std::string;
using std::pair;


/**
* @brief ��Ӧ��
*/
class Rsp
{
/**
* @brief ��Ӧ��ö��
*/
public:
    enum RetCode
    {
        RETCODE_SUCCEED = 0,
        RETCODE_NO_ITEM,
    };

public:
	Rsp();
	~Rsp();
public:
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
	void Add(string sKey, vector<Rsp> vValue);

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
	const vector<Rsp> GetVector(string sKey)const;

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

public:
    /*!< ��Ӧ�� */
    const static string RetCode;
private:
	/*!< ���Ͳ���ӳ�� */
	map<string, int> m_mapIntArg;
	/*!< �ַ�������ӳ�� */
	map<string, string> m_mapStringArg;
	/*!< �������ӳ�� */
	map<string, vector<Rsp>> m_mapVectorArg;
};

#endif // __RSP_H__
