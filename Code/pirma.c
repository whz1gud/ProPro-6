#include <stdio.h>
#include <stdlib.h>

double positiveNum_validation();

int main()
{
    FILE *fp;
    double n;
    n = positiveNum_validation();
    printf("%.2lf\n", n);
    fp = fopen("output.txt", "w");
    fprintf(fp, "%.2lf\n", n);
    fclose(fp);    
    return 0;
}

double positiveNum_validation()
{
    double num;
    printf("Enter a positive number:\n");
    while(scanf("%lf", &num) == 0 || num <= 0)
    {
        printf("It is not a positive number! Try again:\n");
        while (getchar() != '\n');
    }
    printf("*Value accepted*\n");
    return num;
}
