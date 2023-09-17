#include <stdio.h>

void calc_cylinder(void)
{
	double radius = 0.0;
	double height = 0.0;
	double result = 0.0;

	printf("-Cylinder-\n\n");

	printf("Input radius: ");
	scanf("%lf", &radius);

	printf("Input height: ");
	scanf("%lf", &height);

	result = radius * radius * 3.14 * height;

	printf("\n");
	printf("Volume of Cylinder: %.2f\n", result);
}
