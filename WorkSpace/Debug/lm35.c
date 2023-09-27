/*===========================================================================================
 * Filename   : lm35.c
 * Author     : Ahmad Haroun
 * Description: Source File for LM35 Temperature Sensor Driver
 * Created on : Jun 12, 2023
 *==========================================================================================*/

#include "lm35.h"
#include "adc.h"


/***********************************************************************************************
 * Function Name: LM35_getTemperature
 * Description  : Function responsible for calculate the temperature from the ADC digital value.
 * INPUTS       : void
 * RETURNS      : uint8(temp_value)
 ***********************************************************************************************/
uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}
