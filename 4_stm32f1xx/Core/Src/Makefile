####################################################
# 1、配置编译相关参数、编译文件(夹)、目标及中间文件
####################################################

# 定义生成目标，包括其路径及文件名【只能是一个对象】
TARGET = $(ROOT)/build/stm32f1xx

# 定义中间文件夹，用于存放中间文件【只能是一个对象】
OBJS_D = $(ROOT)/build/

# 添加编译源文件，包括路径及文件名【多个用空格分隔】
# xxx.s复制来源: HAL库\Drivers\CMSIS\Device\ST\STM32F1xx\Source\Templates\gcc
SRCS_F = $(ROOT)/startup_stm32f103xb.s                                     \
         $(ROOT)/Core/Src/main.c                                           \
         $(ROOT)/Core/Src/stm32f1xx_it.c                                   \
         $(ROOT)/Core/Src/stm32f1xx_hal_msp.c                              \
         $(ROOT)/Core/Src/system_stm32f1xx.c                               \
         $(ROOT)/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.c  \
         $(ROOT)/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.c      \
         $(ROOT)/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.c   \
         $(ROOT)/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c          \
         $(ROOT)/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.c      \
         $(ROOT)/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.c   \
         $(ROOT)/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.c     \
         $(ROOT)/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c      \
         $(ROOT)/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c   \
         $(ROOT)/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.c      \
         $(ROOT)/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.c    \
         $(ROOT)/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.c \
         $(ROOT)/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.c

# 添加编译文件夹，要指定文件扩展名【多个用空格分隔】
SRCS_D = $(ROOT)/modules/led/*.c

# 添加编译库文件，包括路径及文件名【多个用空格分隔】
LIBS   = $(ROOT)/build/libs/delay.a

# 添加源码文件及包含文件所在的路径【多个用空格分隔】
VPATH  = $(ROOT)/                                 \
         $(ROOT)/Core/Src                         \
         $(ROOT)/Core/Inc                         \
         $(ROOT)/Drivers/STM32F1xx_HAL_Driver/Src \
         $(ROOT)/Drivers/STM32F1xx_HAL_Driver/Inc \
         $(ROOT)/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy   \
         $(ROOT)/Drivers/CMSIS/Device/ST/STM32F1xx/Include \
         $(ROOT)/Drivers/CMSIS/Include            \
         $(ROOT)/modules/delay                    \
         $(ROOT)/modules/led

# 定义编译器及其环境相关参数
include $(ROOT)/envi.rule
CFLAG_O += -Wall -Og

# 包含[Makefile]脚本公共代码
include $(ROOT)/make.rule

