#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

// Push
void push(char item) {
    stack[++top] = item;
}

// Pop
char pop() {
    return stack[top--];
}

// Priority function
int priority(char symbol) {
    switch(symbol) {
        case '+':
        case '-': return 1;

        case '*':
        case '/': return 2;

        case '^': return 3;

        default: return 0;
    }
}

// Infix to Postfix conversion
void infix_to_postfix(char infix[], char postfix[]) {
    int i, j = 0;
    char symbol;

    for(i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        // If operand → add to postfix
        if(isalnum(symbol)) {
            postfix[j++] = symbol;
        }

        // If '(' → push
        else if(symbol == '(') {
            push(symbol);
        }

        // If ')' → pop until '('
        else if(symbol == ')') {
            while(stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }

        // Operator
        else {
            while(top != -1 && priority(stack[top]) >= priority(symbol)) {
                postfix[j++] = pop();
            }
            push(symbol);
        }
    }

    // Pop remaining operators
    while(top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

// Main
int main() {
    char infix[100], postfix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
