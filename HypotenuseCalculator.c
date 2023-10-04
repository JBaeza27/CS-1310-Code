
//Hypotenuse Calculator . User input .
#include <stdio.h>
#include <math.h>

int main()
{
  double A;
  double B; 
  double C; 
  
  printf("Enter side a and b:"); /*checking.c:(.text+0x79): undefined reference to `sqrt'
                                  collect2: error: ld returned 1 exit status*/
  scanf("%lf %lf", &A, &B);

  C = sqrt(A*A + B*B);
  printf("Side C: %lf", C);

  return 0;
}