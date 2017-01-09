# Programs
My 2nd repository
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define AREA(a,b) a*b
int main(int argc,char *argv[])
{
    float x3,y3,x4,y4,l,w;
    if(argc==5)
    {
        if(((argv[1])==(argv[3]))||((argv[2])==(argv[4])))
            printf("A unique rectangle can not be made with these points.\nPlease enter the coordinates again.");
        else
        {
            x3=atof(argv[1]);
            y3=atof(argv[4]);
            x4=atof(argv[3]);
            y4=atof(argv[2]);
            l=fabs(atof(argv[1])-x4);
            w=fabs(atof(argv[4])-y4);
            printf("\nThe coordinates of rectangle are:\n");
            printf("(%.2f %.2f)\t",atof(argv[1]),atof(argv[2]));
            printf("(%.2f %.2f)\n",x4,y4);
            printf("(%.2f %.2f)\t",x3,y3);
            printf("(%.2f %.2f)\n\n",atof(argv[3]),atof(argv[4]));
            printf("Area of rectangle is %.2f\n",AREA(l,w));
        }
    }
    else
        printf("Proper coordinates are not entered.\nPlease enter the coordinates again.");
}
