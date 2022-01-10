#include<stdio.h>
#include<conio.h>
struct node
{
   int data;
   struct node *link;
};
typedef struct node qnode;
qnode *getnode();
void main()
{
   qnode *front,*rear,*temp;
   int item,ch;
   clrscr();
   front=NULL;
   rear=NULL;
   do
   {
      printf("select your choice");
      printf("\n \t 1.insert\n2.delete\n3.display\n.4.exit");
      scanf("%d",&ch);
      switch(ch)
      {
	 case 1:printf("enter the item to insert");
	 scanf("%d",&item);
	 temp=getnode();
	 temp->data=item;
	 temp->link=NULL;
	 if(front==NULL)
	 {
	    front=temp;
	    rear=temp;
	 }
	 else
	 {
	    rear->link=temp;
	    rear=temp;
	 }
	 break;
	 case 2:if(front==NULL)
	 printf("queue is empty");
	 else
	 {
	    temp=front;
	    item=temp->data;
	    front=front->link;
	    if(front==NULL)
	    rear=NULL;
	    free(temp);
	 }
	 break;
	 case 3:if(front==NULL)
	 printf("queue is empty");
	 else
	 {
	    printf("queue is \n");
	    temp=front;
	    while(temp!=NULL)
	    {
	       printf("%d\t",temp->data);
	       temp=temp->link;
	    }
	 }
	 break;
	 case 4:exit(0);
	 defalut:printf("invalid");
      }
   }
   while(ch!=5);
   getch();
}
qnode *getnode()
{
   qnode *p;
   p=(qnode*)malloc(sizeof(qnode));
   return p;
}
