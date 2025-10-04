#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

typedef struct {
    char data[SIZE];
    int top;
} STACK;

void push(STACK *s, char ch) {
    s->data[++(s->top)] = ch;
}

char pop(STACK *s) {
    return s->data[(s->top)--];
}

int precedence(char ch) {
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '^') return 3;
    return 0;
}
//reversing a string
void reverse(char *str) {
    int i = 0, j = strlen(str) - 1;
    while(i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++; j--;
    }
}

void infixToPrefix(char *infix, char *prefix) {
    STACK s;
    s.top = -1;
    int k = 0;

    reverse(infix);

    for(int i = 0; infix[i]; i++) {
        char ch = infix[i];

        if(isalnum(ch)) {
            prefix[k++] = ch; // Operand → directly to output
        }
        else if(ch == ')') {
            push(&s, ch);
        }
        else if(ch == '(') {
            while(s.top != -1 && s.data[s.top] != ')')
                prefix[k++] = pop(&s);
            pop(&s);
        }
        else {
            while(s.top != -1 && precedence(s.data[s.top]) > precedence(ch))
                prefix[k++] = pop(&s);
            push(&s, ch);
        }
    }

    while(s.top != -1) 
        prefix[k++] = pop(&s);

    prefix[k] = '\0';
    reverse(prefix); 
}

int main() {
    char infix[SIZE], prefix[SIZE];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}