#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 10001
#define TARGET_PLACE 10001

int main(int argc, char *argv[])
{
	int i, j, nth, base, *prm, *prmtime;
	char buffer[BUFSIZE];

	prm = calloc(TARGET_PLACE, sizeof(int));
	prmtime = calloc(TARGET_PLACE, sizeof(int));
	base = 0;
	nth = 6;
	prm[0] = 2;
	prm[1] = 3;
	prm[2] = 5;
	prm[3] = 7;
	prm[4] = 11;
	prm[5] = 13;

	while (1) {
		memset(buffer, 0, sizeof(buffer));

		for (i = 1; i < nth; i++) {

			for (j = ((prm[i] * (prmtime[i] + 1)) - base); 
					j < BUFSIZE; j += prm[i]) {
				buffer[j] = 1;
				prmtime[i]++;
			}

			if (i == (nth - 1)) {
				if (prm[i] > base)
					j = (prm[i] - base);
				else
					j = 1;

				for (; j < BUFSIZE; j += 2) {
					if (buffer[j] == 1)
						continue;
					prm[nth] = (j + base);
					nth++;
					break;
				}
			}

			if (nth >= TARGET_PLACE)
				break;
		}

		base += (BUFSIZE - 1);

		if (nth >= TARGET_PLACE)
			break;
	}

	printf ("%d: %d\n", TARGET_PLACE, prm[(TARGET_PLACE - 1)]);

	free(prm);
	free(prmtime);

	return 0;
}


