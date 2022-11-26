#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *fp;
    char stringNum[9];
    int comma = 0, iComma, intNum, correct = 0, sumAfterComma = 0, flag = 0;
    double doubleNum;
    fp = fopen("in.txt", "r");

    fscanf(fp, "%s", stringNum);

    for (int i = 0; i < strlen(stringNum); ++i)
    {
        if (stringNum[i] == ',')
        {

            comma = 1;
            iComma = i;
        }
    }

    if (comma == 1)
    {
        for (int i = iComma + 1; i < strlen(stringNum); ++i)
        {
            sumAfterComma += 1;
        }
        if (sumAfterComma >= 1 && sumAfterComma <= 3)
        {
            stringNum[iComma] = '.';
            sscanf(stringNum, "%lf", &doubleNum);
            if (doubleNum >= 10 && doubleNum <= 1000)
            {
                printf("doubleNum = %.3lf\n", doubleNum);
            }
        }
    }
    else
    {
        while (!feof(fp))
        {
            if (isdigit(fgetc(fp)))
            {
                flag = 1;
            }
        }
        printf("flag = %d\n", flag);
        if (flag == 1)
        {
            fscanf(fp, "%d", &intNum);
            if (intNum >= 10 && intNum <= 1000)
            {
                printf("intNum = %d\n", intNum);
                correct = 1;
            }
        }
    }
    printf("correct = %d\n", correct);

    return 0;
}