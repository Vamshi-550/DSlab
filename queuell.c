#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct node
{
	int data;
	struct node*next;
};

struct queue
{
	struct node*front,*rear;
};


void create_queue(struct queue*q)
{
	q->front=q->rear = NULL;
}

void insert(struct queue*q,int val)
{
	struct node *ptr = malloc(sizeof(struct node));
	ptr->data = val;
	ptr->next = NULL;
	if(q->rear == NULL)
	q->front=q->rear = ptr;
}

void delete_element(struct queue *q)
{
if(q->front == NULL)
{
	printf("\n UNDERFLOW");
	return;
}
struct node*temp = q->front;
printf("\n Deleted:%d",temp->data);
q->front = q->front->next;
if(q->front == NULL)
q->rear = NULL;
free(temp);
}

int peek(struct queue*q)
{
	return(q->front)?q->front->data:-1;
}

void display(struct queue*q)
{
	if(q->front == NULL)
	{
		printf("\nQUEUE IS EMPTY");
		return;
	}
	struct node*temp = q->front;
	printf("\nQueue:");
	while(temp)
	{
		printf("%d",temp->data);
		temp = temp->next;
	}
}
int main()
{
    struct queue q;
    create_queue(&q);

    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Peek\n");
        
        printf("4. Display queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&q, value);
                break;
            case 2:
                delete_element(&q);
                break;
            case 3:
                value = peek(&q);
                if (value != -1)
                    printf("Front element is: %d\n", value);
                else
                    printf("Queue is empty\n");
                break;
            case 4:
                display(&q);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}
