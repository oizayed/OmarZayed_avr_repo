#include "../MCAL/DIO/DIO.h"
#include "../MCAL/PORT_DRIVER/PORT.h"



void L01_T04(void)
{
	STD_levelType CurrStatus0 = STD_low, PrevStatus0 = STD_low;
	STD_levelType CurrStatus1 = STD_low, PrevStatus1 = STD_low;
	STD_levelType CurrStatus2 = STD_low, PrevStatus2 = STD_low;
	STD_levelType LED0Status = STD_low;
	STD_levelType LED1Status = STD_low;
	STD_levelType LED2Status = STD_low;
	PORT_init();

	while(1)
	{
		CurrStatus0 = Dio_ReadChannel(Dio_Channel_D0);
		CurrStatus1 = Dio_ReadChannel(Dio_Channel_D1);
		CurrStatus2 = Dio_ReadChannel(Dio_Channel_D2);

		if(CurrStatus0 == STD_high)
		{
			if(PrevStatus0 == STD_low && !(LED2Status && LED1Status))
			{
				Dio_FlipChannel(Dio_Channel_D5);
				LED0Status = !LED0Status;
			}
		}
		if(CurrStatus1 == STD_high)
		{
			if(PrevStatus1 == STD_low && !(LED2Status && LED0Status))
			{
				Dio_FlipChannel(Dio_Channel_D6);
				LED1Status = !LED1Status;
			}
		}
		if(CurrStatus2 == STD_high)
		{
			if(PrevStatus2 == STD_low && !(LED1Status && LED0Status))
			{
				Dio_FlipChannel(Dio_Channel_D7);
				LED2Status = !LED2Status;
			}
		}

		PrevStatus0 = CurrStatus0;
		PrevStatus1 = CurrStatus1;
		PrevStatus2 = CurrStatus2;
	}
}
