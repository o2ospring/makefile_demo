#include <stdio.h>
#include <stdint.h>
#include "hello.h"

uint8_t hello(const char *p) 
{
	printf("2. hello() run: %s\n", p);
	return 0;
}

