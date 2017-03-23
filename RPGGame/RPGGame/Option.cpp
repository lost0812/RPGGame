#include "Option.h"


OptionsArrow::OptionsArrow(void)
{
}


OptionsArrow::~OptionsArrow(void)
{
}

bool OptionsArrow::Init(OptionsPosition &optionsPosition)
{
	m_optionsPosition = optionsPosition;
	return true;
}

int OptionsArrow::SelectOption()
{
	int input;
	int selected = 0;
	gotoxy( m_optionsPosition.positions[selected].iX, m_optionsPosition.positions[selected].iY );
	printf(OptionArrow);
	while( true )
	{
		Sleep(100);
		if( _kbhit( ) )
		{
			input = _getch( );

			if( input == 13 )//�س�
				return selected;
			else if( input == 27 )//ESC
				return -1;

			//�����
			if( input == 224 )
			{
				if( _kbhit() )
				{
					input = _getch();
					gotoxy( m_optionsPosition.positions[selected].iX, m_optionsPosition.positions[selected].iY );
					printf(OptionClearArrow);
					if( m_optionsPosition.direction == data::DIRECTION_HORIZONTAL )
					{
						switch( input )//�ƶ�
						{
						case 75:if( selected>0 )--selected;break;//��
						case 77:if( selected<m_optionsPosition.positions.size()-1 )++selected;break;//��
						}
					}
					else if( m_optionsPosition.direction == data::DIRECTION_VERTICAL )
					{
						switch( input )
						{
						case 72:if( selected>0 )--selected;break;//��
						case 80:if( selected<m_optionsPosition.positions.size()-1 )++selected;break;//��
						}

					}
					gotoxy( m_optionsPosition.positions[selected].iX, m_optionsPosition.positions[selected].iY );
					printf(OptionArrow);
				}
			}
		}
	}
}
