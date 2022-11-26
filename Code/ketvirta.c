#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void format_validation(int *, int *, int *);

int main()
{
    FILE *fp;
    int y, m, d;
    int num = 0;
    char weekdayNames[7][11];
    char weekdayName[11];
    format_validation(&y, &m, &d);
    fp = fopen("week.txt", "r");
    int weekday = (d += m < 3 ? y-- : y - 2, 23 * m / 9 + d + 4 + y / 4 - y / 100 + y / 400) % 7;
    if (fp != NULL)
    {
        while (fgets(weekdayName, 11, fp))
        {
            strcpy(weekdayNames[num], weekdayName);
            num++;
        }
        for (int i = 0; i < 7; i++)
        {
            if (weekday == i + 1)
            {
                printf("%s", weekdayNames[i]);
            }
        }
        if (weekday == 0)
        {
            printf("%s", weekdayNames[6]);
        }
        fclose(fp);
        }
    else
        printf("File not found!\n");

    return 0;
}

void format_validation(int *y, int *m, int *d)
{
    int yy, mm, dd;
    int flag = 0;
    printf("Enter date (YYYY-MM-DD) format: ");
    do
    {
        while (scanf("%d-%d-%d", &yy, &mm, &dd) != 3 || getchar() != '\n')
        {
            printf("Incorrect date format! Try again:\n");
            while (getchar() != '\n')
                ;
        }

        // check year
        if (yy >= 1900 && yy <= 9999)
        {
            // check month
            if (mm >= 1 && mm <= 12)
            {
                // check days
                if ((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
                {
                    printf("Date is valid.\n");
                    flag = 1;
                }
                else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
                {
                    printf("Date is valid.\n");
                    flag = 1;
                }
                else if ((dd >= 1 && dd <= 28) && (mm == 2))
                {
                    printf("Date is valid.\n");
                    flag = 1;
                }
                else if (dd == 29 && mm == 2 && (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)))
                {
                    printf("Date is valid.\n");
                    flag = 1;
                }
                else
                    printf("Day is invalid. Enter date again:\n");
            }
            else
            {
                printf("Month is not valid. Enter date again:\n");
            }
        }
        else
        {
            printf("Year is not valid. Enter date again:\n");
        }
    } while (flag != 1);
    *y = yy;
    *m = mm;
    *d = dd;
}