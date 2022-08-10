####################################################
# 1、配置编译相关参数、编译文件(夹)、目标及中间文件
####################################################

# 定义生成目标，包括其路径及文件名【只能是一个对象】
TARGET = ./build/app.exe

# 定义中间文件夹，用于存放中间文件【只能是一个对象】
OBJS_D = ./build/

# 添加编译源文件，包括路径及文件名【多个用空格分隔】
SRCS_F = ./app/main.c                             \
         ./usr/hello.c                            \
         ./usr/test.c

# 添加编译文件夹，要指定文件扩展名【多个用空格分隔】
SRCS_D = ./modules/led/*.c                        \
         ./modules/delay/*.c

# 添加编译库文件，包括路径及文件名【多个用空格分隔】
LIBS   = 

# 添加源码文件及包含文件所在的路径【多个用空格分隔】
VPATH  = ./app                                    \
         ./usr/                                   \
         ./modules/led/                           \
         ./modules/delay

# 定义编译器及其环境相关参数
CC = gcc
RM = rm
CFLAG_L = 
CFLAG_O = -c -W -Wall
CFLAG_M = -MMD -MP -MF"$(@:%.o=%.d)"
RMFLAGS = -fr
MKDIR   = mkdir -p
#ECHO_SET = @set -e
#ECHO_END = 

# 生成源文件包含路径选项参数
ifdef VPATH
SRCS_INC := $(addprefix -I,$(strip $(VPATH)))
endif

####################################################
# 2、根据上面的相关配置，生成包括路径的相关文件对象
####################################################

VPATH := $(addsuffix /,$(VPATH))
VPATH := $(subst //,/,$(VPATH))
SRCS_INC := $(addsuffix /,$(SRCS_INC))
SRCS_INC := $(subst //,/,$(SRCS_INC))
OBJS_D := $(addsuffix /,$(OBJS_D))
OBJS_D := $(subst //,/,$(OBJS_D))
DEPS_D := $(OBJS_D)
DIRS := $(sort $(OBJS_D) $(dir $(TARGET)))
SRCS := $(filter %.c, $(SRCS_F) $(wildcard $(SRCS_D)))
OBJS := $(SRCS:.c=.o)
OBJS := $(addprefix $(OBJS_D),$(notdir $(OBJS)))
DEPS := $(SRCS:.c=.d)
DEPS := $(addprefix $(OBJS_D),$(notdir $(DEPS)))
OBJX := $(sort $(OBJS) $(DEPS) $(addsuffix .tmp,$(DEPS)))
LIBS := $(sort $(LIBS))

ifdef VPATH
CFLAG_O += $(SRCS_INC)
#CFLAG_M += $(SRCS_INC)
endif

####################################################
# 3、执行创建文件夹、生成依赖、编译、删除等相关操作
####################################################

.PHONY: all clean echo

all: $(TARGET)

# 非执行"clean/echo"才包含
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),echo)
-include $(DEPS)
endif
endif

# 编译出最终执行文件
$(TARGET): $(OBJS) $(LIBS)
	@echo "[2]making $@..."
	@$(CC) $(CFLAG_L) -o $@ $(filter %.o, $^) $(LIBS)

# 编译出中间目标文件
$(OBJS_D)%.o: %.c
	@echo "[1]making $@..."
	@$(CC) $(CFLAG_O) $(CFLAG_M) $< -o $@

# 清除目标及执行文件
clean:
	$(MKDIR) $(DIRS)
	$(RM) $(RMFLAGS) $(OBJX) $(TARGET)

# 查看变量对象相关值
echo:
	$(MKDIR) $(DIRS)
	@echo "VPATH: $(VPATH)"      # VPATH 为[make]工具增加搜索目录
	@echo "DIRS: $(DIRS)"        # DIRS 为编译过程需要创建的文件夹（如：build/）
	@echo "SRCS: $(SRCS)"        # SRCS 为全部源码文件及其路径    （如：usr/hello.c）
	@echo "OBJS: $(OBJS)"        # OBJS 为全部中间目标文件及其路径（如：build/hello.o）
	@echo "DEPS: $(DEPS)"        # DEPS 为全部依赖信息文件及其路径(源码文件包含其它文件的信息)（如：build/hello.d）
	@echo "OBJX: $(OBJX)"        # OBJX 为所有中间文件及其路径(包括：OBJS 和 DEPS)
	@echo "LIBS: $(LIBS)"        # LIBS 为编译包含的库文件及其路径（如：build/abc.a）
	@echo "CFLAG_O: $(CFLAG_O)"  # CFLAG_O 编译中间目标文件的选项参数（如：-c -I./usr/）
	@echo "CFLAG_M: $(CFLAG_M)"  # CFLAG_O 生成依赖信息文件的选项参数（如：-MM -I./usr/）

