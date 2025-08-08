#include <stdio.h>
#define SIZE 5  

int queue[SIZE];
int front = -1, rear = -1;

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

void enqueue(int value) {
    if ((front==-1 && rear==SIZE-1) || (rear+1)%SIZE==front) {
        printf("Queue is full\n");
        return;
    }
    
    if(front==-1){
    	front=0;
    	rear=0;
    	queue[rear]=value;
    	return;
    }
    
    if(front==rear+1){
    	rear=0;
    	queue[rear]=value;
    	return;
    }
    
    else {
        rear = (rear+1)%SIZE;
    	queue[rear] = value;
    	return;
    }
    printf("Enqueued %d\n", value);
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
   
    int temp = queue[front];

    if (front == rear) {
        front = -1;
        rear = -1; 
    } 
    else {
        front = (front + 1) % SIZE;
    }
    printf("Dequeued %d\n", temp);
   
}



int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                display();
                break;
            case 2:
                dequeue();
                display();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

