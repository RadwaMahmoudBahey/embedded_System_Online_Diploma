################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_F1033C6_Drivers/KEYPAD_DRIVER/KPD.c 

OBJS += \
./STM32_F1033C6_Drivers/KEYPAD_DRIVER/KPD.o 

C_DEPS += \
./STM32_F1033C6_Drivers/KEYPAD_DRIVER/KPD.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_F1033C6_Drivers/KEYPAD_DRIVER/KPD.o: ../STM32_F1033C6_Drivers/KEYPAD_DRIVER/KPD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/Radwa_RTOS/inc" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/CMSIS_V5" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F1033C6_Drivers/inc" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F1033C6_Drivers/LCD_DRIVER" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F1033C6_Drivers/KEYPAD_DRIVER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_F1033C6_Drivers/KEYPAD_DRIVER/KPD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

