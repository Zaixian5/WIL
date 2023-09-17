#include <stdio.h>

void calc_triangle(void)
{
	double base = 0.0;
	double height = 0.0;
	double result = 0.0;

	printf("-Triangle-\n\n");

	printf("Input base: ");
	scanf("%lf", &base);

	printf("Input height: ");
	scanf("%lf", &height);

	result = (base * height) / 2.0;

	printf("\n");
	printf("Area of Triangle: %.2f\n", result);	
}
