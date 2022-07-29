####################################################
# 1、配置编译相关参数、编译文件(夹)、目标及中间文件
####################################################

# 定义生成文件，包括其路径及文件名【只能是一个对象】
EXE    = ./build/exec

# 定义中间文件夹，用于存放中间文件【只能是一个对象】
OBJS_D = ./build/

# 添加编译源文件，包括路径及文件名【多个用空格分隔】
SRCS_F = ./app/main.c                             \
         ./usr/hello.c                            \
         ./usr/test.c

# 添加编译文件夹，要指定文件扩展名【多个用空格分隔】
SRCS_D = ./modules/md5/*.c                        \
         ./modules/crc/*.c

# 添加编译库文件，包括路径及文件名【多个用空格分隔】
LIBS   = 

# 添加源码文件及包含文件所在的路径【多个用空格分隔】
VPATH  = ./app                                    \
         ./usr                                    \
         ./modules/md5                            \
         ./modules/crc

# 定义编译器及其环境相关参数
CC = gcc
RM = rm
CFLAGS  = 
CFLAG_O = -c
CFLAG_M = -E -MM
RMFLAGS = -fr
MKDIR = mkdir -p
ECHO_OFF= @set -e
ECHO_ON = 

# 生成源文件包含路径选项参数
ifdef VPATH
SRCS_INC := $(addprefix -I,$(strip $(VPATH)))
endif

####################################################
# 2、根据上面的相关配置，生成包括路径的相关文件对象
####################################################

OBJS_D := $(addsuffix /,$(OBJS_D))
OBJS_D := $(subst //,/,$(OBJS_D))
DEPS_D := $(OBJS_D)
DIRS := $(sort $(OBJS_D) $(dir $(EXE)))
SRCS := $(SRCS_F) $(wildcard $(SRCS_D))
SRCS := $(filter %.c, $(SRCS))
OBJS := $(SRCS:.c=.o)
OBJS := $(addprefix $(OBJS_D),$(notdir $(OBJS)))
DEPS := $(SRCS:.c=.d)
DEPS := $(addprefix $(OBJS_D),$(notdir $(DEPS)))
OBJX := $(OBJS) $(DEPS) $(addsuffix .tmp,$(OBJS))
LIBS := $(sort $(LIBS))

ifdef VPATH
CFLAG_O += $(SRCS_INC)
CFLAG_M += $(SRCS_INC)
endif

####################################################
# 3、执行创建文件夹、生成依赖、编译、删除等相关操作
####################################################

.PHONY: all clean echo

all: $(EXE)

# 非执行"clean/echo"才包含
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),echo)
-include $(DEPS)
endif
endif

# 编译出最终执行文件
$(EXE): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) -o $@ $(filter %.o, $^) $(LIBS)

# 编译出中间目标文件
$(OBJS_D)%.o: %.c
	@echo "[2]making $@..."
	@$(MKDIR) $(DIRS); \
	$(CC) $(CFLAG_O) $< -o $@

# 生成代码依赖信息
$(DEPS_D)%.d: %.c
	@echo "[1]making $@..."
	$(ECHO_OFF); \
	$(MKDIR) $(DIRS); \
	$(RM) $(RMFLAGS) $@.tmp; \
	$(CC) $(CFLAG_M) $< > $@.tmp; \
	sed 's,\(.*\)\.o[ :]*,$(dir $@)\1.o $@: ,g' < $@.tmp > $@; \
	$(RM) $(RMFLAGS) $@.tmp; \
	$(ECHO_ON)

# 清除目标及执行文件
clean:
	$(RM) $(RMFLAGS) $(EXE) $(OBJX)

# 查看变量对象相关值
echo:
	@echo "VPATH: $(VPATH)"      # VPATH 为[make]工具增加搜索目录
	@echo "DIRS: $(DIRS)"        # DIRS 为编译过程需要创建的文件夹（如：build/）
	@echo "SRCS: $(SRCS)"        # SRCS 为全部源码文件及其路径    （如：usr/hello.c）
	@echo "OBJS: $(OBJS)"        # OBJS 为全部中间目标文件及其路径（如：build/hello.o）
	@echo "DEPS: $(DEPS)"        # DEPS 为全部依赖信息文件及其路径(源码文件包含其它文件的信息)（如：build/hello.d）
	@echo "OBJX: $(OBJX)"        # OBJX 为所有中间文件及其路径(包括：OBJS 和 DEPS)
	@echo "LIBS: $(LIBS)"        # LIBS 为编译包含的库文件及其路径（如：build/abc.a）
	@echo "CFLAG_O: $(CFLAG_O)"  # CFLAG_O 编译中间目标文件的选项参数（如：-c -I./usr/）
	@echo "CFLAG_M: $(CFLAG_M)"  # CFLAG_O 生成依赖信息文件的选项参数（如：-MM -I./usr/）

