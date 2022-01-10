#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct treenode
{
   struct treenode *lchild;
   int data;
   struct treenode *rchild;
};
typedef struct treenode treenode;
treenode *getnode();
main()
{
   treenode *root;
   root=NULL;
   treecreate(&root,6);
   treecreate(&root,4);
   treecreate(&root,8);
   treecreate(&root,3);
   treecreate(&root,7);
   treecreate(&root,5);
   treecreate(&root,9);
   clrscr();
   treedisplay(root,1);
   getch();
}
treecreate(treenode **rt,int item)
{
   treenode *current=(*rt),*temp;
   if((*rt)==NULL)
   {
      (*rt)=getnode();
      (*rt)->data=item;
      (*rt)->lchild=NULL;
      (*rt)->rchild=NULL;
      return;
   }
   while(current!=NULL)
   {
      if(item<current->data)
      {
	 if(current->lchild!=NULL)
	 current=current->lchild;
	 else
	 {
	    temp=getnode();
	    current->lchild=temp;
	    temp->data=item;
	    temp->lchild=NULL;
	    temp->rchild=NULL;
	    return;
	 }
      }
      else
      {
	 if(item>current->data)
	 {
	    if(current->rchild!=NULL)
	    current=current->rchild;
	    else
	    {
	       temp=getnode();
	       current->rchild=temp;
	       temp->data=item;
	       temp->rchild=NULL;
	       temp->lchild=NULL;
	       return;
	    }
	 }
	 else
	    {
	       printf("worng data");
	       exit(0);
	    }
	 }
      }
   }
treedisplay(treenode *rt,int level)
{
   int i;
   if((rt)!=NULL)
   {
      treedisplay((rt)->rchild,level+1);
      printf("\n");
      for(i=0;i<level;i++)
      printf("\t");
      printf("%d",(rt)->data);
      treedisplay((rt)->lchild,level+1);
   }
}
treenode *getnode()
{
  treenode *t;
  t=(treenode *)malloc(sizeof(treenode));
  return t;
}







