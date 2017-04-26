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
		COMMAND_IDLE = 0,

		/*!< ��ʼ */
		COMMAND_START,

		/*!< չʾ���� */
		COMMAND_SHOW_BAG = 10001,

        /*!< չʾ��Ʒ */
        COMMAND_SHOW_ITEM = 10002,

        /*!< չʾ�̵� */
        COMMAND_SHOW_SHOP = 10003,

        /*!< չʾ��Ʒ */
        COMMAND_SHOW_SHOP_ITEM = 10004,



        
    };

    /**
    * @brief ֪ͨö��
    */
    enum Notify
    {
        /*!< �� */
        NOTIFY_IDLE = 0,
        NOTIFY_SHOP_BUY = 30001,

        NOTIFY_UPDATE_PROPERTY = 20001,
        NOTIFY_UPDATE_INFORMATION = 20002,
    };
}



#endif // __CMD_H__

