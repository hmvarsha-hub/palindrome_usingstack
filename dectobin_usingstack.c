#include <stdio.h>
#define SIZE 100

struct stack {
    int data[SIZE];
    int top;
};
typedef struct stack STACK;

void push(STACK *s, int num) {
    s->data[++(s->top)] = num;
}

int pop(STACK *s) {
    return s->data[(s->top)--];
}

void decimalToBinary(STACK *s, int num) {
    s->top=-1;  
    int i=0, j, bin[SIZE];

    if (num == 0) {
        printf("0\n");
        return;
    }

    while (num > 0) {
        push(s, num % 2);
        num = num / 2;
}
    while (s->top != -1) {
        bin[i++] = pop(s);
    }

    for (j = 0; j < i; j++) {
        printf("%d", bin[j]);
    }
    printf("\n");
}

int main() {
    STACK s;
    int num;

    for(;;) {
        printf("Enter a number (negative to exit): ");
        scanf("%d", &num);

        if (num < 0) break;

        printf("Binary: ");
        decimalToBinary(&s, num);  
    }

    return 0;
}