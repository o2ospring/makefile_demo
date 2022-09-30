#include <stdio.h>
#include "main.h"
#include "hello.h"
#include "test.h"
#include "delay.h"
#include "led.h"
#include "main_2.c" ///

int main (int argc, char *argv[])
{
	int i;
	
	for (i=1; i<argc; i++)
	{
		printf("0. argv[%d]=%s\n", i, argv[i]);
	}
	printf("1. main() run!\n");
	hello("hello world!");
	test();
	delay();
	led();
	return 0;
}

