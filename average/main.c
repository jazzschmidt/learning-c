#include <stdio.h>

int get_decimals(int);

int main(int argc, char const *argv[]) {
	int value_count;

	printf("Amount of values: ");
	scanf("%d", &value_count);
	printf("\n");

	double values[value_count];
	double total = 0;

	for(int i = 0; i < value_count; ++i) {
		printf("%02d: ", i+1);
		scanf("%lf", &values[i]);

		total += values[i];
	}

	double avg = total / value_count;

	printf("Total: %lf\nAverage: %lf\n", total, avg);

	return 0;
}
