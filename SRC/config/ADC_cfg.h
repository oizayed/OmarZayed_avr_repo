/*
 * ADC_cfg.h
 *
 *  Created on: Jul 20, 2019
 *      Author: New User
 */

#ifndef E15_LAB_SRC_SRC_CONFIG_ADC_CFG_H_
#define E15_LAB_SRC_SRC_CONFIG_ADC_CFG_H_

/*
 * Choose Voltage_Reference_Selection_Mode from following list:-
 *
 * Internal_Vref_turned_off
 * AVCC_with_external_capacitor_at_AREF_pin
 * Internal_2.56V_Ref_with_ext_cap
 *
 * */

#define Voltage_Reference_Selection_Mode		Internal_Vref_turned_off

/*
 * Choose ADC_Adjust_Result from following list:-
 *
 * ADC_Left_Adjust_Result
 * ADC_Right_Adjust_Result
 *
 * */

#define ADC_Adjust_Result		ADC_Right_Adjust_Result

/*
 * Choose ADC_Prescaler from following list:-
 *
 * ADC_Prescaler_2_msk
 * ADC_Prescaler_4_msk
 * ADC_Prescaler_8_msk
 * ADC_Prescaler_16_msk
 * ADC_Prescaler_32_msk
 * ADC_Prescaler_64_msk
 * ADC_Prescaler_128_msk
 *
 * */

#define ADC_Prescaler		ADC_Prescaler_128_msk

/*
 * Choose ADC_Auto_Trigger_Mode from following list:-
 *
 * No_Auto_Trigger
 * Free_Running_mode
 * Analog_Comparator
 * External_Interrupt_Request_0
 * Timer/Counter0_Compare_Match
 * Timer/Counter0_Overflow
 * Timer/Counter1_Compare_Match_B
 * Timer/Counter1_Overflow
 * Timer/Counter1_Capture Event
 *
 * */

#define ADC_Auto_Trigger_Source		No_Auto_Trigger




#endif /* E15_LAB_SRC_SRC_CONFIG_ADC_CFG_H_ */
