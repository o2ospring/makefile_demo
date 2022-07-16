####################################################
# 1、配置编译相关参数、编译文件(夹)、目标及中间文件
####################################################

# 定义编译器及命令相关参数
CC = gcc
CFLAGS  = 
CFLAG_O = -c
CFLAG_M = -E -MM
RM = rm
RMFLAGS = -fr
MKDIR = mkdir -p

# 定义执行文件，包括其路径及文件名
EXEC = ./build/main

# 定义中间文件夹，用于存放中间文件
OBJS_D = ./build/

# 添加编译文件，包括其路径及文件名
SRCS_F = ./app/main.c            \
         ./usr/test.c            \
         ./usr/hello.c

# 添加编译文件夹，要指定文件扩展名
SRCS_D = ./modules/crc/*.c       \
         ./modules/md5/*.c

# 添加源码文件及包含文件所在的路径
VPATH = app:usr:modules/crc:modules/md5

# 添加使用-l和-L指定的库文件和路径
LIBS = 

####################################################
# 2、根据上面的相关配置，生成包括路径的相关文件对象
####################################################

CFLAG_O += -I $(subst :, -I ,$(VPATH))
CFLAG_M += -I $(subst :, -I ,$(VPATH))
OBJS_D := $(addsuffix /,$(OBJS_D))
OBJS_D := $(subst //,/,$(OBJS_D))
DEPS_D := $(OBJS_D)
DIRS := $(sort $(OBJS_D) $(dir $(EXEC)))
SRCS := $(SRCS_F) $(wildcard $(SRCS_D))
SRCS := $(filter %.c, $(SRCS))
OBJS := $(SRCS:.c=.o)
OBJS := $(addprefix $(OBJS_D),$(notdir $(OBJS)))
DEPS := $(SRCS:.c=.d)
DEPS := $(addprefix $(OBJS_D),$(notdir $(DEPS)))
OBJX := $(OBJS) $(DEPS)

####################################################
# 3、执行创建文件夹、生成依赖、编译、删除等相关操作
####################################################

.PHONY: all clean echo

all: $(EXEC)

# 非执行"clean"才包含
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),echo)
-include $(DEPS)
endif
endif

# 编译出最终执行文件
$(EXEC): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@

# 编译出中间目标文件
$(OBJS_D)%.o: %.c
	@echo "making $@..."
	@$(MKDIR) $(DIRS); \
	$(CC) $(CFLAG_O) $(filter %.c, $^) -o $@

# 生成代码依赖信息
$(DEPS_D)%.d: %.c
	@echo "making $@..."
	@set -e; \
	$(MKDIR) $(DIRS); \
	$(RM) $(RMFLAGS) $@.tmp; \
	$(CC) $(CFLAG_M) $(filter %.c, $^) > $@.tmp; \
	sed 's,\(.*\)\.o[ :]*,$(dir $@)\1.o $@: ,g' < $@.tmp > $@; \
	$(RM) $(RMFLAGS) $@.tmp

# 清除目标及执行文件
clean:
	$(RM) $(RMFLAGS) $(EXEC) $(OBJX)

# 查看变量对象相关值
echo:
	@echo "DIRS: $(DIRS)"        # DIRS 为编译过程需要创建的文件夹（如：build/）
	@echo "SRCS: $(SRCS)"        # SRCS 为全部源码文件及其路径    （如：usr/hello.c）
	@echo "OBJS: $(OBJS)"        # OBJS 为全部中间目标文件及其路径（如：build/hello.o）
	@echo "DEPS: $(DEPS)"        # DEPS 为全部依赖信息文件及其路径(源码文件包含其它文件的信息)（如：build/hello.d）
	@echo "OBJX: $(OBJX)"        # OBJX 为所有中间文件及其路径(包括：OBJS 和 DEPS)
	@echo "CFLAG_O: $(CFLAG_O)"  # CFLAG_O 编译中间目标文件的选项参数（如：-c）
	@echo "CFLAG_M: $(CFLAG_M)"  # CFLAG_O 生成依赖信息文件的选项参数（如：-MM）

