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


void Stepper_Motor_HAL_Init(void);
void Stepper_Motor_HAL_Set_Speed(void);
void Stepper_Motor_HAL_Step(void);




#endif /* STEPPER_MOTOR_HAL_STEPPER_MOTOR_HAL_H_ */
