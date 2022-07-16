#include <stdio.h>
#include "main.h"
#include "hello.h"
#include "test.h"

int main ()
{
	printf("1. main() run!\n");
	hello("hello world!");
	test();
	return 0;
}
