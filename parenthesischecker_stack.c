#include <stdio.h>
#include <string.h>

#define SIZE 100

typedef struct  {
    char data[SIZE];
    int top;
} STACK;

void push(STACK *s, char ch) {
        s->data[++(s->top)] = ch;
    
}

char pop(STACK *s) {
    if (s->top >= 0) {
        return s->data[(s->top)--];
    }
    return '\0'; 
}
int isValidParentheses(char *str) {
    STACK s;
    s.top = -1;

    int len = strlen(str);
    for (int i = 0; i < len; i++)
     {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        } 
        else if (ch == ')' || ch == '}' || ch == ']') {
            char top = pop(&s);
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
           {
                return 0; 
            }
        }
    }

    return s.top == -1; 
}


int main() {
    char str[SIZE];
    printf("Enter a string with parentheses: ");
    scanf("%s", str);

    if (isValidParentheses(str)) {
        printf("The string has valid parentheses.\n");
    } else {
        printf("The string does NOT have valid parentheses.\n");
    }

    return 0;
}