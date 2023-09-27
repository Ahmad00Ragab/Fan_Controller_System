/*===========================================================================================
 * Filename   : Main.c
 * Author     : Ahmad Haroun
 * Description: Fan Controller system
 * Created on : Jul 12, 2023
 *==========================================================================================*/

 /*===========================================================================================
 * SUMMARY:
 *  The aim of this project is to design a temperature-controlled fan using ATmega32
 *  MICROCONTROLLER, in which the fan is automatically turned ON or OFF according to the
 *  temperature.
 *==========================================================================================*/

/*===========================================================================================
 * Specification
 * temperature.
 * MicroController    : ATMega32
 * CPU Frequency      : 1Mhz
 * Timer              : Timer0 (8-bit), PWM MODE
 * Display            : LCD (LM016L)
 * temperature sensor : LM35
 * ADC                : ATMEGA32 ADC
 * Motor Driver       : H-Bridge (L293D)
 *==========================================================================================*/
#include "adc.h"
#include "lcd.h"
#include "lm35.h"
#include "motor.h"



/*******************************************************************************
 *                               Main                                          *
 *******************************************************************************/
int main(void)
{

	ADC_ConfigType Config = {Internal,prescaler8_ID};
	LCD_init();
	ADC_init(&Config);
	DcMotor_Init();
	LCD_displayString("Fan is ");
	LCD_moveCursor(1,0);
	LCD_displayString("Temp =    c");
	uint8 temp;
	while(1)
	{
		temp = LM35_getTemperature();
		if(temp < 30)
		{
			if(temp >= 10)
			{
				DcMotor_Rotate(stop, 0);
				LCD_moveCursor(0, 7);
				LCD_displayString("off");
				LCD_moveCursor(1, 7);
				LCD_intgerToString(temp);
			}
			else
			{
				DcMotor_Rotate(stop, 0);
				LCD_moveCursor(0, 7);
				LCD_displayString("off");
				LCD_moveCursor(1, 7);
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
			}

		}
		else if(temp >= 30 && temp < 60)
		{
			DcMotor_Rotate(rotate_A_CW, 25);
			LCD_moveCursor(0, 7);
			LCD_displayString("on ");
			LCD_moveCursor(1, 7);
			LCD_intgerToString(temp);
		}
		else if(temp >= 60 && temp < 90)
		{

				DcMotor_Rotate(rotate_A_CW, 50);
				LCD_moveCursor(0, 7);
				LCD_displayString("on ");
				LCD_moveCursor(1, 7);
				LCD_intgerToString(temp);


		}
		else if(temp >= 90 && temp < 120)
		{
			if(temp >= 100)
			{
				DcMotor_Rotate(rotate_A_CW, 75);
				LCD_moveCursor(0, 7);
				LCD_displayString("on ");
				LCD_moveCursor(1, 7);
				LCD_intgerToString(temp);
			}
			else
			{
				DcMotor_Rotate(rotate_CW, 75);
				LCD_moveCursor(0, 7);
				LCD_displayString("on ");
				LCD_moveCursor(1, 7);
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
			}

		}
		else if(temp >= 120)
		{
			DcMotor_Rotate(rotate_A_CW, 100);
			LCD_moveCursor(0, 7);
			LCD_displayString("on ");
			LCD_moveCursor(1, 7);
			LCD_intgerToString(temp);
		}
		else
		{

		}
	}
	return 0;
}
