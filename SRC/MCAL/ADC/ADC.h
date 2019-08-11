/*
 * ADC.h
 *
 *  Created on: Jul 20, 2019
 *      Author: New User
 */

#ifndef E15_LAB_SRC_SRC_MCAL_ADC_ADC_H_
#define E15_LAB_SRC_SRC_MCAL_ADC_ADC_H_

#include "ADC_Types.h"
#include "../../utils/STD_Types.h"


void ADC_int(void);
void ADC_Start_Conv(ADC_ChannelType ADC_Channel_Used);
float32 ADC_Read_Conv(ADC_ChannelType ADC_Channel_Used);
void ADC_enableInterrupt(void);
void ADC_disableInterrupt(void);




#endif /* E15_LAB_SRC_SRC_MCAL_ADC_ADC_H_ */
