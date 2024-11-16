/*
 * BSP.c
 *
 *  Created on: Aug 30, 2024
 *      Author: kunal
 */


#include "main.h"
#include "GPIO.h"

void BSP_Init(void)
{



	GPIO_Pin_Init(GPIOD, 12,
			GPIO_Configuration.Mode.General_Purpose_Output,
			GPIO_Configuration.Output_Type.Push_Pull,
			GPIO_Configuration.Speed.Very_High_Speed,
			GPIO_Configuration.Pull.No_Pull_Up_Down,
			GPIO_Configuration.Alternate_Functions.None);

	GPIO_Pin_Init(GPIOD, 13,
			GPIO_Configuration.Mode.General_Purpose_Output,
			GPIO_Configuration.Output_Type.Push_Pull,
			GPIO_Configuration.Speed.Very_High_Speed,
			GPIO_Configuration.Pull.No_Pull_Up_Down,
			GPIO_Configuration.Alternate_Functions.None);

	GPIO_Pin_Init(GPIOD, 14,
			GPIO_Configuration.Mode.General_Purpose_Output,
			GPIO_Configuration.Output_Type.Push_Pull,
			GPIO_Configuration.Speed.Very_High_Speed,
			GPIO_Configuration.Pull.No_Pull_Up_Down,
			GPIO_Configuration.Alternate_Functions.None);

	GPIO_Pin_Init(GPIOD, 15,
			GPIO_Configuration.Mode.General_Purpose_Output,
			GPIO_Configuration.Output_Type.Push_Pull,
			GPIO_Configuration.Speed.Very_High_Speed,
			GPIO_Configuration.Pull.No_Pull_Up_Down,
			GPIO_Configuration.Alternate_Functions.None);
}
