#include <avr/delay.h>
#include "../EHAL/SepSevSeg/SepSevSeg.h"


void L02_T02(void)
{
	uint8 counter  =0;
	SepSevSeg_Init();
	SepSevSeg_1_en();
	SepSevSeg_2_en();
	uint8 dir = 1;
	while(1)
	{



		counter += dir;

		SepSevSeg_1_DisplayNum(counter % 10 );
		SepSevSeg_2_DisplayNum(counter / 10 );
		_delay_ms(200);

		if(counter == 99)
		{
			dir = - 1;
		}
		if(counter == 0)
		{
			dir = 1;
		}

	}

}

