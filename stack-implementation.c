#include<stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int v) {
    if (top == MAX - 1) {
        printf("\nStack overflow");
        return;
    } 
    top++;
    stack[top] = v;
    return;
}
int pop() {
    if (top == -1) {
        printf("\nStack underflow");
        return -1;
    }
    return stack[top--];
}
void display() {
    int i;
    for (i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
}
int main() {
    int n;
    int i=-1;;
    while (i!=0) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d", &i);
        if(i==1) {
            printf("Enter value to push: ");
            scanf("%d", &n);
            push(n);
        } 
        else if(i==2) {
            printf("Popped value: %d\n", pop());
            }
        else if(i==3) {
            printf("Stack elements: ");
            display();
        } 
        else if(i==4) {
            printf("Exiting...\n");
        } 
        else {
            printf("Invalid option, please try again.\n");
        }
    }
        return 0;
    }