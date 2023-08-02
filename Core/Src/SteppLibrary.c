/*
 * SteppLibrary.c
 *
 *  Created on: Dec 8, 2022
 *      Author: feodosiy
 */

/**
  ******************************************************************************
  * @file           : SteppLibrary.c
  * @brief          : step body
  ******************************************************************************
  */


#include "SteppLibrary.h"

extern TIM_HandleTypeDef htim1;

//******************FUNCTIONS************************
//------------------------------------------------------------------------------------------
void microDelay(uint16_t delay)
{
  __HAL_TIM_SET_COUNTER(&htim1, 0);
  while (__HAL_TIM_GET_COUNTER(&htim1) < delay);
}
//------------------------------------------------------------------------------------------
void stepMotorRotation(uint32_t steps, uint8_t direction, uint16_t delay)
{
	uint32_t k;
	if (direction == 0)
		HAL_GPIO_WritePin(DIR_PORT_1, DIR_PIN_1, GPIO_PIN_SET);
	else
		HAL_GPIO_WritePin(DIR_PORT_1, DIR_PIN_1, GPIO_PIN_RESET);

	for(k = 0; k < steps; k++)
	{
		HAL_GPIO_WritePin(STEP_PORT_1, STEP_PIN_1, GPIO_PIN_SET);
		microDelay(delay);
		HAL_GPIO_WritePin(STEP_PORT_1, STEP_PIN_1, GPIO_PIN_RESET);
		microDelay(delay);
	}
}
//------------------------------------------------------------------------------------------
void stepMotorVector(uint32_t steps, uint8_t direction, uint16_t delay)
{
	printf("In function stepMotorVector!!! \n");
	uint32_t k;
	if (direction == 0)
		HAL_GPIO_WritePin(DIR_PORT_2, DIR_PIN_2, GPIO_PIN_SET);
	else
		HAL_GPIO_WritePin(DIR_PORT_2, DIR_PIN_2, GPIO_PIN_RESET);
	printf("Before for stepMotorVector!!! \n");
	for(k = 0; k < steps; k++)
	{
		printf("In FOR!!! \n");
		HAL_GPIO_WritePin(STEP_PORT_2, STEP_PIN_2, GPIO_PIN_SET);
		microDelay(delay);
		HAL_GPIO_WritePin(STEP_PORT_2, STEP_PIN_2, GPIO_PIN_RESET);
		microDelay(delay);
	}
	printf("Posle for stepMotorVector!!! \n");
}
//------------------------------------------------------------------------------------------
void stepMotorUpDown(uint32_t steps, uint8_t direction, uint16_t delay)
{
	uint32_t k;
	if (direction == 0)
		HAL_GPIO_WritePin(DIR_PORT_3, DIR_PIN_3, GPIO_PIN_SET);
	else
		HAL_GPIO_WritePin(DIR_PORT_3, DIR_PIN_3, GPIO_PIN_RESET);

	for(k = 0; k < steps; k++)
	{
		HAL_GPIO_WritePin(STEP_PORT_3, STEP_PIN_3, GPIO_PIN_SET);
		microDelay(delay);
    	HAL_GPIO_WritePin(STEP_PORT_3, STEP_PIN_3, GPIO_PIN_RESET);
    	microDelay(delay);
	}
}
//------------------------------------------------------------------------------------------
void convertStepsAndCommand(uint8_t *data, uint16_t *steps, uint8_t *command)
{
    *command = (data[1] & MASK_FOR_COMMAND)>>4;
    *steps = ((data[1] & MASK_FOR_STEPS)<<8) | data[0];
}
//------------------------------------------------------------------------------------------
void commandHandler(uint16_t steps, uint8_t command)
{
	switch (command) {
	case CMD_MOVE_TO_STARTING_POINT:
		/*
		 * no limit switches in the prototype yet
		 * */
		printf("Case CMD_MOVE_TO_STARTING_POINT!!! \n");
	  break;
	case CMD_UP_THE_NEEDLE:
		printf("Case CMD_UP_THE_NEEDLE!!! \n");
		//stepMotorUpDown(steps, UP, SPEED_DELAY_FOR_UP_DOWN);
	  break;
	case CMD_DOWN_THE_NEEDLE:
		printf("Case CMD_DOWN_THE_NEEDLE!!! \n");
		//stepMotorUpDown(steps, DOWN, SPEED_DELAY_FOR_UP_DOWN);
	  break;
	case CMD_ROTATION_CLOCKWISE:
		printf("Case CMD_ROTATION_CLOCKWISE!!! \n");
		//stepMotorRotation(steps, ROTATION_CLOCKWISE, SPEED_DELAY_FOR_ROTATION);
	  break;
	case CMD_ROTATION_ANTICLOCKWISE:
		printf("Case CMD_ROTATION_ANTICLOCKWISE!!! \n");
		//stepMotorRotation(steps, ROTATION_ANTICLOCKWISE, SPEED_DELAY_FOR_ROTATION);
	  break;
	case CMD_MOVE_TO_CENTER:
		printf("Case CMD_MOVE_TO_CENTER!!! \n");
		//stepMotorVector(steps, MOVE_TO_CENTER, SPEED_DELAY_FOR_VECTOR);
	  break;
	case CMD_MOVE_FROM_CENTER:
		printf("Case CMD_MOVE_FROM_CENTER!!! \n");
		//stepMotorVector(steps, MOVE_FROM_CENTER, SPEED_DELAY_FOR_VECTOR);
	  break;
	case CMD_END_PROGRAMM:
		/*
		 *
		 * */
	  break;
	}
}
//------------------------------------------------------------------------------------------
