/*
 * Stepper_Motor_HAL.c
 *
 *  Created on: Sep 9, 2024
 *      Author: kunal
 */


#include "Stepper_Motor_HAL.h"



void TIM6_DAC_IRQHandler(void)
{
	TIM6 -> SR &= ~TIM_SR_UIF;




	if(Stepper_Motor_1.Control == Stepper_Motor_Configuration.Control.Enable)
	{
		if(Stepper_Motor_1.Direction == Stepper_Motor_Configuration.Direction.Forward)
		{
			if(Stepper_Motor_1.Step_Mode == Stepper_Motor_Configuration.Step_Mode.Full_Step)
			{
				if(Stepper_Motor_1.Last_Step < Stepper_Motor_1.Final_Step)
				{
					GPIOA -> BSRR = Stepper_Motor_Configuration.Full_Step_Sequence[Stepper_Motor_1.Step % 4];
					Stepper_Motor_1.Last_Step +=1;
					Stepper_Motor_1.Step += 1;
				}
				else
				{
					Stepper_Motor_1.Step = 0;
					Stepper_Motor_1.Control = Stepper_Motor_Configuration.Control.Disable;
				}
			}
			else if(Stepper_Motor_1.Step_Mode == Stepper_Motor_Configuration.Step_Mode.Half_Step)
			{
				if(Stepper_Motor_1.Last_Step < Stepper_Motor_1.Final_Step)
				{
					GPIOA -> BSRR = Stepper_Motor_Configuration.Half_Step_Sequence[Stepper_Motor_1.Step % 8];
					Stepper_Motor_1.Last_Step +=1;
					Stepper_Motor_1.Step += 1;
				}
				else
				{
					Stepper_Motor_1.Step = 0;
					Stepper_Motor_1.Control = Stepper_Motor_Configuration.Control.Disable;
				}
			}
			else if(Stepper_Motor_1.Step_Mode == Stepper_Motor_Configuration.Step_Mode._1_4_Step)
			{
				if(Stepper_Motor_1.Last_Step < Stepper_Motor_1.Final_Step)
				{
					GPIOA -> BSRR = Stepper_Motor_Configuration._1_4_Step_Sequence[Stepper_Motor_1.Step % 12];
					Stepper_Motor_1.Last_Step +=1;
					Stepper_Motor_1.Step += 1;
				}
				else
				{
					Stepper_Motor_1.Step = 0;
					Stepper_Motor_1.Control = Stepper_Motor_Configuration.Control.Disable;
				}
			}
		}
		else if(Stepper_Motor_1.Direction == Stepper_Motor_Configuration.Direction.Backward)
		{

		}




	}

}


void Stepper_Motor_HAL_Init(void)
{

	// 1A
	GPIO_Pin_Init(GPIOA, 0, GPIO_Configuration.Mode.General_Purpose_Output,
							GPIO_Configuration.Output_Type.Push_Pull,
							GPIO_Configuration.Speed.Very_High_Speed,
							GPIO_Configuration.Pull.No_Pull_Up_Down,
							GPIO_Configuration.Alternate_Functions.None);

	// 1B
	GPIO_Pin_Init(GPIOA, 1, GPIO_Configuration.Mode.General_Purpose_Output,
							GPIO_Configuration.Output_Type.Push_Pull,
							GPIO_Configuration.Speed.Very_High_Speed,
							GPIO_Configuration.Pull.No_Pull_Up_Down,
							GPIO_Configuration.Alternate_Functions.None);

	// 2A
	GPIO_Pin_Init(GPIOA, 2, GPIO_Configuration.Mode.General_Purpose_Output,
							GPIO_Configuration.Output_Type.Push_Pull,
							GPIO_Configuration.Speed.Very_High_Speed,
							GPIO_Configuration.Pull.No_Pull_Up_Down,
							GPIO_Configuration.Alternate_Functions.None);

	// 2B
	GPIO_Pin_Init(GPIOA, 3, GPIO_Configuration.Mode.General_Purpose_Output,
							GPIO_Configuration.Output_Type.Push_Pull,
							GPIO_Configuration.Speed.Very_High_Speed,
							GPIO_Configuration.Pull.No_Pull_Up_Down,
							GPIO_Configuration.Alternate_Functions.None);


	NVIC_DisableIRQ(TIM6_DAC_IRQn);
	RCC -> APB1ENR |= RCC_APB1ENR_TIM6EN;
	TIM6 -> EGR |= TIM_EGR_UG;
	TIM6->CR1 |= TIM_CR1_URS;
	TIM6->DIER |=  TIM_DIER_UIE;
}
void Stepper_Motor_HAL_Set_Speed(uint16_t RPM)
{
	NVIC_DisableIRQ(TIM6_DAC_IRQn);

	uint16_t PPS = 0;
	PPS = (RPM * 200)/60;
	if(PPS < 400)
	{
		TIM6->PSC =8400-1;
	}
	else
	{
		TIM6->PSC =840-1;
	}
	TIM6->ARR = PPS;
	TIM6->CR1 |= TIM_CR1_CEN;

	NVIC_SetPriority(TIM6_DAC_IRQn,1);
	NVIC_EnableIRQ(TIM6_DAC_IRQn);
}


void Stepper_Motor_HAL_Step(uint8_t steps)
{

}
