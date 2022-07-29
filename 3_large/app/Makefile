####################################################
# 1、配置编译相关参数、编译文件(夹)、目标及中间文件
####################################################

# 定义生成文件，包括其路径及文件名【只能是一个对象】
EXE    = $(ROOT)/build/objs/exec

# 定义中间文件夹，用于存放中间文件【只能是一个对象】
OBJS_D = $(ROOT)/build/objs

# 添加编译源文件，包括路径及文件名【多个用空格分隔】
SRCS_F = $(ROOT)/app/main.c                       \
         $(ROOT)/usr/hello.c                      \
         $(ROOT)/usr/test.c

# 添加编译文件夹，要指定文件扩展名【多个用空格分隔】
SRCS_D = $(ROOT)/modules/md5/*.c

# 添加编译库文件，包括路径及文件名【多个用空格分隔】
LIBS   = $(ROOT)/build/libs/crc.a

# 添加源码文件及包含文件所在的路径【多个用空格分隔】
VPATH  = $(ROOT)/app                             \
         $(ROOT)/usr                             \
         $(ROOT)/modules/md5                     \
         $(ROOT)/modules/crc

# 定义编译器及其环境相关参数
include $(ROOT)/envi.rule

# 包含[Makefile]脚本公共代码
include $(ROOT)/make.rule

