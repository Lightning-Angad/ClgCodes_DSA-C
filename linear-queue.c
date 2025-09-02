#include<stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value){
    if(rear == MAX - 1){
        printf("Queue Overflow\n");
        return;
    }
        if(front == -1) front = 0;
        rear++;
        queue[rear] = value;
        printf("Inserted %d\n", value);
}

void dequeue(){
    if(front == -1 || front > rear){
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted %d\n", queue[front]);
    front++;
}

void display(){
    int i;
    if(front == -1 || front > rear){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for(i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(){
    int choice, value;
    while(1){
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter elements: ");
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