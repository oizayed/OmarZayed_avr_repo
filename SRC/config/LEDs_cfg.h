#ifndef E15_LEDs_cfg
#define E15_LEDs_cfg
#include "../MCAL/DIO/DIO_types.h"
#include "../utils/STD_Types.h"


#define activeLEDs 8


typedef enum
{
	LED_D0,
	LED_D1,
	LED_D2,
	LED_D3,
	LED_D4,
	LED_D5,
	LED_D6,
	LED_D7
}LED;



typedef struct
{
	LED number;
	Activity active;
	Dio_ChannelType ledPin;
}LED_Info;

#endif
