.PHONY: all clean echo
export ROOT = $(realpath .)
include $(ROOT)/envi.rule

####################################################
# 1、定义子 Makefile 文件所在路径。【多个用空格分隔】
####################################################

# 注意: 唯一生成执行文件的子 Makefile 必须放到最后面
MAKEFILE_D = $(ROOT)/modules/crc                   \
             $(ROOT)/app

####################################################
# 2、整理子 Makefile 文件路径信息。通过几个函数整理
#    为方便之后生成命令字符串准备，例如整理为：
#    cd $(ROOT)/modules/crc// cd $(ROOT)/app//
####################################################

MAKEFILE_CALL := $(addsuffix /,$(MAKEFILE_D))
MAKEFILE_CALL := $(subst //,/,$(MAKEFILE_CALL))
MAKEFILE_CALL := $(addsuffix /,$(MAKEFILE_CALL))
MAKEFILE_CALL := $(addprefix cd////,$(MAKEFILE_CALL))
MAKEFILE_CALL := $(subst cd////,cd ,$(MAKEFILE_CALL))

####################################################
# 3、调用子 Makefile 文件执行命令。使用字符串函数的
#    替换功能生成对应的命令字符串，例如生成为：
#    cd $(ROOT)/modules/crc && $(MAKE) all; \
#    cd $(ROOT)/app         && $(MAKE) all;
####################################################

all:
	$(ECHO_SET); \
	$(subst //, && $(MAKE) all;,$(MAKEFILE_CALL)) \
	$(ECHO_END)
	@echo "+-----o2ospring-------------+"
	@echo "| :-) completed.            |"
	@echo "+---------------------------+"

clean:
	$(ECHO_SET); \
	$(subst //, && $(MAKE) clean;,$(MAKEFILE_CALL)) \
	$(ECHO_END)

echo:
	$(ECHO_SET); \
	$(subst //, && $(MAKE) echo;,$(MAKEFILE_CALL)) \
	$(ECHO_END)

