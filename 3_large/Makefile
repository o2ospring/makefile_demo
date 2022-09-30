export ROOT = $(realpath .)
.PHONY: all clean echo debug
include envi.rule

####################################################
# 1、定义子 Makefile 文件所在路径。【多个用空格分隔】
####################################################

# 注意: 唯一生成执行文件的子 Makefile 必须放到最后面
MAKEFILE_D = modules/delay                         \
             app

# 开启编译调试信息（不定义或定义为0表示关闭）
export DEBUG = 1

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

debug:
	$(subst //, && $(MAKE) debug$(LFTAB),$(MAKEFILE_CALL))

