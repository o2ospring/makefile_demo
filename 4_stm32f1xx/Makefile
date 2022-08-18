.PHONY: all clean echo
include envi.rule

####################################################
# 0、专门为【STM32Fxxx】应用工程增加的参数配置。
####################################################

# 添加全局宏定义,作用于整个项目工程【多个用空格分隔】
# STM32F103芯片选择: STM32F103x6,STM32F103xB,STM32F103xE,STM32F103xG
export G_DEF  = USE_HAL_DRIVER                     \
                STM32F103xB

# 添加链接器脚本文件，要路径+文件名【只能是一个对象】
# xxx.ld复制来源: HAL库\Drivers\CMSIS\Device\ST\STM32F1xx\Source\Templates\gcc
export ROOT = $(realpath .)
export LD_SCF = $(ROOT)/STM32F103XB_FLASH.ld

# 开启编译调试信息（不定义表示关闭）
export DEBUG  = 

####################################################
# 1、定义子 Makefile 文件所在路径。【多个用空格分隔】
####################################################

# 注意: 唯一生成执行文件的子 Makefile 必须放到最后面
MAKEFILE_D = modules/delay                         \
             Core/Src

####################################################
# 2、整理子 Makefile 文件路径信息。通过几个函数整理
#    为方便之后生成命令字符串准备，例如整理为：
#    cd modules/crc// cd app//
####################################################

MAKEFILE_CALL := $(addsuffix /,$(MAKEFILE_D))
MAKEFILE_CALL := $(subst //,/,$(MAKEFILE_CALL))
MAKEFILE_CALL := $(addsuffix /,$(MAKEFILE_CALL))
MAKEFILE_CALL := $(addprefix cd////,$(MAKEFILE_CALL))
MAKEFILE_CALL := $(subst cd////,@cd ,$(MAKEFILE_CALL))
# 定义【换行+Tab格】
define LFTAB

	
endef

####################################################
# 3、调用子 Makefile 文件执行命令。使用字符串函数的
#    替换功能生成对应的命令字符串，例如生成为：
#    @cd modules/crc && $(MAKE) all
#    @cd app         && $(MAKE) all
####################################################

all:
	$(subst //, && $(MAKE) all$(LFTAB),$(MAKEFILE_CALL))
	@echo "+-----o2ospring-------------+"
	@echo "| :-) completed.            |"
	@echo "+---------------------------+"

clean:
	$(subst //, && $(MAKE) clean$(LFTAB),$(MAKEFILE_CALL))

echo:
	$(subst //, && $(MAKE) echo$(LFTAB),$(MAKEFILE_CALL))

