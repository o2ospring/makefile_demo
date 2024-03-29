####################################################
# 1、定义编译器及环境公共参数，方便不同环境/平台移植
####################################################

CC = gcc
AR = ar
RM = rm
CFLAG_L = 
CFLAG_O = -c
CFLAG_M = -MMD -MP -MF"$(@:%.o=%.d)"
ARFLAGS = rcs
RMFLAGS = -fr
MKDIR   = mkdir -p
#ECHO_SET = @set -e
#ECHO_END = 
VPATH  := $(SRCS_I)
SRCS_I := $(addprefix -I,$(SRCS_I) $(dir $(SRCS_F) $(SRCS_D)))

ifdef DEBUG
ifneq ($(DEBUG),0)
CFLAG_O += -g
endif
endif

ifdef TARGET
DEBUG_CMD = cgdb -d gdb -ex 'file $(TARGET)' -ex 'tb main' -ex 'r'
endif

