################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Radwa_RTOS/Circular_FIFO.c \
../Radwa_RTOS/CortexMX_porting.c \
../Radwa_RTOS/Scheduler.c 

OBJS += \
./Radwa_RTOS/Circular_FIFO.o \
./Radwa_RTOS/CortexMX_porting.o \
./Radwa_RTOS/Scheduler.o 

C_DEPS += \
./Radwa_RTOS/Circular_FIFO.d \
./Radwa_RTOS/CortexMX_porting.d \
./Radwa_RTOS/Scheduler.d 


# Each subdirectory must supply rules for building sources it contributes
Radwa_RTOS/Circular_FIFO.o: ../Radwa_RTOS/Circular_FIFO.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/Radwa_RTOS/inc" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/CMSIS_V5" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F1033C6_Drivers/inc" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F1033C6_Drivers/LCD_DRIVER" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F1033C6_Drivers/KEYPAD_DRIVER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Radwa_RTOS/Circular_FIFO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Radwa_RTOS/CortexMX_porting.o: ../Radwa_RTOS/CortexMX_porting.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/Radwa_RTOS/inc" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/CMSIS_V5" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F1033C6_Drivers/inc" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F1033C6_Drivers/LCD_DRIVER" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F1033C6_Drivers/KEYPAD_DRIVER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Radwa_RTOS/CortexMX_porting.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Radwa_RTOS/Scheduler.o: ../Radwa_RTOS/Scheduler.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/Radwa_RTOS/inc" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/CMSIS_V5" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F1033C6_Drivers/inc" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F1033C6_Drivers/LCD_DRIVER" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.0/Drivers/STM32_F1033C6_Drivers/KEYPAD_DRIVER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Radwa_RTOS/Scheduler.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

