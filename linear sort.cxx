#include <stdio.h>

int main()
{
    int array[100], search, c, number, success = 0;

    printf("Enter the number of elements in array\n");
    scanf("%d", &number);

    printf("Enter %d numbers\n", number);
    for (c = 0; c < number; c++)
        scanf("%d", &array[c]);

    printf("Enter the number to search\n");
    scanf("%d", &search);

    for (c = 0; c < number; c++)
    {
        if (array[c] == search)
        {
            printf("%d is present at location %d.\n", search, c + 1);
            success = 1;
            break;
        }
    }

    if (success != 1)
        printf("%d is not present in array.\n", search);

    return 0;
}