/*===========================================================================================
 * Filename   : adc.c
 * Author     : Ahmad Haroun
 * Description: Source File for ADC  Driver
 * Created on : Jun 12, 2023
 *==========================================================================================*/
#include "adc.h"
#include "common_macros.h"      /* To use the macros like SET_BIT */
#include "gpio.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


/**************************************************************************
 * Function Name: ADC_init
 * Description  : Initialize ADC in Polling Technique
 * INPUTS       : Config_ptr (struct of initialization configuration)
 * RETURNS      : void
 **************************************************************************/
void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	ADMUX  = (ADMUX & 0x3F)|((Config_Ptr->Refrence_Voltage) << 6);
	ADCSRA = (ADCSRA & 0xF8)|(Config_Ptr->prescaler);
	ADCSRA |=(1 << ADEN) ; /* ADC Enable */
}

/**************************************************************************
 * Function Name: ADC_readChannel
 * Description  : responsible for read analog data from a certain ADC channel
 *                and convert it to digital using the ADC driver.
 * Technique    : POLLING Technique
 * INPUTS       : channel_num (the channel that the LM35 is connected to )
 * RETURNS      : uint16(the reading in digital form)
 **************************************************************************/
uint16 ADC_readChannel(uint8 channel_num)
{
	ADMUX = (ADMUX & 0xE0) | (channel_num & 0x1F);
	SET_BIT(ADCSRA,ADSC);     /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}
