#include<stdio.h>
#include<stdlib.h>
struct node
{
      int id;
      struct node *next;
}*start1=NULL,*start2=NULL,*start3=NULL;
struct node *new1,*new2,*new3,*current1,*current2,*current3;
int n1,n2,i;
void create()
{
      printf("enter number of nodes in first list:");
      scanf("%d",&n1);
      for(i=1;i<=n1;i++)
      {
            new1=(struct node*)malloc(sizeof(struct node));
            printf("enter the id:");
            scanf("%d",&new1->id);
            if(start1==NULL)
            {
                  start1=new1;
                  current1=new1;
            }
            else
            {
                  current1->next=new1;
                  current1=new1;
            }
      }
      current1->next=NULL;
      printf("enter number of nodes in second list:");
      scanf("%d",&n2);
      for(i=1;i<=n2;i++)
      {
            new2=(struct node*)malloc(sizeof(struct node));
            printf("enter the id:");
            scanf("%d",&new2->id);
            if(start2==NULL)
            {
                  start2=new2;
                  current2=new2;
            }
            else
            {
                  current2->next=new2;
                  current2=new2;
            }
      }
      current2->next=NULL;
}
void display()
{
      current1=start1;
      printf("\nlist 1 is\n");
      while(current1!=NULL)
      {
            printf("%d\n",current1->id);
            current1=current1->next;
      }
      current2=start2;
      printf("\nlist 2 is\n");
      while(current2!=NULL)
      {
            printf("%d\n",current2->id);
            current2=current2->next;
      }
}
void sort()
{
      int i,j;
      int temp;
      struct node *new;
      for(i=1;i<n1-1;i++)
      {
            current1=start1;
            new=current1->next;
           for(j=i;j<n1;j++)
           {
                 if(current1->id>new->id)
                 {
                       temp=current1->id;
                       current1->id=new->id;
                       new->id=temp;
                 }
                 current1=current1->next;
                 new=new->next;
           }
      }
      current1->next=NULL;
      for(i=1;i<n2-1;i++)
      {
            current2=start2;
            new=current2->next;
           for(j=i;j<n2;j++)
           {
                 if(current2->id>new->id)
                 {
                       temp=current2->id;
                       current2->id=new->id;
                       new->id=temp;
                 }
                 current2=current2->next;
                 new=new->next;
           }
      }
      current2->next=NULL;
}
void merge()
{
      current1=start1;
      current2=start2;
      current3=start3;
      printf("the merged list is\n");
      while(current1!=NULL&&current2!=NULL)
      {
            if(current1->id<current2->id)
            {
                  current3=current1;
                  current1=current1->next;
                  printf("\n%d\t",current3->id);
            }
            else if(current1->id>current2->id)
            {
                  current3=current2;
                  current2=current2->next;
                  printf("\n%d\t",current3->id);
            }
            else if(current1->id==current2->id)
            {
                  current3=current1;
                  current1=current1->next;
                  current2=current2->next;
                  printf("\n%d\t",current3->id);
            }
            current3=current3->next;
      }
      while(current1!=NULL)
      {
            current3=current1;
            current1=current1->next;
            printf("\n%d\t",current3->id);
            current3=current3->next;
      }
      while(current2!=NULL)
      {
            current3=current2;
            current2=current2->next;
            printf("\n%d\t",current3->id);
            current3=current3->next;
      }
}
int main()
{
      create();
      display();
      sort();
      merge();
}

