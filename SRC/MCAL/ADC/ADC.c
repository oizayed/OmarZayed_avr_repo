/*
 * ADC.c
 *
 *  Created on: Jul 20, 2019
 *      Author: New User
 */
#define Voltage_Reference_clr_msk						0b00111111
#define Internal_Vref_turned_off						0b00000000
#define AVCC_with_external_capacitor_at_AREF_pin		0b01000000
#define Internal_2_56V_Ref_with_ext_cap					0b11000000

#define ADC_Adjust_Result_clr_msk						0b11011111
#define ADC_Left_Adjust_Result							0b00100000
#define ADC_Right_Adjust_Result							0b00000000

#define ADC_Prescaler_clr_msk							0b11111000
#define ADC_Prescaler_2_msk								0b00000000
#define ADC_Prescaler_4_msk								0b00000010
#define ADC_Prescaler_8_msk								0b00000011
#define ADC_Prescaler_16_msk							0b00000100
#define ADC_Prescaler_32_msk							0b00000101
#define ADC_Prescaler_64_msk							0b00000110
#define ADC_Prescaler_128_msk							0b00000111

#define Auto_Trigger_msk								0b00011111
#define Free_Running_mode                               0b00000000
#define Analog_Comparator                               0b00100000
#define External_Interrupt_Request_0                    0b01000000
#define Timer_Counter0_Compare_Match                    0b01100000
#define Timer_Counter0_Overflow                         0b10000000
#define Timer_Counter1_Compare_Match_B                  0b10100000
#define Timer_Counter1_Overflow                         0b11000000
#define Timer_Counter1_Capture Event                    0b11100000


#define Single_Input_clr_msk							0b11111000

#define Max_No_Of_Channels								8

#define ADC_Enable_msk									0b10000000
#define ADC_Start_Conv_msk								0b01000000
#define Auto_Trigger_disable							0b11011111
#define Auto_Trigger_enable								0b00100000

/* =============================================
 * INCLUDES
 * ============================================*/

#include "ADC_hw.h"
#include "../../config/ADC_cfg.h"
#include "ADC.h"
#include "ADC_Types.h"
#include "avr/delay.h"
#include "../../utils/Bit_Math.h"


/* =============================================
 * FUNCTIONS DEFINITIONS
 * ============================================*/

void ADC_int(void)
{
	// set voltage ref
	ADMUX &= Voltage_Reference_clr_msk;
	ADMUX |= Voltage_Reference_Selection_Mode;

	// set ADC_Adjust_Result
	ADMUX &= ADC_Adjust_Result_clr_msk;
	ADMUX |= ADC_Adjust_Result;

	// set Prescaler
	ADCSRA &= ADC_Prescaler_clr_msk;
	ADCSRA |= ADC_Prescaler;

	// enable ADC
	ADCSRA |= ADC_Enable_msk;

#if ADC_Auto_Trigger_Source == No_Auto_Trigger
	ADCSRA &= Auto_Trigger_disable;
#else
	ADCSRA |= Auto_Trigger_enable;
	SFIOR &= Auto_Trigger_msk;
	SFIOR |= ADC_Auto_Trigger_Source;
#endif





}

void ADC_Start_Conv(ADC_ChannelType ADC_Channel_Used)
{

	if (ADC_Channel_Used < Max_No_Of_Channels)
	{
		// choose channel
		ADMUX &= Single_Input_clr_msk;
		ADMUX |= ADC_Channel_Used;

		// start conv
		ADCSRA |= ADC_Start_Conv_msk;
	}


}

static uint16 convertBinaryToDecimal(uint16 num)
{
	int NoInDec = 0, i = 0, remainder;
	while (num!=0)
	{
		remainder = num%10;
		num /= 10;
		NoInDec += remainder;
		++i;
	}
	return NoInDec;
}


float32 ADC_Read_Conv(ADC_ChannelType ADC_Channel_Used)
{
	while(GET_BIT(ADCSRA,6)){}
	uint32 convValue = ADCX;

#if ADC_Adjust_Result == ADC_Left_Adjust_Result

	convValue = convValue >> 6;

#endif


	return (5*(convertBinaryToDecimal(convValue))/1024);

}

void ADC_enableInterrupt(void)
{
	SET_BIT(ADCSRA,3);
}

void ADC_disableInterrupt(void)
{
	CLR_BIT(ADCSRA,3);
}





