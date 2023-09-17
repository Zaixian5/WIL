#include <stdio.h>

void calc_circle(void);
void calc_rectangle(void);
void calc_triangle(void);
void calc_cylinder(void);

int main(void)
{
	int figure = 0;
	
	printf("=====Area & Volume Calculator=====\n\n");

	printf("Select Number:\n");
	printf("1. circle  2. rectangle  3. triangle  4. cylinder\n");
	scanf("%d", &figure);

	switch(figure)
	{
	case 1:
		calc_circle();
		break;
	
	case 2:
		calc_rectangle();
		break;
	
	case 3:
		calc_triangle();
		break;

	case 4:
		calc_cylinder();
		break;

	default:
		printf("Check Your Number!\n");
	}

	return 0;
}
