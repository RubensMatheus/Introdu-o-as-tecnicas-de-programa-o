#include <stdio.h>

int main()
{

    int i, j, num;
    char letra;

    scanf("%d %c", &num, &letra);

    for (i = 1; i < num; i++)
    {
        for (j = 1; j < num; j++)
        {
            if (j == i || j == num - i)
                printf("%c", letra);
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}