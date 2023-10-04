//Circumference calculator. User input.
#include <stdio.h>
#include <math.h> 
int main ()
{
  const double PI = 3.14519;
  double radius;
  double circumference;
  double area;

  circumference = 2 * PI * radius;        /*/usr/bin/ld: /tmp/ccLEMFgk.o: in function `main':
                                          checking.c:(.text+0x88): undefined reference to `pow'*/
  area = PI * pow(radius, 2); 

  printf("Enter the radius of the circle: ");
  scanf("%lf", &radius);

  printf("circumference: %lf\n", circumference);
  printf("area: %lf", area);


  return 0;
}