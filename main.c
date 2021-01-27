#include "stm32f10x.h"


int main()
{
	delay_init();
	OLED_Init();
	SHT2x_Init(); 
	LCD_P6x8Str(1,1,temch);
	LCD_P6x8Str(120,1,temC);
	LCD_P6x8Str(1,3,humch);
	LCD_P6x8Str(110,3,humRH);
	
	while(1)
	{
		sht20_temperature=SHT2x_GetTempPoll();//��ȡSHT20 �¶�  
		sht20_humidity=SHT2x_GetHumiPoll();//��ȡSHT20 ʪ��
		write_6_8_number(80,1,sht20_temperature);//�¶�
		write_6_8_number(70,3,sht20_humidity);//ʪ��
		delay_ms(100);

	}
	
}
