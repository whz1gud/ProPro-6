#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void format_validation(int *, int *, int *);

int main()
{
    FILE *fp;
    char userInput[100], domain[100];
    int length, atIndex, at = 0, dot = 0;

    do
    {
        printf("Give a valid email:\n");
        scanf("%s", &userInput);
        length = strlen(userInput);
        for (int i = 0; i < length; i++)
        {
            if (userInput[i] == '@' && i != 0)
            {
                atIndex = i;
                printf("\nk = %d\n", atIndex);
                at = 1;
                for (int j = atIndex + 1; j < length; j++)
                {
                    if (userInput[j] == '@')
                    {
                        at = 0;
                        break;
                    }
                    printf("at = %d\n", at);
                    if (userInput[j] == '.' && j != atIndex + 1 && j != length-1)
                    {
                        printf("j = %d\n", j);
                        dot = 1;
                    }
                    if (userInput[j] == '.' && j == atIndex + 1)
                    {
                        dot = 0;
                        break;
                    }
                    
                }
                if (at == 0 || dot == 0)
                {
                    break;
                }
            }
        }
        printf("\nfinal at = %d\nfinal dot = %d\n", at, dot);

    } while (at != 1 || dot != 1);

    fp = fopen("emails.txt", "a");
    fprintf(fp, "%s\n",userInput);
    fclose(fp);
    return 0;
}