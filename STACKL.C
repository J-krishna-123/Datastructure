#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct stacknode
{
   int data;
   struct stacknode *link;
};
typedef struct stacknode node;
node *getnode();
void main()
{
   node *first,*temp,*current;
   int ch,item,i,n;
   clrscr();
   first=NULL;
   do
   {
      printf("\n select your choice");
      printf("\n1.push\n 2.pop\n3.display\n4.exit\n");
      scanf("%d",&ch);
      switch(ch)
      {
	 case 1:printf("enter the element to insert");
	 scanf("%d",&item);
	 temp=getnode();
	 if(temp==NULL)
	 {
	    printf("unable to create node");
	 }
	 else
	 {
	    temp->data=item;
	    temp->link=first;
	    first=temp;
	 }
	 break;
	 case 2:if(first==NULL)
	 printf("the list is empty");
	 else
	 {
	    current=first;
	    item=current->data;
	    first=first->link;
	    free(current);
	 }
	 break;
	 case 3:if(first==NULL)
	 printf("stack underflow");
	 else
	 {
	    current=first;
	    while(current!=NULL)
	    {
	       printf("%d\t",current->data);
	       current=current->link;
	    }
	 }
	 break;
	 case 4:exit(0);
	 default:printf("\n invalid input");
      }
   }
   while(ch!=4);
   getch();
}
node *getnode()
{
   node *p;
   p=(node*)malloc(sizeof(node));
   return(p);
}

