#include "../EHAL/SepSevSeg/SepSevSeg.h"
#include "../EHAL/KP/KP.h"
#include <util/delay.h>

void L03_T01(void)
{

	SepSevSeg_Init();
	SepSevSeg_1_en();
	SepSevSeg_2_en();
	uint8 B1 = 0;
	uint8 B2 = 0;
	SepSevSeg_1_DisplayNum(B1);
	SepSevSeg_2_DisplayNum(B2);
	uint8 count = 0;
	uint8 PrvKey = 255;
	uint8 key = 255;


	while(1)
	{
		key = KP_getPressedButton();
		if(key != 255)
		{
			if(PrvKey == 255)
			{
				SepSevSeg_1_DisplayNum(key);
				SepSevSeg_2_DisplayNum(key);
			}
		}
		PrvKey = key;
	}

	/*if(count == 0)
				{
					SepSevSeg_1_DisplayNum(B1);
					SepSevSeg_2_DisplayNum(B2);
					count = 1;
				}
				if(count == 1)
				{
					B1 = key;
					count = 2;

				}else if(count == 2)
				{
					B2 = key;
					count = 0;
				}*/


}
