
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int stack_a[];

	stack_a[0] = 1;
	stack_a[1] = 34;

	printf("%d;",stack_a);

	
}