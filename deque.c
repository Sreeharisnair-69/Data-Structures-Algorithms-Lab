#include <stdio.h>
#define MAX 5

int Deque[MAX];
int front = -1, rear = -1;

int isFull(){
	if((front==0 && rear==MAX-1) || (front==rear+1)){
		return 1;
	}
	else{
		return 0;
	}
}

int isEmpty(){
	if(front==-1){
		return 1;
	}
	else{
		return 0;
	}
}

void push(int val){
	if (isFull()==1){
		printf("Deque Overflow\n");
	}
	else{
		if(front==-1 && rear==-1){
			front=rear=0;
		}
		else if(front==0){
			front=MAX-1;
		}
		else{
			front=front-1;
		}
		Deque[front]=val;
	}
}

void inject(int val){
	if (isFull()==1){
		printf("Deque Overflow\n");
	}
	else{
		if(front==-1 && rear==-1){
			front=rear=0;
		}
		else if(rear==MAX-1){
			rear=0;
		}
		else{
			rear=rear+1;
		}
		Deque[rear]=val;
	}
}

void pop(){
	if (isEmpty()==1){
		printf("Deque Underflow\n");
	}
	else{
		printf("Popped %d\n",Deque[front]);
		if (front==rear){
			front=rear=-1;
		}
		else if(front==MAX-1){
			front=0;
		}
		else{
			front=front+1;
		}	
	}
}

void reject(){
	if (isEmpty()==1){
		printf("Deque Underflow\n");
	}
	else{
		printf("Rejected %d\n",Deque[rear]);
		if (front==rear){
			front=rear=-1;
		}
		else if(rear==0){
			rear=MAX-1;
		}
		else{
			rear=rear-1;
		}	
	}
}

void display(){
	if (isEmpty()==1){
		printf("Deque is empty");
		return;
	}
	else{
		printf("Queue elements: ");
    		int i = front;
    		while (1) {
        		printf("%d ", Deque[i]);
        		if (i == rear) break;
        		i = (i + 1) % MAX;
   	 	}
    		printf("\n");
	}
}	

int main(){
	int choice, value;

    	while (1) {
       		printf("\n--- Deque Menu ---\n");
        	printf("1. push\n2. inject\n3. pop\n4. reject\n5. exit\n");
        	printf("Enter your choice: ");
        	scanf("%d", &choice);
        	
        	switch (choice) {
            		case 1:
                		printf("Enter value to push: ");
                		scanf("%d", &value);
                		push(value);
                		display();
               			break;
               		case 2:
                		printf("Enter value to inject: ");
                		scanf("%d", &value);
                		inject(value);
                		display();
               			break;
            		case 3:
                		pop();
                		display();
                		break;
                	case 4:
                		reject();
                		display();
                		break;
            		case 5:
            			printf("Exiting program...\n");
               			return 0;
            		default:
               			printf("Invalid choice. Try again.\n");
        	}
    	}

    	return 0;
}

