#include <stdio.h>

#define BIGNUM_SIZE 201
struct bignum {
	int d[BIGNUM_SIZE];
	int used;
};

void print_bignum(struct bignum *bnum)
{
	int i;
	for (i = bnum->used; i >= 0; i--)
		if (bnum->d[i])
			break;
	for (; i >= 0; i--)
		printf("%05d", bnum->d[i]);
	printf("\n");
}

void bignum_add(struct bignum *bnum1, struct bignum *bnum2)
{
	int i, carry = 0;
	for (i = 0; i <= bnum2->used; i++) {
		bnum1->d[i] += (bnum2->d[i] + carry);
		carry = 0;
		if (bnum1->d[i] >= 100000) {
			bnum1->d[i] %= 100000;
			carry = 1;
		}
	}
	if (carry == 1)
		bnum1->d[i]++;
	if (bnum1->d[i] && (i > bnum1->used))
		bnum1->used = i;
	else if (bnum1->used < bnum2->used)
		bnum1->used = bnum2->used;
}

int find_nth_first_nbits_fibonacci(int nbits)
{
	int i, nth, idx;
	struct bignum num[2] = {0};

	nth = 3;
	num[0].d[0] = 1;
	num[1].d[0] = 1;
	while (1) {
		idx = ((nth & 0x1) ^ 0x1);
		bignum_add(&num[idx], &num[(idx ^ 0x1)]);
		if (((num[idx].used + 1) * 5) >= nbits) {
			int tmp = ((num[idx].used + 1) * 5);
			for (i = 10000; i > 0; i /= 10) {
				if (num[idx].d[num[idx].used] / i == 0)
					tmp--;
			}
			if (tmp >= nbits)
				break;
		}
		nth++;
	}

	return nth;
}

int main(int argc, char *argv[])
{
	printf("%d\n", find_nth_first_nbits_fibonacci(1000));

	return 0;
}

