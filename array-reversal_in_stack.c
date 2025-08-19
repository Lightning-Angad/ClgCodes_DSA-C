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
void reversal(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        push(arr[i]);
    }
    for (i = 0; i < n; i++) {
        arr[i] = pop();
    }
}
int main() {
    int arr[MAX], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    reversal(arr, n);
    
    printf("Reversed array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}