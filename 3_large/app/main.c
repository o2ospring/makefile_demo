#include <stdio.h>
#include "main.h"
#include "hello.h"
#include "test.h"
#include "crc.h"
#include "md5.h"
#include "main_2.c" ///

int main (int argc, char *argv[])
{
	printf("1. main() run!\n");
	hello("hello world!");
	test();
	crc();
	md5();
	return 0;
}
