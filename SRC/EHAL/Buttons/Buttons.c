#include "../../config/Buttons_cfg.h"
#include "../../MCAL/DIO/DIO_types.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../../SRC/utils/STD_Types.h"



extern const Button_Info Button_Group[activeButtons];

Button_Press Button_Status (Button Button_iD)
{
	uint8 i;
	Button_Press OurButton = Not_Pressed;
	for(i = 0; i < activeButtons; i++)
	{
		if(Button_iD == Button_Group[i].number)
		{
			if(Button_Group[i].active)
			{
				if(Dio_ReadChannel(Button_Group[i].ButtonPin))
				{
					OurButton = Pressed;
				} else
				{
					OurButton = Not_Pressed;
				}

			} else
			{
				if(Dio_ReadChannel(Button_Group[i].ButtonPin))
				{
					OurButton = Not_Pressed;
				} else
				{
					OurButton = Pressed;
				}
			}
		}
	}
	return OurButton;
}



