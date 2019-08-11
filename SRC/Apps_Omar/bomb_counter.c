/*
 * bomb_counter.c
 *
 *  Created on: Jul 13, 2019
 *      Author: New User
 */
#include "../MCAL/DIO/DIO.h"
#include "../Scheduler/Scheduler.h"
#include "../MCAL/PORT_DRIVER/PORT.h"
#include "../MCAL/EXTI/EXTI.h"
#include "../utils/Interrupts.h"
#include "../EHAL/BcdSevSegments/BcdSevSegments.h"
#include "../EHAL/LCD/LCD.h"
#include "../EHAL/KP/KP.h"
uint8 seconds = 60;
uint8 key = 255;
const uint8 actualPasscode[8] = {'1','2','3','4','5','6','7','8'};
uint8 givenPasscode[8];
uint8 period = 100;
boolean blinking = false;
void Task_1(void)
{
	static uint8  blink = 0;
	blink ++;
	if(blink == 1)
	{
		BcdSevSeg_2_di();
		BcdSevSeg_DisplayNum(seconds % 10);
		if(!blinking)
		{
			BcdSevSeg_1_en();
		}
	}
	else if(blink == 2)
	{
		BcdSevSeg_1_di();
		BcdSevSeg_DisplayNum(seconds / 10);
		if(!blinking)
		{
			BcdSevSeg_2_en();
		}
		blink =0;

	}

}
void Task_2(void)
{
	seconds--;
	if(!seconds)
	{
		Set_Task_Status(Task_2, Suspended);
		Dio_WriteChannel(Dio_Channel_D3,STD_high);
		Dio_WriteChannel(Dio_Channel_D4,STD_high);

	}
}
void Task_3(void)
{
	static uint8 i = 0;
	boolean Pass = false;
	static uint8 PrvKey = 255;
	const uint8 MapArr[16]={'1','2','3','+', '4', '5','6','-','7','8','9','*','M','0','C','E'};
	key = KP_getPressedButton();
	if(key != 255)
	{
		if(PrvKey == 255)
		{
			LCD_writeCharData(MapArr[key]);
			givenPasscode[i] = MapArr[key];
			i++;
			if(i == 8)
			{
				Pass = true;
				for(uint8 j = 0; j < 8; j++)
				{
					if(actualPasscode[j] != givenPasscode[j])
					{
						Pass = false;
						period = period / 2;
						Set_Task_Status(Task_2, period);
						break;
					}
				}
				if(Pass == true)
				{
					Set_Task_Status(Task_2, Suspended);
				}
				i = 0;
				LCD_writeString("              ",1,0);
				LCD_goToPos(1,0);
			}

		}
	}
	PrvKey = key;
}
void Task_4(void)
{
	if(seconds < 10)
	{
		blinking = !blinking;
	}
}

void BombCounter(void)
{
	PORT_init();
	LCD_init();
	EXTI_init();
	Scheduler_createTask(Task_1,1,Active);
	Scheduler_createTask(Task_2,period,Active);
	Scheduler_createTask(Task_3,3,Active);
	Scheduler_createTask(Task_4,period,Active);
	Dio_WriteChannel(Dio_Channel_D3,STD_low);
	Dio_WriteChannel(Dio_Channel_D4,STD_low);
	LCD_writeString("Enter Passcode :",0,0);
	LCD_goToPos(1,0);
	Scheduler_init();
	while(1)
	{
		;
	}



}
void ISR(EXTI_INT0)
{
	seconds = 1;
}
