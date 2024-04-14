#include <stdio.h>
#include <math.h>

double polynum(double* coefficent, int n, double x);

void main() {
	printf("Calculate the value of an polynomial y = a0 + a1x1 + a2x2^2 + ... \n");
	int c, count = 0;
	do {
		count++;
		double coefficient[5], x, y;
		int n;
		printf("Enter the degree of the polynomial (< 5): ");
		scanf_s("%d", &n);
		for (int i = 0; i <= n; i++) {
			printf("Enter the %dth coefficient (a%d): ", i + 1, i);
			scanf_s("%lf", &coefficient[i]);
		}
		printf("Enter the value of x: ");
		scanf_s("%lf", &x);
		y = polynum(coefficient, n, x);
		printf("The value of y = %lf\n", y);
		printf("If you want to calculate again, enter Y or y: ");
		fseek(stdin, 0, SEEK_END);
		c = getchar();
	} while (c == 'Y' || c == 'y');
	printf("You've done %d tasks\n", count);
	printf("Thank you for using this program!\n");
}

double polynum(double* coefficent, int n, double x) {
	double y = 0;
	for (int i = 0; i <= n; i++) {
		y += *(coefficent + i) * pow(x, i);
	}
	return y;
}