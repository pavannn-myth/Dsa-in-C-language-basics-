#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

int qinsert(int q[], int r, int n) {
    int item;

    if (r == n - 1) {
        printf("Queue overflow\n");
        return r;
    }

    printf("Enter item: ");
    scanf("%d", &item);

    q[++r] = item;
    return r;
}

int qdelete(int q[], int f, int r) {
    int item;

    if (f > r) {
        printf("Queue underflow\n");
        return f;
    }

    item = q[f];
    printf("Deleted element = %d\n", item);

    f++;

    return f;
}

void display(int q[], int f, int r) {
    int i;

    if (f > r) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements:\n");
    for (i = f; i <= r; i++) {
        printf("%d\t", q[i]);
    }
    printf("\n");
}

int main() {
    int ch, n, q[SIZE], f = 0, r = -1;

    printf("Enter size of queue: ");
    scanf("%d", &n);

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                r = qinsert(q, r, n);
                break;

            case 2:
                f = qdelete(q, f, r);
                break;

            case 3:
                display(q, f, r);
                break;

            case 4:
                printf("Thank you!\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
