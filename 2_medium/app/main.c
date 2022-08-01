#include <stdio.h>
#include "main.h"
#include "hello.h"
#include "test.h"
#include "main_2.c" ///

int main (void)
{
	printf("1. main() run!\n");
	hello("hello world!");
	test();
	return 0;
}

