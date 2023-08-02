/*
 * SteppLibrary.h
 *
 *  Created on: Dec 8, 2022
 *      Author: feodosiy
 */

#ifndef INC_STEPPLIBRARY_H_
#define INC_STEPPLIBRARY_H_

//******************INCLUDES************************
#include "stm32h7xx_hal.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


//******************DEFINES************************
/*--------Motor №1 -- ROTATION MOTOR---------------*/
#define EN_PIN_1 GPIO_PIN_2
#define EN_PORT_1 GPIOG

#define MS1_PIN_1 GPIO_PIN_3
#define MS1_PORT_1 GPIOG

#define STEP_PIN_1 GPIO_PIN_4
#define STEP_PORT_1 GPIOD

#define DIR_PIN_1 GPIO_PIN_3
#define DIR_PORT_1 GPIOD

#define stepsMotorRotate 8232
#define ROTATION_CLOCKWISE 1
#define ROTATION_ANTICLOCKWISE 0
#define SPEED_DELAY_FOR_ROTATION 1000
//-------------------------------------------------


/*--------Motor №2 -- VECTOR MOTOR---------------*/
#define EN_PIN_2 GPIO_PIN_4
#define EN_PORT_2 GPIOE

#define MS1_PIN_2 GPIO_PIN_5
#define MS1_PORT_2 GPIOE

#define MS2_PIN_2 GPIO_PIN_6
#define MS2_PORT_2 GPIOE

#define STEP_PIN_2 GPIO_PIN_9
#define STEP_PORT_2 GPIOF

#define DIR_PIN_2 GPIO_PIN_1
#define DIR_PORT_2 GPIOG

#define MOVE_TO_CENTER 1
#define MOVE_FROM_CENTER 0
#define SPEED_DELAY_FOR_VECTOR 1000
//-------------------------------------------------


/*--------Motor №3 -- UP DOWN MOTOR---------------*/
#define EN_PIN_3 GPIO_PIN_7
#define EN_PORT_3 GPIOB

#define RST_PIN_3 GPIO_PIN_14
#define RST_PORT_3 GPIOE

#define SLEEP_PIN_3 GPIO_PIN_11
#define SLEEP_PORT_3 GPIOE

#define CFG1_PIN_3 GPIO_PIN_6
#define CFG1_PORT_3 GPIOB

#define CFG2_PIN_3 GPIO_PIN_14
#define CFG2_PORT_3 GPIOG

#define CFG3_PIN_3 GPIO_PIN_13
#define CFG3_PORT_3 GPIOE

#define STEP_PIN_3 GPIO_PIN_9
#define STEP_PORT_3 GPIOE

#define DIR_PIN_3 GPIO_PIN_15
#define DIR_PORT_3 GPIOD

#define UP 1
#define DOWN 0
#define SPEED_DELAY_FOR_UP_DOWN 1000
//-------------------------------------------------

//----------Recieve and handling data--------------
#define MASK_FOR_COMMAND 0xF0
#define MASK_FOR_STEPS 0x0F
//-------------------------------------------------

//------------Commands from phone------------------
#define CMD_MOVE_TO_STARTING_POINT 0x0F
#define CMD_UP_THE_NEEDLE 0x0C
#define CMD_DOWN_THE_NEEDLE 0x03
#define CMD_ROTATION_CLOCKWISE 0x0A
#define CMD_ROTATION_ANTICLOCKWISE 0x05
#define CMD_MOVE_TO_CENTER 0x06
#define CMD_MOVE_FROM_CENTER 0x09
#define CMD_END_PROGRAMM 0x00
//-------------------------------------------------

#endif /* INC_STEPPLIBRARY_H_ */

//******************FUNCTIONS************************
void microDelay(uint16_t delay);
void stepMotorRotation(uint32_t steps, uint8_t direction, uint16_t delay);
void stepMotorVector(uint32_t steps, uint8_t direction, uint16_t delay);
void stepMotorUpDown(uint32_t steps, uint8_t direction, uint16_t delay);
void convertStepsAndCommand(uint8_t *data, uint16_t *steps, uint8_t *command);
void commandHandler(uint16_t steps, uint8_t command);
//***************************************************

