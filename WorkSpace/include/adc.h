/*===========================================================================================
 * Filename   : adc.h
 * Author     : Ahmad Haroun
 * Description: Header File for ADC  Driver
 * Created on : Jun 12, 2023
 *==========================================================================================*/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56



/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
/* voltage reference */
typedef enum
{
	AREF,
	AVCC,
	reserved ,
	Internal
}ADC_ReferenceVolatge;

typedef enum
{
	prescaler2_ID0,
	prescaler2_ID1,
	prescaler4_ID ,
	prescaler8_ID ,
	prescaler16_ID ,
	prescaler32_ID,
	prescaler64_ID,
	prescaler128_ID
}ADC_Prescaler;

typedef struct
{
	ADC_ReferenceVolatge Refrence_Voltage;
	ADC_Prescaler prescaler;

}ADC_ConfigType;

/*******************************************************************************
*                      Functions Prototypes                                   *
*******************************************************************************/


/**************************************************************************
 * Function Name: ADC_init
 * Description  : Initialize ADC in Polling Technique
 * INPUTS       : Config_ptr (struct of initialization configuration)
 * RETURNS      : void
 **************************************************************************/
void ADC_init(const ADC_ConfigType *Config_Ptr);



/**************************************************************************
 * Function Name: ADC_readChannel
 * Description  : responsible for read analog data from a certain ADC channel
 *                and convert it to digital using the ADC driver.
 * INPUTS       : channel_num (the channel that the LM35 is connected to )
 * RETURNS      : uint16(the reading in digital form)
 **************************************************************************/
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
