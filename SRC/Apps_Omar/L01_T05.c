#include "../MCAL/DIO/DIO.h"
#include "../MCAL/PORT_DRIVER/PORT.h"

#define Button0ON		STD_low
#define Button0OFF		STD_high
#define Button1ON		STD_low
#define Button1OFF		STD_high
#define Button2ON		STD_low
#define Button2OFF		STD_high
#define Button3ON		STD_high
#define Button3OFF		STD_low
#define Button4ON		STD_low
#define Button4OFF		STD_high
#define Button5ON		STD_low
#define Button5OFF		STD_high
#define Button6ON		STD_high
#define Button6OFF		STD_low
#define Button7ON		STD_low
#define Button7OFF		STD_high



void L01_T05(void)
{
	STD_levelType CurrStatus0 = Button0OFF, PrevStatus0 = Button0OFF;
	STD_levelType CurrStatus1 = Button1OFF, PrevStatus1 = Button1OFF;
	STD_levelType CurrStatus2 = Button2OFF, PrevStatus2 = Button2OFF;
	STD_levelType CurrStatus3 = Button3OFF, PrevStatus3 = Button3OFF;
	STD_levelType CurrStatus4 = Button4OFF, PrevStatus4 = Button4OFF;
	STD_levelType CurrStatus5 = Button5OFF, PrevStatus5 = Button5OFF;
	STD_levelType CurrStatus6 = Button6OFF, PrevStatus6 = Button6OFF;
	STD_levelType CurrStatus7 = Button7OFF, PrevStatus7 = Button7OFF;

	Dio_WriteChannel(Dio_Channel_D0, STD_low);
	Dio_WriteChannel(Dio_Channel_D1, STD_high);
	Dio_WriteChannel(Dio_Channel_D2, STD_low);
	Dio_WriteChannel(Dio_Channel_D3, STD_high);
	Dio_WriteChannel(Dio_Channel_D4, STD_low);
	Dio_WriteChannel(Dio_Channel_D5, STD_low);
	Dio_WriteChannel(Dio_Channel_D6, STD_high);
	Dio_WriteChannel(Dio_Channel_D7, STD_high);

	PORT_init();

	while(1)
	{
		CurrStatus0 = Dio_ReadChannel(Dio_Channel_C0);
		CurrStatus1 = Dio_ReadChannel(Dio_Channel_C1);
		CurrStatus2 = Dio_ReadChannel(Dio_Channel_C2);
		CurrStatus3 = Dio_ReadChannel(Dio_Channel_C3);
		CurrStatus4 = Dio_ReadChannel(Dio_Channel_C4);
		CurrStatus5 = Dio_ReadChannel(Dio_Channel_C5);
		CurrStatus6 = Dio_ReadChannel(Dio_Channel_C6);
		CurrStatus7 = Dio_ReadChannel(Dio_Channel_C7);



		if(CurrStatus0 == Button0ON)
		{
			if(PrevStatus0 == Button0OFF)
			{
				Dio_FlipChannel(Dio_Channel_D0);
			}
		}
		if(CurrStatus1 == Button1ON)
		{
			if(PrevStatus1 == Button1OFF)
			{
				Dio_FlipChannel(Dio_Channel_D1);
			}
		}
		if(CurrStatus2 == Button2ON)
		{
			if(PrevStatus2 == Button2OFF)
			{
				Dio_FlipChannel(Dio_Channel_D2);
			}
		}
		if(CurrStatus3 == Button3ON)
		{
			if(PrevStatus3 == Button3OFF)
			{
				Dio_FlipChannel(Dio_Channel_D3);
			}
		}

		if(CurrStatus4 == Button4ON)
		{
			if(PrevStatus4 == Button4OFF)
			{
				Dio_FlipChannel(Dio_Channel_D4);
			}
		}

		if(CurrStatus5 == Button5ON)
		{
			if(PrevStatus5 == Button5OFF)
			{
				Dio_FlipChannel(Dio_Channel_D5);
			}
		}

		if(CurrStatus6 == Button6ON)
		{
			if(PrevStatus6 == Button6OFF)
			{
				Dio_FlipChannel(Dio_Channel_D6);
			}
		}
		if(CurrStatus7 == Button7ON)
		{
			if(PrevStatus7 == Button7OFF)
			{
				Dio_FlipChannel(Dio_Channel_D7);
			}
		}



		PrevStatus0 = CurrStatus0;
		PrevStatus1 = CurrStatus1;
		PrevStatus2 = CurrStatus2;
		PrevStatus3 = CurrStatus3;
		PrevStatus4 = CurrStatus4;
		PrevStatus5 = CurrStatus5;
		PrevStatus6 = CurrStatus6;
		PrevStatus7 = CurrStatus7;
	}
}
