/*
 * lab_01_BcdSevSeg.c
 *
 *  Created on: Jun 21, 2019
 *      Author: Muhammad.Elzeiny
 */
#include <avr/delay.h>
#include "../EHAL/BcdSevSegments/BcdSevSegments.h"
#include "../MCAL/DIO/DIO.h"

void L02_T03(void)
{
	BcdSevSeg_Init();
	uint8 counter  =99,i;
	STD_levelType CurrStatus = STD_low, PrevStatus = STD_low;
	while(1)
	{
		for(i=0;i<10;i++)
		{
			BcdSevSeg_2_di();
			BcdSevSeg_DisplayNum(counter % 10 );
			BcdSevSeg_1_en();

			_delay_ms(10);

			BcdSevSeg_1_di();
			BcdSevSeg_DisplayNum(counter / 10 );
			BcdSevSeg_2_en();

			_delay_ms(10);
		}
		if(counter)
		{
			counter--;
		}
		CurrStatus = Dio_ReadChannel(Dio_Channel_D0);
		if(CurrStatus == STD_high)
		{
			if(PrevStatus == STD_low)
			{
				counter = 99;
			}
		}
		PrevStatus = CurrStatus;
	}

}
