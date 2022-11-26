#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void format_validation(double, double, double, double *, double *, double *);
double middleOfThree(double, double, double);

int main()
{
    FILE *fp;
    int rez;
    double num1, num2, num3, midVal;
    char filename[100];
    char search[5] = ".txt";
    char *ret;

    format_validation(num1, num2, num3, &num1, &num2, &num3);
    printf("Enter the file name (*.txt)\n");

    midVal = middleOfThree(num1, num2, num3);

    do
    {
        scanf("%s", &filename);
        ret = strstr(filename, search);
        printf("%s", ret);

        if (ret == NULL)
        {
            printf("Wrong file name format! Try again:\n");
        }
        else
        {
            rez = strcmp(search, ret);
        }
        if (rez != 0)
        {
            printf("Wrong file name format! Try again:\n");
        }
        
    } while (ret == NULL || rez != 0);

    fp = fopen(filename, "w");
    fprintf(fp, "Middle value: %lf", midVal);
    fclose(fp);

    return 0;
}

void format_validation(double num1, double num2, double num3, double *pNum1, double *pNum2, double *pNum3)
{
    printf("Enter 3 numbers in this format (x;y;z):\n");
    while (scanf("%lf", &num1) == 0 || getchar() != ';' || scanf("%lf", &num2) == 0 || getchar() != ';' || scanf("%lf", &num3) == 0 || getchar() != '\n')
    {
        printf("Incorrect format! Try again:\n");
        while (getchar() != '\n')
            ;
    }
    *pNum1 = num1;
    *pNum2 = num2;
    *pNum3 = num3;
    printf("*Correct format*\n");
}

double middleOfThree(double a, double b, double c)
{
    // Checking for b
    if ((a < b && b < c) || (c < b && b < a))
       return b;
 
    // Checking for a
    else if ((b < a && a < c) || (c < a && a < b))
       return a;
 
    else
       return c;
}