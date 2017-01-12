#include<stdio.h>
#include<stdlib.h>
struct node
{
      int id;
      struct node *next;
}*start=NULL;
struct node *new,*current;
int count=0;
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
            count++;
            printf("(y/n):");
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
void pallindrome()
{
      int c=0;
      struct node *temp;
      int j;
      for(current=start;current!=NULL;current=current->next)
      {
            j=count;
            for(temp=start;j>1;j--)
            {
                  temp=temp->next;
            }
            count--;
            if(current->id==temp->id)
            {
                  continue;
                  c++;
            }
            else
            {
                  break;
            }
      }
      if(count%2==0)
      {
            if(c==count/2)
            {
                  printf("pallindromic\n");
            }
            else
            {
                  printf("not pallindromic\n");
            }
      }
      else
      {
            if(c==(count+1)/2)
            {
                  printf("pallindromic\n");
            }
            else
            {
                  printf("not pallindromic\n");
            }
      }
}
int main()
{
      create();
      display();
      pallindrome();
      return 0;
}
