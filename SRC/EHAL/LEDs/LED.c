#include "../../config/LEDs_cfg.h"
#include "../../MCAL/DIO/DIO_types.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../../SRC/utils/STD_Types.h"



extern const LED_Info LED_Group[activeLEDs];

void LED_ON (LED LED_iD)
{
	uint8 i;
	for( i = 0; i < activeLEDs; i++)
	{
		if(LED_iD == LED_Group[i].number)
		{
			if(LED_Group[i].active)
			{
				Dio_WriteChannel(LED_Group[i].ledPin, STD_high);
				return;
			} else
			{
				Dio_WriteChannel(LED_Group[i].ledPin, STD_low);
				return;
			}
		}
	}
}
void LED_OFF (LED LED_iD)
{
	uint8 i;
	for( i = 0; i < activeLEDs; i++)
	{
		if(LED_iD == LED_Group[i].number)
		{
			if(LED_Group[i].active)
			{
				Dio_WriteChannel(LED_Group[i].ledPin, STD_low);
				return;
			} else
			{
				Dio_WriteChannel(LED_Group[i].ledPin, STD_high);
				return;
			}
		}
	}
}


