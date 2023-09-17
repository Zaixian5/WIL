#include <stdio.h>

void calc_circle(void)
{
	double radius = 0.0;
	double result = 0.0;
	
	printf("-Circle-\n\n");
	printf("Input radius: ");
	scanf("%lf", &radius);
	
	result = radius*radius*3.14;

	printf("\n");
	printf("Area of Circle: %.2f\n", result);
}
