#define SepSevSeg_COMMMON_CATHOD		STD_low
#define SepSevSeg_COMMMON_ANOD			STD_high

#include "../../utils/STD_Types.h"
#include "../../utils/Bit_Math.h"

#include "../../MCAL/PORT_DRIVER/PORT.h"
#include "../../MCAL/DIO/DIO.h"

#include "../../config/SepSevSeg_cfg.h"
#include "SepSevSeg.h"

const uint8 SepNumMap[16]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};

void SepSevSeg_Init(void)
{
	PORT_init();
}

void SepSevSeg_1_DisplayNum(uint8 num)
{
	Dio_WriteChannel(SepSevSeg_1_PIN_a, (SepSevSeg_1_COMMMON_TYPE ^ (GET_BIT(SepNumMap[num],0))) );
	Dio_WriteChannel(SepSevSeg_1_PIN_b, (SepSevSeg_1_COMMMON_TYPE ^ (GET_BIT(SepNumMap[num],1))) );
	Dio_WriteChannel(SepSevSeg_1_PIN_c, (SepSevSeg_1_COMMMON_TYPE ^ (GET_BIT(SepNumMap[num],2))) );
	Dio_WriteChannel(SepSevSeg_1_PIN_d, (SepSevSeg_1_COMMMON_TYPE ^ (GET_BIT(SepNumMap[num],3))) );
	Dio_WriteChannel(SepSevSeg_1_PIN_e, (SepSevSeg_1_COMMMON_TYPE ^ (GET_BIT(SepNumMap[num],4))) );
	Dio_WriteChannel(SepSevSeg_1_PIN_f, (SepSevSeg_1_COMMMON_TYPE ^ (GET_BIT(SepNumMap[num],5))) );
	Dio_WriteChannel(SepSevSeg_1_PIN_g, (SepSevSeg_1_COMMMON_TYPE ^ (GET_BIT(SepNumMap[num],6))) );
}
void SepSevSeg_2_DisplayNum(uint8 num)
{
	Dio_WriteChannel(SepSevSeg_2_PIN_a, (SepSevSeg_2_COMMMON_TYPE ^ (GET_BIT(SepNumMap[num],0))) );
	Dio_WriteChannel(SepSevSeg_2_PIN_b, (SepSevSeg_2_COMMMON_TYPE ^ (GET_BIT(SepNumMap[num],1))) );
	Dio_WriteChannel(SepSevSeg_2_PIN_c, (SepSevSeg_2_COMMMON_TYPE ^ (GET_BIT(SepNumMap[num],2))) );
	Dio_WriteChannel(SepSevSeg_2_PIN_d, (SepSevSeg_2_COMMMON_TYPE ^ (GET_BIT(SepNumMap[num],3))) );
	Dio_WriteChannel(SepSevSeg_2_PIN_e, (SepSevSeg_2_COMMMON_TYPE ^ (GET_BIT(SepNumMap[num],4))) );
	Dio_WriteChannel(SepSevSeg_2_PIN_f, (SepSevSeg_2_COMMMON_TYPE ^ (GET_BIT(SepNumMap[num],5))) );
	Dio_WriteChannel(SepSevSeg_2_PIN_g, (SepSevSeg_2_COMMMON_TYPE ^ (GET_BIT(SepNumMap[num],6))) );
}
void SepSevSeg_1_en(void)
{
	Dio_WriteChannel(SepSevSeg_PIN_EN1,SepSevSeg_1_COMMMON_TYPE);
}
void SepSevSeg_1_di(void)
{
	Dio_WriteChannel(SepSevSeg_PIN_EN1,!SepSevSeg_1_COMMMON_TYPE);
}
void SepSevSeg_2_en(void)
{
	Dio_WriteChannel(SepSevSeg_PIN_EN2,SepSevSeg_2_COMMMON_TYPE);
}
void SepSevSeg_2_di(void)
{
	Dio_WriteChannel(SepSevSeg_PIN_EN2,!SepSevSeg_2_COMMMON_TYPE);
}
