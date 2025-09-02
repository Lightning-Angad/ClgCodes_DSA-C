#include<stdio.h>
#define MAX 5
int queue[MAX];
int front=-1, rear=-1;

void enqueue(int value) {
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) {
        printf("Queue is Full\n");
        return;
    } else if (front == -1) { // Insert First Element
        front = rear = 0;
        queue[rear] = value;
    } else if (rear == MAX - 1 && front != 0) { // Wrap Around
        rear = 0;
        queue[rear] = value;
    } else { // Normal Case
        rear++;
        queue[rear] = value;
    }
    printf("Inserted: %d\n", value);
}

int dequeue() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return -1;
    }
    int data = queue[front];
    queue[front] = -1; // Optional: Clear the slot
    if (front == rear) { // Queue has only one element
        front = rear = -1;
    } else if (front == MAX - 1) { // Wrap Around
        front = 0;
    } else { // Normal Case
        front++;
    }
    printf("Deleted: %d\n", data);
    return data;
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        for (int i = front; i < MAX; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}