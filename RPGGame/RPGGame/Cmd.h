#ifndef __CMD_H__
#define __CMD_H__

/**
* @brief ���������ռ�
*/
namespace cmd
{
	/**
	* @brief ����ö��
	*/
	enum Command
	{
		/*!< �� */
		COMMAND_IDLE,

		/*!< ��ʼ */
		COMMAND_START,

		/*!< չʾ���� */
		COMMAND_SHOW_BAG = 10001,

		/*!< չʾ��Ʒ */
		COMMAND_SHOW_ITEM = 10002,
	};

}



#endif // __CMD_H__

