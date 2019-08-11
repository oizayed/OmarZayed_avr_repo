/*
 * ADC_hw.h
 *
 *  Created on: Jul 20, 2019
 *      Author: New User
 */

#ifndef E15_LAB_SRC_SRC_MCAL_ADC_ADC_HW_H_
#define E15_LAB_SRC_SRC_MCAL_ADC_ADC_HW_H_

#define ADMUX				*((volatile uint8*)0x27)
#define ADCSRA				*((volatile uint8*)0x26)
#define ADCX				*((volatile uint16*)0x24)
#define SFIOR				*((volatile uint8*)0x50)

#endif /* E15_LAB_SRC_SRC_MCAL_ADC_ADC_HW_H_ */
