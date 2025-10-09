#include<stdio.h>
int main()
{
	int roll_no;
	char name[50];
	int marks[5],total=0;
	int i;
	printf("enter rollno number:");
	scanf("%d",&roll_no);
	
	printf("enter name:");
	scanf(" %[^\n]",name);
	
	for(i=0;i<5;i++){
		printf("enter marks of subject%d:",i+1);
		scanf("%d",&marks[i]);
		total+=marks;
	}
	printf("\n-- student details (using array)--\n");
	printf("rollno number:%d\n",roll_no);
	printf("name:%s\n",name);
	printf("marks: \n");
	for(i=0;i<5;i++)
	{
		printf("%d",marks[i]);
		
	}
	printf("\n total: %d\n",total);

	return 0;
}
