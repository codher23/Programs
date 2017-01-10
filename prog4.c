#include<stdio.h>
#include<stdlib.h>
struct node
{
        int id;
        struct node *left;
        struct node *right;
        struct node *up;
        struct node *down;
        struct node *next;
}*start=NULL;
struct node *new,*current;
struct node *ptr[16];
int k=0;
int a[50];
int count=1;
void create()
{
      int i;
      for(i=0;i<16;i++)
      {
            new=(struct node*)malloc(sizeof(struct node));
            new->id=i;
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
}
void array()
{
      int i;
      current=start;
      for(i=0;i<16;i++)
      {
            ptr[i]=current;
            current=current->next;
      }
}
void point()
{
      int ID;
      ID=0;
        current=start;
        current->left=NULL;
        current->right=ptr[1];
        current->up=NULL;
        current->down=NULL;
      ID=1;
        current=current->next;
        current->left=NULL;
        current->right=NULL;
        current->up=NULL;
        current->down=ptr[5];
      ID=2;
        current=current->next;
        current->left=NULL;
        current->right=ptr[3];
        current->up=NULL;
        current->down=NULL;
      ID=3;
        current=current->next;
        current->left=NULL;
        current->right=NULL;
        current->up=NULL;
        current->down=NULL;
      ID=4;
        current=current->next;
        current->left=NULL;
        current->right=NULL;
        current->up=NULL;
        current->down=NULL;
      ID=5;
        current=current->next;
        current->left=ptr[4];
        current->right=ptr[6];
        current->up=NULL;
        current->down=ptr[9];
      ID=6;
        current=current->next;
        current->left=NULL;
        current->right=ptr[7];
        current->up=ptr[2];
        current->down=ptr[10];
      ID=7;
        current=current->next;
        current->left=NULL;
        current->right=NULL;
        current->up=NULL;
        current->down=ptr[11];
      ID=8;
        current=current->next;
        current->left=NULL;
        current->right=ptr[9];
        current->up=NULL;
        current->down=ptr[12];
      ID=9;
        current=current->next;
        current->left=ptr[8];
        current->right=NULL;
        current->up=NULL;
        current->down=ptr[13];
      ID=10;
        current=current->next;
        current->left=NULL;
        current->right=NULL;
        current->up=NULL;
        current->down=ptr[14];
      ID=11;
        current=current->next;
        current->left=NULL;
        current->right=NULL;
        current->up=NULL;
        current->down=NULL;
      ID=12;
        current=current->next;
        current->left=NULL;
        current->right=ptr[13];
        current->up=NULL;
        current->down=NULL;
      ID=13;
        current=current->next;
        current->left=NULL;
        current->right=ptr[14];
        current->up=NULL;
        current->down=NULL;
      ID=14;
        current=current->next;
        current->left=NULL;
        current->right=ptr[15];
        current->up=NULL;
        current->down=NULL;
      ID=15;
        current=current->next;
        current->left=NULL;
        current->right=NULL;
        current->up=NULL;
        current->down=NULL;
}
void ncreate()
{
      int y=0,i,q=0;
      int flag,x;
      printf("Enter the id: ");
      scanf("%d",&a[0]);
      current=start;
      while(y<=k)
      {
            current=start;
            q=y;
            for(i=0;i<16;i++)
            {
                  if(a[q]==current->id)
                  {
                        if(current->up!=NULL)
                        {
                              flag=0;
                              for(x=0;x<=k;x++)
                              {
                                    if(current->up->id==a[x])
                                          flag++;
                              }
                              if(flag==0)
                              {
                                    k++;
                                    a[k]=current->up->id;
                                    count++;
                              }
                        }
                        if(current->left!=NULL)
                        {
                              flag=0;
                              for(x=0;x<=k;x++)
                              {
                                    if(current->left->id==a[x])
                                          flag++;
                              }
                              if(flag==0)
                              {
                                    k++;
                                    a[k]=current->left->id;
                                    count++;
                              }
                        }
                        if(current->right!=NULL)
                        {
                              flag=0;
                              for(x=0;x<=k;x++)
                              {
                                    if(current->right->id==a[x])
                                          flag++;
                              }
                              if(flag==0)
                              {
                                    k++;
                                    a[k]=current->right->id;
                                    count++;
                              }
                        }
                        if(current->down!=NULL)
                        {
                              flag=0;
                              for(x=0;x<=k;x++)
                              {
                                    if(current->down->id==a[x])
                                          flag++;
                              }
                              if(flag==0)
                              {
                                    k++;
                                    a[k]=current->down->id;
                                    count++;
                              }
                        }
                        break;
                  }
                  current=current->next;
            }
            y++;
      }
}
void display()
{
      int i;
      for(i=0;i<count;i++)
            printf("\t%d\n\n",a[i]);
}
void main()
{
      create();
      array();
      point();
      ncreate();
      display();
}
