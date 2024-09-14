/*
 * Stepper_Motor_Defs.h
 *
 *  Created on: Sep 13, 2024
 *      Author: kunal
 */

#ifndef STEPPER_MOTOR_DEFS_H_
#define STEPPER_MOTOR_DEFS_H_

#include "main.h"

static const struct Stepper_Motor_Configuration
{
	struct Control{
		bool Enable;
		bool Disable;
	}Control;

	struct Step_Mode{
		uint8_t Full_Step;
		uint8_t Half_Step;
		uint8_t _1_4_Step;
	}Step_Mode;

	struct Direction{
		uint8_t Forward;
		uint8_t Backward;
	}Direction;

	uint32_t Full_Step_Sequence[4];
	uint32_t Half_Step_Sequence[8];
	uint32_t _1_4_Step_Sequence[12];


}Stepper_Motor_Configuration = {

		.Control = {
			.Enable = 1,
			.Disable = 2,
		},

		.Step_Mode = {
				.Full_Step = 1,
				.Half_Step = 2,
				._1_4_Step = 3,
		},

		.Direction = {
				.Forward = 1,
				.Backward = 2,
		},

		.Full_Step_Sequence = {0xFFFE0001, 0xFFFD0002, 0xFFFB0004, 0xFFF70008},

		.Half_Step_Sequence = {0xFFFE0001, 0xFFFA0005, 0xFFFB0004, 0xFFF90006, 0xFFFD0002, 0xFFF5000A, 0xFFF70008,0xFFF60009},


};


#endif /* STEPPER_MOTOR_DEFS_H_ */
