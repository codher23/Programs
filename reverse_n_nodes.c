#include<stdio.h>
#include<stdlib.h>
struct node
{
      int id;
      struct node *next;
}*start1=NULL,*start2=NULL;
struct node *new1,*new2,*current1,*current2;
int count1=0,count2=0;
void create1()
{
      char q;
      do
      {
            new1=(struct node *)malloc(sizeof(struct node));
            printf("enter the id:");
            scanf("%d%*c",&new1->id);
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
            printf("do u want to enter another node(y/n) :");
            scanf("%ch%*c",&q);
            count1++;
      }while(q=='y');
      current1->next=NULL;
}
void display1()
{
      for(current1=start1;current1!=NULL;current1=current1->next)
      {
            printf("%d\t",current1->id);
      }
}
void reverse()
{
      int n,i;
      printf("enter the number of nodes to be reversed:");
      scanf("%d%*c",&n);
      struct node *temp,*prev,*flag;
      temp=start1;
      current1=start1;
      for(i=1;i<=n;i++)
      {
            temp=temp->next;
      }
      prev=temp;
      for(i=1;i<=n;i++)
      {
            flag=current1->next;
            current1->next=prev;
            prev=current1;
            current1=flag;
      }
      start1=prev;
}
int main()
{
      create1();
      display1();
      reverse();
      printf("\n");
      display1();
      return 0;
}


