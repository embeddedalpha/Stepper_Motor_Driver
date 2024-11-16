################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stepper_Motor/Stepper_Motor_HAL/Stepper_Motor_HAL.c 

OBJS += \
./Stepper_Motor/Stepper_Motor_HAL/Stepper_Motor_HAL.o 

C_DEPS += \
./Stepper_Motor/Stepper_Motor_HAL/Stepper_Motor_HAL.d 


# Each subdirectory must supply rules for building sources it contributes
Stepper_Motor/Stepper_Motor_HAL/%.o Stepper_Motor/Stepper_Motor_HAL/%.su Stepper_Motor/Stepper_Motor_HAL/%.cyclo: ../Stepper_Motor/Stepper_Motor_HAL/%.c Stepper_Motor/Stepper_Motor_HAL/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"B:/STM32F407V_Firmware_C_Lang/Stepper_Motor_Driver/Console" -I"B:/STM32F407V_Firmware_C_Lang/Stepper_Motor_Driver/DMA" -I"B:/STM32F407V_Firmware_C_Lang/Stepper_Motor_Driver/GPIO" -I"B:/STM32F407V_Firmware_C_Lang/Stepper_Motor_Driver/USART" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Stepper_Motor-2f-Stepper_Motor_HAL

clean-Stepper_Motor-2f-Stepper_Motor_HAL:
	-$(RM) ./Stepper_Motor/Stepper_Motor_HAL/Stepper_Motor_HAL.cyclo ./Stepper_Motor/Stepper_Motor_HAL/Stepper_Motor_HAL.d ./Stepper_Motor/Stepper_Motor_HAL/Stepper_Motor_HAL.o ./Stepper_Motor/Stepper_Motor_HAL/Stepper_Motor_HAL.su

.PHONY: clean-Stepper_Motor-2f-Stepper_Motor_HAL

