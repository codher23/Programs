#include<stdio.h>
#include<stdlib.h>
struct node
{
      int id;
      struct node *next;
}*start=NULL;
struct node *new,*current;
int a;
void create()
{
      char q;
      do
      {
            new=(struct node *)malloc(sizeof(struct node));
            printf("enter the id:");
            scanf("%d%*c",&new->id);
            if(start==NULL)
            {
                  start=new;
                  current=new;
            }
            else
            {
                  current->next=new;
                  current=new;
            }
            printf("do u want to enter another node(y/n) :");
            scanf("%ch%*c",&q);
      }while(q=='y');
      current->next=NULL;
}
void display()
{
      for(current=start;current!=NULL;current=current->next)
      {
            printf("%d\t",current->id);
      }
}
void clockwise()
{
      int count=0;
      struct node *temp,*prev;
      temp=start;
      current=start;
      prev=start;
      while(current!=NULL)
      {
            if(current->id==a&&count!=0)
            {
                  prev->next=NULL;
                  start=current;
                  while(current->next!=NULL)
                  {
                        current=current->next;
                  }
                  current->next=temp;
                  break;
            }
            else if(count==0&&current->id==a)
            {
                  break;
            }
            else
            {
                  prev=current;
                  current=current->next;
                  count++;
            }
      }
}
void anticlockwise()
{
      struct node *temp,*prev;
      temp=start;
      current=start;
      prev=NULL;
      while(current!=NULL)
      {
            temp=current->next;
            current->next=prev;
            prev=current;
            current=temp;
      }
      start=prev;
      clockwise();
}
int main()
{
      int z;
      create();
      printf("\n\n");
      display();
      printf("choose direction :\n1.clockwise\n2.anticlockwise\n");
      scanf("%d%*c",&z);
      printf("enter the starting id :");
      scanf("%d%*c",&a);
      switch(z)
      {
            case(1):
                  {
                        clockwise();
                        display();
                        break;
                  }
            case(2):
                  {
                        anticlockwise();
                        display();
                        break;
                  }
      }
      return 0;
}
