/*===========================================================================================
 * Filename   : timer0.h
 * Author     : Ahmad Haroun
 * Description: Header file ATMEGA32 Timer0 Driver
 * Created on : Jun 12, 2023
 *==========================================================================================*/
#ifndef TIMER0_H_
#define TIMER0_H_

#include "gpio.h"
#include <avr/interrupt.h>


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	NORMAL_PORT,
	TOGGLE_OC1A,
	CLEAR_OC1A,
	SET_OC1A,
}CTC_Output_Mode;

typedef enum
{
	Normal_Port,
	Toggle_OC1A ,
	NON_INVERTING,
	INVERTING,
}PWM_Output_Mode;

typedef enum
{
	NO_CLOCK,
	NO_PRESCALER,
	PRESCALER_8,
	PRESCALER_64,
	PRESCALER_256,
	PRESCALER_1024,
	EXTERNAL_FALLING,
	EXTERNAL_RISING,
}Clock_Pescaler;

typedef enum
{
	DISABLE_INTERRUPT,
	ENABLE_INTERRUPT,
}INTERRUPT_SELECT;

/*******************************************************************************
 *                               Global_Variables Declaration                  *
 *******************************************************************************/


/********************************************************************************
 * Global Array of 4 pointers to function
 * 1.static to use in this file and hold his value
 * 2.volatile to use in ISRs function and in the function 'TIMER0_Set_CallBack'
 * 3.Initial value with Null or use NULL_Ptr in standard_types
 * TIMER0_OVF_vect    : INDEX 0
 * TIMER0_COMP        : INDEX 1
 *********************************************************************************/
static volatile void (*TIMER0_CallBack_Array[2])(void) = {NULL_PTR};



/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/


/**************************************************************************
 * Function Name: TIMER0_Init_Normal_Mode
 * Description  : Initialize Timer0 in Normal Mode or Overflow mode
 * INPUTS       : Prescaler,Interrupt_Choice
 * RETURNS      : void
 **************************************************************************/
void TIMER0_Init_Normal_Mode(Clock_Pescaler Prescaler,INTERRUPT_SELECT Interrupt_Choice);



/**************************************************************************
 * Function Name: TIMER0_Init_CTC_Mode
 * Description  : Initialize Timer0 in Clear timer on compare match(CTC) mode
 * INPUTS       : Compare_Value,OutPutPin_Mode,Prescaler,Interrupt_Choice
 * RETURNS      : void
 **************************************************************************/
void TIMER0_Init_CTC_Mode(uint16 Compare_Value,CTC_Output_Mode OutPutPin_Mode
		                 ,Clock_Pescaler Prescaler,INTERRUPT_SELECT Interrupt_Choice);



/**************************************************************************
 * Function Name: TIMER0_Init_PWM_Mode
 * Description  : Initialize Timer0 in pulse width modulation generation(PWM)mode
 * INPUTS       : Compare_Value(Duty Cycle),OutPutPin_Mode,Prescaler,Interrupt_Choice
 * RETURNS      : void
 **************************************************************************/
void TIMER0_Init_PWM_Mode(uint8 Compare_Value,PWM_Output_Mode OutPutPin_Mode
		                  ,Clock_Pescaler Prescaler,INTERRUPT_SELECT Interrupt_Choice);



/**********************************************************************************
 * Function Name: TIMER0_Set_CallBack
 * Description  : A Function to set the callBack functions for Timer0 Events
 * INPUTS       : ptr_2_fun,index(which indicates which ISR would be Executed)
 * RETURNS      : void
 **********************************************************************************/
void TIMER0_Set_CallBack(void(* ptr_2_fun)(void),uint8 index);

#endif /* TIMER0_H_ */
