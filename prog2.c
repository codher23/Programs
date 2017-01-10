#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
struct teacher
{
    char *name[20];
    char *department[20];
    long double mobile;
};
struct student
{
    char *name[20];
    int roll_no;
};
struct node
{
    char *ID[20];
    union person
    {
        struct teacher t;
        struct student s;
    }p;
    int count;
    int flag;
    struct node *next;
}*start=NULL;
//DECLARATION OF GLOBAL VARIABLES
char ch[20],q='y';
char a[30];
int c,n;
struct node *new,*current,*s;

void create1(void)
      {
            int i;
            printf("Enter the number of nodes:");
            scanf("%d",&n);
      for(i=1;i<=n;i++)
      {
            new=(struct node *)malloc(sizeof(struct node));
            printf("NODE %d:\n",i);
            printf("Enter ID:");
            scanf("%s%*c",&new->ID);
            printf("Whether Student (y/n):");
            scanf("%ch%*c",&ch[i]);
            if(ch[i]=='y')
            {
                  printf("Enter student's name:");
                  scanf("%s",&new->p.s.name);
                  printf("Enter the roll number:");
                  scanf("%d",&new->p.s.roll_no);
            }
            else if(ch[i]=='n')
            {
                  printf("Enter teacher's name:");
                  scanf("%s",&new->p.t.name);
                  printf("Enter the name of department:");
                  scanf("%s",&new->p.t.department);
                  printf("Enter the mobile number:");
                  scanf("%Lf",&new->p.t.mobile);
            }
            else
            {
                  printf("Wrong input entered");
            }
            printf("\n");
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
      }
      return;
}
//PRINT LINKED LIST
void display()
{
      int i;
      current=start;
      for(i=1;i<=n;i++)
      {
            printf("\n%d.",i);
            printf("ID=%s\n",current->ID);
            if(ch[i]=='y')
            {
                  printf("Student's Name=%s\nRoll Number=%d\n",current->p.s.name,current->p.s.roll_no);
            }
            else
            {
                  printf("Teacher's Name=%s\nDepartment=%s\nMobile Number=%.0Lf\n",current->p.t.name,current->p.t.department,current->p.t.mobile);
            }
            current=current->next;
            //printf("\n");
      }
      return;
}
//SORTING OF LINKED LIST
void sort(void)
{
      int j,l=1,k;
      current=start;
      int i,c=1,v[20];
      char u[20];
      for(i=0;i<n;i++)
      {
            //u[i]=*current->ID;
            v[i]=current->count;
            current=current->next;
      }
      while(c>0)
      {
            c=0;
            for(i=0;i<n-1;i++)
            {
                  s=v[i];
                  if(v[i]<v[i+1])
                  {
                        v[i]=v[i+1];
                        v[i+1]=s;
                        s=v[i];
                        c++;
                  }
            }
      }
      j=1;
      printf("\nThe sorted list is:\n");
      current=start;
      for(k=1;k<=n;k++)
      {
            current->flag=0;
            current=current->next;
      }
      for(i=0;i<n;i++)
      {
            l=1;
            for(current=start;current!=NULL;current=current->next)
            {
                  if(current->count==v[i]&&current->flag!=1)
                  {
                        printf("\n%d.",j);
                        printf("ID=%s\n",current->ID);
                        if(ch[l]=='y')
                        {
                              printf("Student's Name=%s\nRoll Number=%d\n",current->p.s.name,current->p.s.roll_no);
                              current->flag=1;
                        }
                        else
                        {
                              printf("Teacher's Name=%s\nDepartment=%s\nMobile Number=%.0Lf\n",current->p.t.name,current->p.t.department,current->p.t.mobile);
                              current->flag=1;
                        }
                        j++;
                        break;
                  }
                  l++;
            }
      }
      return;
}


//INITIALISE COUNT TO 1
void initialise()
{
      int i;
      current=start;
      for(i=1;i<=n;i++)
      {
            current->count=1;
            current=current->next;
      }
      return;
}
//SEARCH A NODE
void search()
{
      int i;
      while(q=='y')
      {
            printf("\n\nEnter ID to be searched:");
            scanf("%s%*c",&a);
            current=start;
            i=1;
            while(current!=NULL)
            {
                  if(strcmp(a,*current->ID)==0)
                  {
                        current->count=(current->count)+1;
                        printf("Count of searches is:%d\n",current->count);
                        printf("ID FOUND\n");
                        printf("ID=%s\n",current->ID);
                        if(ch[i]=='y')
                        {
                              printf("Student's Name=%s\nRoll Number=%d\n",current->p.s.name,current->p.s.roll_no);
                        }
                        else
                        {
                              printf("Teacher's Name=%s\nDepartment=%s\nMobile Number=%.0Lf\n",current->p.t.name,current->p.t.department,current->p.t.mobile);
                        }
                        //printf("\n");
                        sort();
                        break;
                  }
                  i++;
                  current=current->next;
            }
            printf("Search another node? (y/n) ");
            scanf("%c",&q);
      }
}

//MAIN FUNCTION


void main()
{
      create1();
      printf("The stored information is:\n");
      display();
      initialise();
      search();
}
//ENTER LINKED LIST

