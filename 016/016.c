#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

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

int power_digit_sum(int base, int exp)
{
	int i, _exp;
	struct bignum bnums[20] = {0};
	struct bignum bnum = {0};
	bnums[0].d[0] = base;
	_exp = 1;
	i = 0;
	while(i < 20) {
		if ((_exp << 1) > exp)
			break;
		i++;
		bignum_assign(&bnums[i], &bnums[(i - 1)]);
		bignum_multiply(&bnums[i], &bnums[(i - 1)]);
		_exp <<= 1;
	}

	bignum_assign(&bnum, &bnums[i]);

	/* i-value inherited from the loop above */
	for (; i >= 0; i--) {
		if ((_exp + (1 << i)) > exp)
			continue;
		bignum_multiply(&bnum, &bnums[i]);
		_exp += (1 << i);
	}

	assert(_exp == exp);

	return bignum_sum_digits(&bnum);
}

int main(int argc, char *argv[])
{
	printf("%d\n", power_digit_sum(2, 1000));
	return 0;
}

