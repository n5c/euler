#include <stdio.h>

struct bignum {
	int d[500];
	int used;
};

void bignum_multiply(struct bignum *bnum1, struct bignum *bnum2)
{
	int i, j, k, carry;
	struct bignum tmp = {{0}, 0};
	for (i = 0; i <= bnum1->used; i++) {
		if (bnum1->d[i] == 0)
			continue;
		carry = 0;
		for (j = 0; j <= bnum2->used; j++) {
			k = (i + j);
			tmp.d[k] += (bnum1->d[i] * bnum2->d[j] + carry);
			carry = 0;
			if (tmp.d[k] >= 10000) {
				carry = (tmp.d[k] / 10000);
				tmp.d[k] %= 10000;
			}
		}
		k++;
		tmp.d[k] += carry;
	}
	for (i = k; i >= 0; i--)
		bnum1->d[i] = tmp.d[i];
	while((bnum1->d[k] == 0) && (k >= 0))
		k--;
	bnum1->used = k;
}

void bignum_assign(struct bignum *bnum1, struct bignum *bnum2)
{
	int i;
	for (i = 0; i <= bnum2->used; i++)
		bnum1->d[i] = bnum2->d[i];
	bnum1->used = bnum2->used;
}

int bignum_sum_digits(struct bignum *bnum)
{
	int i, tmp, sum = 0;
	for (i = 0; i <= bnum->used; i++) {
		tmp = bnum->d[i];
		while(tmp) {
			sum += (tmp % 10);
			tmp /= 10;
		}
	}
	return sum;
}

void print_bignum(struct bignum *bnum)
{
	int i;
	for (i = bnum->used; i >= 0; i--)
		printf("%04d", bnum->d[i]);
	printf("\n");
}

int factorial_digit_sum(int num)
{
	int i;
	struct bignum bnsum = {0}, bnum = {0};
	bnsum.d[0] = 1;
	for (i = 2; i <= num; i++) {
		bnum.d[0] = i;
		bignum_multiply(&bnsum, &bnum);
	}
	return bignum_sum_digits(&bnsum);
}

int main(int argc, char *argv[])
{
	printf("%d\n", factorial_digit_sum(100));
	return 0;
}

