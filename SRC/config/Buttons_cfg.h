#ifndef E15_Buttons_cfg
#define E15_Buttons_cfg
#include "../MCAL/DIO/DIO_types.h"
#include "../utils/STD_Types.h"

#define activeButtons 8


typedef enum
{
	Button_B0,
	Button_B1,
	Button_B2,
	Button_B3,
	Button_B4,
	Button_B5,
	Button_B6,
	Button_B7
}Button;

typedef enum
{
	Not_Pressed,
	Pressed
}Button_Press;


typedef struct
{
	Button number;
	Activity active;
	Dio_ChannelType ButtonPin;
}Button_Info;

#endif
