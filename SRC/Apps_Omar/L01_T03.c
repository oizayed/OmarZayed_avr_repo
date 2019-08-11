#include "../EHAL/LEDs/LED.h"
#include "../EHAL/Buttons/Buttons.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/PORT_DRIVER/PORT.h"



void L01_T03(void)
{
	PORT_init();
	LED_OFF(LED_D0);
	LED_OFF(LED_D1);
	LED_OFF(LED_D2);
	LED_OFF(LED_D3);
	LED_OFF(LED_D4);
	LED_OFF(LED_D5);
	LED_OFF(LED_D6);
	LED_OFF(LED_D7);

	while(1)
	{

		if(Button_Status(Button_B0))
		{
			LED_ON(LED_D0);
		}


	}
}
