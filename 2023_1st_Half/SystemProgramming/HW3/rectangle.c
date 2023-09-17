#include <stdio.h>

void calc_rectangle(void)
{
	double base = 0.0;
	double height = 0.0;
	double result = 0.0;

	printf("-Rectangle-\n\n");

	printf("Input base: ");
	scanf("%lf", &base);

	printf("Input height: ");
	scanf("%lf", &height);

	result = base * height;

	printf("\n");
	printf("Area of Rectangle: %.2f\n", result);
}
