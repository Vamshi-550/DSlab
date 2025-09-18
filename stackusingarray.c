#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct queue
{
	struct node *front,*rear;
};

void create_queue(struct queue *q)
{
	q->front = q->rear = NULL;
}

void insert(struct queue *q, int val)
{
	struct node *ptr = (struct node*) malloc(sizeof(struct node));
	ptr->data = val;
	ptr->next = NULL;
	
	if (q->rear == NULL)
		q->front = q->rear = ptr;
	else
		q->rear = q->rear->next = ptr;
}



void delete_element(struct queue *q)
{
	if (q->front == NULL)
	{
		printf("\nUNDERFLOW");
		return;
	}
	struct node *temp = q->front;
	printf("\nDeleted: %d", temp->data);
	q->front = q->front->next;
	if (q->front == NULL)
		q->rear = NULL;
	free(temp);
}

int peek(struct queue *q)
{
	return (q->front) ? q->front->data : -1;
}

void display(struct queue *q)
{
	if(q->front == NULL)
	{
		printf("\nQUEUE IS EMPTY");
		return;
	}
	struct node *temp = q->front;
	printf("\nQueue: ");
	while (temp)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
}

int main()
{
	struct queue q;
    create_queue(&q);

    int choice, value;

    do
    {
        printf("\n\n--- Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
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
                printf("\nFront element: %d", value);
            break;
        case 4:
            display(&q);
            break;
        case 5:
            printf("\nExiting...");
            break;
        default:
            printf("\nInvalid choice!");
        }
    } while (choice != 5);

    return 0;
}

