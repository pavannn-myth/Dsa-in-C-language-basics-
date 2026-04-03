#include <stdio.h>

// Function prototype
int bsearch(int key, int a[], int low, int high);

int main() {
    int a[10], n, key, i, pos;

    printf("Recursive Binary Search\n");

    printf("Enter the limit: ");
    scanf("%d", &n);

    printf("Enter %d elements in sorted order:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    pos = bsearch(key, a, 0, n - 1);

    if (pos == -1)
        printf("Item not found!\n");
    else
        printf("Item found at position %d\n", pos + 1);

    return 0;
}

// Recursive binary search
int bsearch(int key, int a[], int low, int high) {
    int mid;

    if (low > high)
        return -1;

    mid = (low + high) / 2;

    if (key == a[mid])
        return mid;
    else if (key < a[mid])
        return bsearch(key, a, low, mid - 1);
    else
        return bsearch(key, a, mid + 1, high);
}
