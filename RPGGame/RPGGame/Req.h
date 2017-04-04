#ifndef __REQ_H__
#define __REQ_H__

#include <map>
#include <vector>
#include <string>

using std::map;
using std::vector;
using std::string;
using std::pair;

/**
* @brief ������
*/
class Req
{
public:
	Req();
	~Req();
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
	void Add(string sKey, vector<Req> vValue);

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
	const vector<Req> GetVector(string sKey)const;

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
	/*!< ���Ͳ���ӳ�� */
	map<string, int> m_mapIntArg;
	/*!< �ַ�������ӳ�� */
	map<string, string> m_mapStringArg;
	/*!< �������ӳ�� */
	map<string, vector<Req>> m_mapVectorArg;
};


#endif // __REQ_H__
