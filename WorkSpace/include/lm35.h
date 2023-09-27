/*===========================================================================================
 * Filename   : lm35.h
 * Author     : Ahmad Haroun
 * Description: Header File for LM35 Temperature Sensor Driver
 * Created on : Jun 12, 2023
 *==========================================================================================*/

#ifndef LM35_H_
#define LM35_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/***********************************************************************************************
 * Function Name: LM35_getTemperature
 * Description  : Function responsible for calculate the temperature from the ADC digital value.
 * INPUTS       : void
 * RETURNS      : void
 ***********************************************************************************************/
uint8 LM35_getTemperature(void);

#endif /* LM35_H_ */
