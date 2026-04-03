#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    int info;
    struct node *llink;
    struct node *rlink;
};

typedef struct node* NODE;

// Create node
NODE getnode() {
    NODE x = (NODE)malloc(sizeof(struct node));
    if (x == NULL) {
        printf("Out of memory!\n");
        exit(0);
    }
    return x;
}

// Insert using direction
NODE insert(int item, NODE root) {
    NODE temp, cur, prev;
    char dir[20];
    int i;

    temp = getnode();
    temp->info = item;
    temp->llink = temp->rlink = NULL;

    if (root == NULL)
        return temp;

    printf("Enter direction (L/R): ");
    scanf("%s", dir);

    // Convert to uppercase
    for (i = 0; i < strlen(dir); i++)
        dir[i] = toupper(dir[i]);

    prev = NULL;
    cur = root;

    for (i = 0; i < strlen(dir); i++) {
        if (cur == NULL)
            break;

        prev = cur;

        if (dir[i] == 'L')
            cur = cur->llink;
        else
            cur = cur->rlink;
    }

    if (cur != NULL || i != strlen(dir)) {
        printf("Insertion not possible!\n");
        free(temp);
        return root;
    }

    if (dir[i - 1] == 'L')
        prev->llink = temp;
    else
        prev->rlink = temp;

    return root;
}

// Display tree (sideways)
void display(NODE root, int level) {
    int i;
    if (root == NULL)
        return;

    display(root->rlink, level + 1);

    for (i = 0; i < level; i++)
        printf("\t");

    printf("%d\n", root->info);

    display(root->llink, level + 1);
}

// Inorder traversal
void inorder(NODE root) {
    if (root == NULL)
        return;

    inorder(root->llink);
    printf("%d -> ", root->info);
    inorder(root->rlink);
}

// Main
int main() {
    NODE root = NULL;
    int ch, item;

    while (1) {
        printf("\n1: Insert\n2: Inorder\n3: Display\n4: Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                root = insert(item, root);
                break;

            case 2:
                printf("Inorder traversal:\n");
                inorder(root);
                printf("\n");
                break;

            case 3:
                if (root == NULL)
                    printf("Empty tree!\n");
                else {
                    printf("Tree structure:\n");
                    display(root, 1);
                }
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
