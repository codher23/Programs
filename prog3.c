#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
        char name[20];
        char subject[30];
        int marks;
        int flag;
        struct node *next;
}*start=NULL,*head=NULL;
int count,lcount;
struct node *new,*current,*list,*s;
void create()
{
        char q;
        count=0;
        do
        {
                new=(struct node *)malloc(sizeof(struct node));
                printf("Enter the name of student:");
                scanf("%s%*c",&new->name);
                printf("Enter the subject:");
                scanf("%s%*c",&new->subject);
                printf("Enter the marks:");
                scanf("%d%*c",&new->marks);
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
                printf("Do you want to enter data for other student? (y/n) :");
                scanf("%ch%*c",&q);
        }while(q=='y'||q=='Y');
        return;
}
void display()
{
      int i;
      current=start;
      for(i=1;i<=count;i++)
      {
                printf(" (%d).  %s ---> %s ---> %d\n",i,current->name,current->subject,current->marks);
                current=current->next;
      }
      return;
}
void ncreate()
{
        int i,j,k,temp;
        lcount=0;
        char temps[30],temps1[30];
        current=start;
        for(k=1;k<=count;k++)
        {
                current->flag=0;
                current=current->next;
        }
        current=start;
       for(i=1;i<=count;i++)
        {
                if(current->flag==0)
                {
                        new=current->next;
                        for(j=i;j<count;j++)
                        {
                                if(new->flag==0)
                                {
                                        if(strcmpi(current->subject,new->subject)==0)
                                        {
                                                if(current->marks < new->marks)
                                                {
                                                        temp=current->marks;
                                                        current->marks=new->marks;
                                                        new->marks=temp;
                                                        strcpy(temps,current->name);
                                                        strcpy(current->name,new->name);
                                                        strcpy(new->name,temps);
                                                        strcpy(temps1,current->subject);
                                                        strcpy(current->subject,new->subject);
                                                        strcpy(new->subject,temps1);
                                                }
                                                new->flag++;
                                        }
                                }
                                new=new->next;
                        }
                        list=(struct node *)malloc(sizeof(struct node));
                        strcpy(list->subject,current->subject);
                        strcpy(list->name,current->name);
                        list->marks=current->marks;
                        if(head==NULL)
                        {
                                head=list;
                                s=list;
                        }
                        else
                        {
                                s->next=list;
                                s=list;
                        }
                        lcount++;
                }
                current=current->next;
        }
        return;
}
void print()
{
        int i;
        s=head;
        for(i=1;i<=lcount;i++)
        {
                printf(" (%d).  %s ---> %s ---> %d\n",i,s->subject,s->name,s->marks);
                s=s->next;
        }
        return;
}
void main()
{
      create();
      printf("\nThe stored information is:\n");
      printf("STUDENT_NAME-->SUBJECT-->MARKS\n");
      display();
      ncreate();
      printf("\nThe linked list of highest marks is:\n");
      printf("SUBJECT-->STUDENT_NAME-->MARKS\n");
      print();
}






























