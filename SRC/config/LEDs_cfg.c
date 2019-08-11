#include "LEDs_cfg.h"


const LED_Info LED_Group[activeLEDs] =
{
		/*             LEDs Group                  */
		  {LED_D0, Active_HIGH, Dio_Channel_D0 },
		  {LED_D1, Active_LOW, Dio_Channel_D1 },
		  {LED_D2, Active_HIGH, Dio_Channel_D2 },
		  {LED_D3, Active_LOW, Dio_Channel_D3 },
		  {LED_D4, Active_HIGH, Dio_Channel_D4 },
		  {LED_D5, Active_HIGH, Dio_Channel_D5 },
		  {LED_D6, Active_LOW, Dio_Channel_D6 },
		  {LED_D7, Active_LOW, Dio_Channel_D7 }

};
