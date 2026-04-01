#include <stdio.h>
#define MAX 1000

void simple_merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int c[MAX];

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else
        {
            c[k] = a[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
        c[k++] = a[i++];

    while (j <= high)
        c[k++] = a[j++];

    for (i = low; i <= high; i++)
    {
        a[i] = c[i];
    }
}

void merge_sort(int a[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        simple_merge(a, low, mid, high);
    }
}

int main()
{
    int n, a[MAX], i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    merge_sort(a, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}