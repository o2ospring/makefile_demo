####################################################
# 1、本案例展示多个文件编译和链接。
# 2、无论我们写再复杂的 Makefile，最终展开所有变量和
#    脚本语句后，与本例 makefile 展示的形式都是一样，
#    不一样的只是展开的目标更多、每个目标的依赖更多、
#    每个目标的操作命令更多而已！
# 3、补充说明：脚本所有内容(包括变量、函数等)展开后
#    都是一组字符串，最终就不存在变量这类的内容了！
####################################################

.PHONY: all
all: main
main:    hello.o test.o main.o
	gcc  hello.o test.o main.o -o main  # 链接

hello.o: hello.c hello.h
hello.o: hello.c
	gcc -c hello.c -o hello.o           # 编译

test.o: test.c test.h
test.o: test.c
	gcc -c test.c -o test.o             # 编译

main.o: main.c main.h
main.o: main.c
	gcc -c main.c -o main.o             # 编译
#	@echo $^                            # 如果开启打印，就会发现【$^】为【main.c main.h】！

.PHONY: clean                           # 为了避免出错，使用 .PHONY 说明 clean 是一个伪目标
clean:
	rm -f main.o test.o hello.o main    # 删除编译生成的文件

