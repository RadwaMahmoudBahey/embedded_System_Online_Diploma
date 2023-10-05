################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f103c6tx.s 

OBJS += \
./Startup/startup_stm32f103c6tx.o 

S_DEPS += \
./Startup/startup_stm32f103c6tx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/startup_stm32f103c6tx.o: ../Startup/startup_stm32f103c6tx.s
	arm-none-eabi-gcc -gdwarf-2 -mcpu=cortex-m3 -g3 -c -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/Radwa_RTOS/inc" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F1033C6_Drivers/KEYPAD_DRIVER" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/CMSIS_V5" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F1033C6_Drivers/inc" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F1033C6_Drivers/LCD_DRIVER" -x assembler-with-cpp -MMD -MP -MF"Startup/startup_stm32f103c6tx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

