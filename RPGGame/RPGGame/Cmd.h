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
        COMMAND_SHOW_BAG = 2100000,

        /*!< չʾ��Ʒ */
        COMMAND_SHOW_ITEM = 2110000,

        /*!< չʾ�̵� */
        COMMAND_SHOW_SHOP = 1200000,

        /*!< չʾ��Ʒ */
        COMMAND_SHOW_SHOP_ITEM = 1210000,



        
    };

    /**
    * @brief ֪ͨö��
    */
    enum Notify
    {
        /*!< �� */
        NOTIFY_IDLE = 0,
        NOTIFY_SHOP_BUY = 1210001,
        NOTIFY_SHOP_SELL = 1210002,

        NOTIFY_UPDATE_PROPERTY = 20001,
        NOTIFY_UPDATE_INFORMATION = 20002,
    };
}



#endif // __CMD_H__

