/* collatz.c */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	unsigned int input;
	unsigned int maxSteps = 1e6;
	unsigned int maxNum;
	unsigned int maxNumStep;
	unsigned int curr;
	unsigned int step;

	printf("========================\n");
	printf("Collatz Conjecture Test:\n");
	printf("========================\n");

	printf("\nEnter a positive integer (or 0 to quit): ");
	scanf("%u", &input);

	while (input != 0) {
		/* initialization */
		maxNum = 0;
		maxNumStep = 0;
		curr = input;

		printf("Collatz sequence: %u", curr);

		if (curr == 1) {
			maxNum = 1;
			maxNumStep = 0;
			step = 0;
			printf("\n");
		} else {
			/* calculate the sequence */
			for (step = 1; step <= maxSteps; step++) {
				if (curr % 2 == 0) { /* curr is an even number */
					curr = curr / 2;
				} else { /* curr is an odd number */
					curr = curr * 3 + 1;

					if (curr > maxNum) {
						maxNum = curr;
						maxNumStep = step;
					}
				}
				printf(", %u", curr);

				if (curr == 1) { /* we have reached the end of the sequence */
					printf("\n");
					break;
				}
			}
		}

		if (curr == 1) { /* we reached the end of the sequence */
			printf("Collatz conjecture is true for n=%u.\n", input);
			printf("Collatz sequence stops after %u steps.\n", step);
			printf("Maximum value is %u at step %u.\n", maxNum, maxNumStep);
		} else {
			printf("Stopping after 1 million steps.\n");
			printf("Collatz conjecture not clear for n=%u.\n", input);
		}

		printf("\nEnter a positive integer (or 0 to quit): ");
		scanf("%u", &input);
	}

	printf("Quit.\n");
	return 0;
}

/* EOF */
