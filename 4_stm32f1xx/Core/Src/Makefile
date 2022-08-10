####################################################
# 1、配置编译相关参数、编译文件(夹)、目标及中间文件
####################################################

# 定义生成目标，包括其路径及文件名【只能是一个对象】
TARGET = ../../build/objs/stm32f1xx

# 定义中间文件夹，用于存放中间文件【只能是一个对象】
OBJS_D = ../../build/objs

# 添加编译源文件，包括路径及文件名【多个用空格分隔】
# xxx.s复制来源: HAL库\Drivers\CMSIS\Device\ST\STM32F1xx\Source\Templates\gcc
SRCS_F = ../../startup_stm32f103xb.s                                     \
         ../../Core/Src/main.c                                           \
         ../../Core/Src/stm32f1xx_it.c                                   \
         ../../Core/Src/stm32f1xx_hal_msp.c                              \
         ../../Core/Src/system_stm32f1xx.c                               \
         ../../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.c  \
         ../../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.c      \
         ../../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.c   \
         ../../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c          \
         ../../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.c      \
         ../../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.c   \
         ../../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.c     \
         ../../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c      \
         ../../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c   \
         ../../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.c      \
         ../../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.c    \
         ../../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.c \
         ../../Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.c

# 添加编译文件夹，要指定文件扩展名【多个用空格分隔】
SRCS_D = ../../modules/led/*.c

# 添加编译库文件，包括路径及文件名【多个用空格分隔】
LIBS   = ../../build/libs/delay.a

# 添加源码文件及包含文件所在的路径【多个用空格分隔】
VPATH  = ../../                                   \
         ../../Core/Src                           \
         ../../Core/Inc                           \
         ../../Drivers/STM32F1xx_HAL_Driver/Src   \
         ../../Drivers/STM32F1xx_HAL_Driver/Inc   \
         ../../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy   \
         ../../Drivers/CMSIS/Device/ST/STM32F1xx/Include \
         ../../Drivers/CMSIS/Include              \
         ../../modules/delay                      \
         ../../modules/led

# 定义编译器及其环境相关参数
include ../../envi.rule
CFLAG_O += -Wall -Og

# 包含[Makefile]脚本公共代码
include ../../make.rule

