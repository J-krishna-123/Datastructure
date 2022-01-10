#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *left;
   struct node *right;
};
typedef struct node node;
node *getnode();
void main()
{
   node *first;
   int ch,item,pos,n,d;
   INDL(&first);
   clrscr();
   printf("\n creating a doubly linked list");
   printf("\n no of node to create");
   scanf("%d",&n);
   DLC(&first,n);
   while(1)
   {
      printf("\nenter your choice");
      printf("\n 1.insert first node\n 2.insert last node\n");
      printf("\n 3.insert at any \n 4.delete first\n5.delete last\n");
      printf("\n 6.delete any\n 7.display\n 8.exit\n");
      scanf("%d",&ch);
      switch(ch)
      {
	 case 1:printf("\nenter item to inserted");
		scanf("%d",&item);
		IDLF(&first,item);
		break;

	 case 2:printf("\nenter item to inserted");
		scanf("%d",&item);
		IDLL(&first,item);
		break;
	 case 3:printf("\nenter item to inserted");
		scanf("%d",&item);
		printf("\n enter the node number");
		scanf("%d",&pos);
		IDLA(&first,item,pos);
		break;
	 case 4:DDLF(&first);
	       break;
	 case 5:DDLL(&first);
	       break;
	 case 6:printf("\n enter the node number to be deleted\n");
	       scanf("%d",&n);
	       DDLA(&first,n);
	       break;
	 case 7:TDL(first);
	       break;
	 case 8:exit(0);
	       break;
      }
   }
}
INDL(node **f)
{
   (*f)=NULL;
   return;
}
DLC(node **f,int n)
{
   node *temp,*current;
   int i,item;
   for(i=1;i<=n;i++)
   {
      printf("enter the data %d",i);
      scanf("%d",&item);
      temp=getnode();
      temp->data=item;
      temp->right=NULL;
      if(*f==NULL)
      {
	 (*f)=temp;
	 temp->left=NULL;
      }
      else
      {
	 current->right=temp;
	 temp->left=current;
      }
      current=temp;
   }
   return;
}
IDLF(node **f,int item)
{
   node *temp;
   int i;
   temp=getnode();
   temp->data=item;
   temp->left=NULL;
   if(*f==NULL)
   {
      temp->right=NULL;
   }
   else
   {
      temp->right=(*f);
      (*f)=temp;
   }
   return;
}
IDLL(node **f,int item)
{
   node *temp,*current;
   temp=getnode();
   temp->data=item;
   temp->right=NULL;
   if(*f==NULL)
   {
      temp->left=NULL;
      (*f)=temp;
   }
   else
   {
      current=(*f);
      while(current->right!=NULL)
      {
	 current=current->right;
      }
      temp->left=current;
      current->right=temp;
   }
   return;
}
IDLA(node **f,int item,int pos)
{
   node *temp,*current;
   int i;
   temp=getnode();
   temp->data=item;
   if(pos==1)
   {
      if(*f!=NULL)
      (*f)->left=temp;
      temp->right=(*f);
      temp->left=NULL;
      (*f)=temp;
   }
   else
   {
      i=2;
      current=(*f);
      while((i<pos)&&(current->right!=NULL))
      {
	 i++;
	 current=current->right;
      }
      temp->left=current;
      temp->right=current->right;
      if(current->right!=NULL)
      {
	 temp->right->left=temp;
	 current->right=temp;
      }
   }
   return;
}
DDLF(node **first)
{
   node *current;
   int item;
   if(*first==NULL)
   {
      printf("list is empty");
      return;
   }
   current=(*first);
   (*first)=(*first)->right;
   if(*first!=NULL)
   (*first)->left=NULL;
   item=current->data;
   freenode(current);
   printf("\n deleted item is %d",item);
   return;
}
DDLL(node **first)
{
   node *current;
   int item;
   if(*first==NULL)
   {
      printf("list is empty");
      return;
   }
   current=(*first);
   while(current->right!=NULL)
   current=current->right;
   if(current->left!=NULL)
   current->left->right=current->right;
   else
   (*first)=NULL;
   item=current->data;
   freenode(current);
   printf("deleted item is %d",item);
   return;
}
DDLA(node **first,int pos)
{
   node *current,*prev;
   int i=1,item;
   if(*first==NULL)
   {
      printf("list is empty");
      return;
   }
   current=(*first);
   while(current!=NULL)
   {
      if(i==pos)
      {
	 item=current->data;
	 if(current->left==NULL)
	 {
	    current->right->left=NULL;
	    (*first)=current->right;
	    freenode(current);
	 }
	 else if(current->right==NULL)
	 {
	    current->left->right=current->right;
	    freenode(current);
	 }
	 else
	 {
	    current->left->right=current->right;
	    current->right->left=current->left;
	    freenode(current);
	 }
	 printf("deleted item is %d",item);
	 return;
      }
      i++;
      current=current->right;
   }
   printf("\n no such node found");
   return;
}
TDL(node *first)
{
   if(first==NULL)
   {
      printf("list is empty");
      return;
   }
   printf("doubly linked list is");
   printf("\n start->");
   do
   {
      printf("%d <->",first->data);
      first=first->right;
   }
   while(first!=NULL);
   printf("END\n");
   return;
}
node *getnode()
{
   node *t;
   t=(node*)malloc(sizeof(node));
   return t;
}
freenode(node *t)
{
   free(t);
   return;
}






