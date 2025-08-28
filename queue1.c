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
void creat_queue(struct queue *q)
{
	q->front = q->rear = NULL;
}
void insert(struct queue *q,int val)
{
	struct node *ptr = malloc(sizeof(struct node)); 
	ptr->data = val;
	ptr->next = NULL;
	if(q->rear == NULL)
	   q->front = q->rear = ptr;
	else
	   q->rear = q->rear->next = ptr;
	//q->rear->next = ptr;
	//q->rear = ptr;
}
void delete_element(struct queue *q)
{
	if(q->front == NULL)
	{
		printf("\nUNDERFLLOW");
		return;
	}
	struct node *temp = q->front;
	printf("\nDELETED: %d",temp->data);
	q->front = q->front->next;
	if(q->front == NULL)
	q->rear = NULL;
	free(temp);
}
int peek(struct queue *q)
{
	return(q->front) ? q->front->data:-1;
}
void display(struct queue *q)
{
	if(q->front == NULL)
	{
		printf("\nQUEUE IS EMPTY");
		return;
	}
	struct node *temp = q->front;
	printf("\nQueue : ");
	while(temp)
	{
		printf("%d",temp->data);
		temp = temp->next;
	}
}
int main()
{
	int val, option;
	struct queue q;
	q.front = NULL;
	q.rear = NULL;
	
	
	do
	{
		printf("\n *****MAIN MENU*****");
	               printf("\n 1. INSERT");
	               printf("\n 2. DELETE");
	               printf("\n 3. PEEK");
	               printf("\n 4. DISPLAY");
	               printf("\n 5. EXIT");
	               printf("\n Enter your option : ");
	               scanf("%d", &option);
	               switch(option)
	               {
	               	case 1:
	               		printf("\n Enter number to insert in the queue: ");
	               		scanf("%d", &val);
	               		insert(&q, val);
	               		break;
	               	case 2:
	               		delete_element(&q);
	               		break;
	               	case 3:
	               		val = peek(&q);
	               		if(val != -1)
	               		       printf("\n The value at front of queue is : %d", val);
	               		break;
	               	case 4:
	               		display(&q);
	               		break;
		}
		
	}while(option != 5) ;
	getch();
	return 0;
}
