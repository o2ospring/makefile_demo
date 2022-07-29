.PHONY: all clean echo
include $(ROOT)/envi.rule

####################################################
# 0、在运行 Makefile 前在 shell 中设置根目录变量 ROOT
####################################################

# 先进入 make.rule 文件所在的目录，再运行下面命令
# export ROOT=`pwd`    # 设置根目录变量 ROOT
# make all             # 执行编译操作
# make clean           # 执行清除操作
# make echo            # 执行查看变量

####################################################
# 1、定义子 Makefile 文件所在路径。【多个用空格分隔】
####################################################

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
	$(ECHO_OFF); \
	$(subst //, && $(MAKE) all;,$(MAKEFILE_CALL)) \
	$(ECHO_ON)

clean:
	$(ECHO_OFF); \
	$(subst //, && $(MAKE) clean;,$(MAKEFILE_CALL)) \
	$(ECHO_ON)

echo:
	$(ECHO_OFF); \
	$(subst //, && $(MAKE) echo;,$(MAKEFILE_CALL)) \
	$(ECHO_ON)

