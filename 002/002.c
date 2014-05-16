#include <stdio.h>
#define LIMIT 4000000

int main (int argc, char *argv[]) 
{
	int num, num1 = 1, num2 = 1, total = 0;
	while ((num = (num1 + num2)) < LIMIT) {
		num1 = num2;
		num2 = num;
		if (num & 0x1)
			continue;
		total += num;
	}
	printf ("%d\n", total);
	return 0;
}

