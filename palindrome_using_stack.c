#include <stdio.h>
#include <string.h>
#define SIZE 100

typedef struct stack {
    char data[SIZE];
    int top;
} STACK;

void push(STACK *s, char ch) {
    s->data[++(s->top)] = ch;
}

char pop(STACK *s) {
    return s->data[(s->top)--];
}

int isPalindrome(char *str) {
    STACK s;
    s.top = -1;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }


    for (int i = 0; i < len; i++) {
        if (str[i] != pop(&s)) {
            return 0; 
        }
    }

    return 1; 
}

// Main function
int main() {
    char str[SIZE];
for(;;){
    printf("Enter a string: ");
    scanf("%s",&str);


    if (isPalindrome(str))
        printf("\nThe string is a palindrome");
    else
        printf("\nThe string is not a palindrome\n ");}

    return 0;
}
