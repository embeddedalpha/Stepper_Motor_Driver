/*
 * Stepper_Motor_HAL.h
 *
 *  Created on: Sep 9, 2024
 *      Author: kunal
 */

#ifndef STEPPER_MOTOR_HAL_STEPPER_MOTOR_HAL_H_
#define STEPPER_MOTOR_HAL_STEPPER_MOTOR_HAL_H_

#include "main.h"
#include "GPIO.h"
#include "Stepper_Motor_Defs.h"

#define STEP_MODE_FULL_STEP 4
#define STEP_MODE_HALF_STEP 7

typedef struct Stepper_Motor_Typedef{
	bool Control;
	uint8_t  Step_Mode;
	uint8_t  Direction;
	uint16_t RPM;
	uint16_t Final_Step;
	uint16_t Last_Step;
	uint8_t Step;
}Stepper_Motor_Typedef;

Stepper_Motor_Typedef Stepper_Motor_1;
Stepper_Motor_Typedef Stepper_Motor_2;
Stepper_Motor_Typedef Stepper_Motor_3;
Stepper_Motor_Typedef Stepper_Motor_4;



void Stepper_Motor_HAL_Init(void);
void Stepper_Motor_Run(bool Direction, uint16_t Speed_RPM);
void Stepper_Motor_HAL_Set_Speed(uint16_t RPM);
void Stepper_Motor_HAL_Step(uint8_t steps);
void Stepper_Motor_HAL_Stop(void);




#endif /* STEPPER_MOTOR_HAL_STEPPER_MOTOR_HAL_H_ */
