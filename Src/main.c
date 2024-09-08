/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "main.h"
#include "DMA.h"
#include "GPIO.h"


DMA_Config Stepper_Motor_1;

uint32_t signal1[10];


int main(void)
{
	MCU_Clock_Setup();
	Delay_Config();

	GPIO_Pin_Init(GPIOA, 0, GPIO_Configuration.Mode.General_Purpose_Output, GPIO_Configuration.Output_Type.Push_Pull, GPIO_Configuration.Speed.Very_High_Speed, GPIO_Configuration.Pull.No_Pull_Up_Down, GPIO_Configuration.Alternate_Functions.None);
	GPIO_Pin_Init(GPIOA, 1, GPIO_Configuration.Mode.General_Purpose_Output, GPIO_Configuration.Output_Type.Push_Pull, GPIO_Configuration.Speed.Very_High_Speed, GPIO_Configuration.Pull.No_Pull_Up_Down, GPIO_Configuration.Alternate_Functions.None);
	GPIO_Pin_Init(GPIOA, 2, GPIO_Configuration.Mode.General_Purpose_Output, GPIO_Configuration.Output_Type.Push_Pull, GPIO_Configuration.Speed.Very_High_Speed, GPIO_Configuration.Pull.No_Pull_Up_Down, GPIO_Configuration.Alternate_Functions.None);
	GPIO_Pin_Init(GPIOA, 3, GPIO_Configuration.Mode.General_Purpose_Output, GPIO_Configuration.Output_Type.Push_Pull, GPIO_Configuration.Speed.Very_High_Speed, GPIO_Configuration.Pull.No_Pull_Up_Down, GPIO_Configuration.Alternate_Functions.None);
	GPIO_Pin_Init(GPIOA, 4, GPIO_Configuration.Mode.General_Purpose_Output, GPIO_Configuration.Output_Type.Push_Pull, GPIO_Configuration.Speed.Very_High_Speed, GPIO_Configuration.Pull.No_Pull_Up_Down, GPIO_Configuration.Alternate_Functions.None);
	GPIO_Pin_Init(GPIOA, 5, GPIO_Configuration.Mode.General_Purpose_Output, GPIO_Configuration.Output_Type.Push_Pull, GPIO_Configuration.Speed.Very_High_Speed, GPIO_Configuration.Pull.No_Pull_Up_Down, GPIO_Configuration.Alternate_Functions.None);

	uint32_t temp1 = 0;
	uint32_t temp2 = 0;

	temp1 = 0b001001;
	temp2 = ~temp1 & 0b111111;
	signal1[0] = temp2 << 16 | temp1;

	temp1 = 0b100001;
	temp2 = ~temp1 & 0b111111;
	signal1[1] = (temp2 << 16) | temp1;

	temp1 = 0b100100;
	temp2 = ~temp1 & 0b111111;
	signal1[2] = (temp2 << 16) | temp1;

	temp1 = 0b000110;
	temp2 = ~temp1 & 0b111111;
	signal1[3] = (temp2 << 16) | temp1;

	temp1 = 0b010010;
	temp2 = ~temp1 & 0b111111;
	signal1[4] = (temp2 << 16) | temp1;

	temp1 = 0b011000;
	temp2 = ~temp1 & 0b111111;
	signal1[5] = (temp2 << 16) | temp1;


	RCC -> APB2ENR |= RCC_APB2ENR_TIM1EN;
	TIM1 -> PSC = 16800;
	TIM1 -> ARR = 1000;
	TIM1 -> DIER |= TIM_DIER_UDE;

	Stepper_Motor_1.Request = DMA_Configuration.Request.TIM1_UP;
	Stepper_Motor_1.buffer_length = 6;
	Stepper_Motor_1.circular_mode = DMA_Configuration.Circular_Mode.Enable;
	Stepper_Motor_1.flow_control = DMA_Configuration.Flow_Control.DMA_Control;
	Stepper_Motor_1.interrupts = DMA_Configuration.DMA_Interrupts.Transfer_Complete;
	Stepper_Motor_1.memory_address = (uint32_t)&signal1[0];
	Stepper_Motor_1.memory_data_size = DMA_Configuration.Memory_Data_Size.word;
	Stepper_Motor_1.memory_pointer_increment = DMA_Configuration.Memory_Pointer_Increment.Enable;
	Stepper_Motor_1.peripheral_address = (uint32_t)&(GPIOA->BSRR);
	Stepper_Motor_1.peripheral_data_size = DMA_Configuration.Peripheral_Data_Size.word;
	Stepper_Motor_1.peripheral_pointer_increment = DMA_Configuration.Peripheral_Pointer_Increment.Disable;
	Stepper_Motor_1.priority_level = DMA_Configuration.Priority_Level.Very_high;
	Stepper_Motor_1.transfer_direction = DMA_Configuration.Transfer_Direction.Memory_to_peripheral;

	DMA_Init(&Stepper_Motor_1);
	DMA_Set_Target(&Stepper_Motor_1);
	DMA_Set_Trigger(&Stepper_Motor_1);

	TIM1 -> CR1 |= TIM_CR1_CEN;



    /* Loop forever */
	for(;;)
	{

	}
}
