####################################################
# 1、配置编译相关参数、编译文件(夹)、目标及中间文件
####################################################

# 定义生成目标，包括其路径及文件名【只能是一个对象】
TARGET = ../build/objs/app.exe

# 定义中间文件夹，用于存放中间文件【只能是一个对象】
OBJS_D = ../build/objs

# 添加编译源文件，包括路径及文件名【多个用空格分隔】
SRCS_F = ../app/main.c                            \
         ../usr/hello.c                           \
         ../usr/test.c

# 添加编译文件夹，要指定文件扩展名【多个用空格分隔】
SRCS_D = ../modules/led/*.c

# 添加编译库文件，包括路径及文件名【多个用空格分隔】
LIBS_F = ../build/libs/delay.a

# 添加源码文件及包含文件所在的路径【多个用空格分隔】
SRCS_I = ../app                                   \
         ../usr/                                  \
         ../modules/led/                          \
         ../modules/delay

# 定义编译器及其环境相关参数
include ../makeenvi.mk
CFLAG_O += -W -Wall

# 包含[Makefile]脚本公共代码
include ../makecore.mk

