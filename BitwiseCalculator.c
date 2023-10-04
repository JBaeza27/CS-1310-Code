//Joseph Baeza 
#include <stdio.h>

#define BITS 8

void ConvertDecimalToBinary(int decimalNumber, char resultBinary[])
{
    int array = BITS - 1; 

    do
    {
        resultBinary[array--] = (decimalNumber % 2) + '0'; //Add 0 for Binary Conversion
        decimalNumber /= 2; //Remainder
    } while (array >= 0);

    resultBinary[BITS] = '\0'; //set to NULL
}

int main()
{
    int numbergiven1, numbergiven2, resultDecimal;
    char operator[3];
    char binaryResult1[BITS + 1]; //Set each result to print
    char binaryResult2[BITS + 1]; 
    char binaryResult3[BITS + 1];
    int end = 1;

    printf("Bitwise Calculator\n"); 
    printf("Enter two base 10 values with a bitwise operator to see the decimal result\n");
    printf("and the binary result. The format is\n");
    printf("FirstNumber BitwiseOperator SecondNumber\n");
    printf("For example, enter the expression\n");
    printf("2 & 3\n");
    printf("This calculator can be used with &, |, ^, <<, and >>\n");
    printf("Please note that the spaces between numbers and the operator are essential\n");
    printf("and the two entered values must be between 0 and 255\n");
    printf("Enter expression: "); // Instructions

    scanf("%d %2s %d", &numbergiven1, operator, &numbergiven2); // Scan the expression

    while (numbergiven1 < 0 || numbergiven1 > 255 || numbergiven2 < 0 || numbergiven2 > 255) // Between 0-255
    {
        printf("Invalid number. Not between 0 and 255.\n");
        printf("Enter expression: ");
        scanf("%d %2s %d", &numbergiven1, operator, &numbergiven2); //If the number if not in between 0-255
    }

    if (operator[0] == '|')
    {
        resultDecimal = numbergiven1 | numbergiven2;
    }
    else if (operator[0] == '^')
    {
        resultDecimal = numbergiven1 ^ numbergiven2;
    }
    else if (operator[0] == '&')
    {
        resultDecimal = numbergiven1 & numbergiven2;
    }
    else if (operator[0] == '<' && operator[1] == '<')
    {
        resultDecimal = numbergiven1 << numbergiven2;
    }
    else if (operator[0] == '>' && operator[1] == '>')
    {
        resultDecimal = numbergiven1 >> numbergiven2; //Has to match the operator
    }
    else
    {
        printf("%s is not a valid operator\n", operator);
        end = 0; //if it doesn't the end is set to 0 which cuts it off to rest
    }

    if (end == 1) //if end is still 1 it continues to print out
    {
        printf("In base 10:\n");
        printf("%d %s %d = %d\n", numbergiven1, operator, numbergiven2, resultDecimal);
        printf("In %d-bit base 2:\n", BITS);

        ConvertDecimalToBinary(numbergiven1, binaryResult1); //call to numbergiven1
        ConvertDecimalToBinary(numbergiven2, binaryResult2); //call to numbergiven2
        ConvertDecimalToBinary(resultDecimal, binaryResult3); //call to Decimal result

        printf("%s\n", binaryResult1); //prints out the number given with expression to the produce the answer
        printf("%s\n", operator);
        printf("%s\n", binaryResult2);
        printf("=================\n");
        printf("%s\n", binaryResult3);
    }

    return 0;
}
