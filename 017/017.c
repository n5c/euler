#include <stdio.h>

/* zero, one, two, ... nineteen */
const int d0_19[] = {
	0, 3, 3, 5, 4, 4, 3, 5, 5, 4,
	3, 6, 6, 8, 8, 7, 7, 9, 8, 8
};

/* zero, ten, twenty, ... ninety */
const int d0_90[] = { 0, 3, 6, 6, 5, 5, 5, 7, 6, 6 };

const int dX00 = 7; /* hundred */

const int dX000 = 8; /* thousand */

const int dand = 3; /* ultimate 'AND' */

int get_letter_count(int num)
{
	int _num, cnt = 0;

	if (num == 1000)
		return 11;

	_num = num;

	if ((_num / 100) != 0) {
		cnt = (d0_19[(_num / 100)] + dX00);
		_num %= 100;
		if (_num == 0)
			return cnt;
		cnt += dand;
	}

	if (_num < 20)
		return (cnt + d0_19[_num]);

	cnt += d0_90[(_num / 10)];
	_num %= 10;
	cnt += d0_19[_num];

	return cnt;
}

int main(int argc, char *argv[])
{
	int i, sum;
	sum = 0;
	for (i = 1; i <= 1000; i++)
		sum += get_letter_count(i);
	printf("%d\n", sum);

	return 0;
}

