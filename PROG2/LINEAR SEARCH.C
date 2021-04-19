#include <stdio.h>
#include <time.h>
int linears(int i);
int a[5],key;
void main()
{
 int i,b;
 printf("Enter 5 numbers\n");
 for(i=0;i<=4;i++)
 {
     scanf("%d",&a[i]);
 }
 printf("Enter the number to be searched\n");
 scanf("%d",&key);
 clock_t start,end;
 start=clock();
 b=linears(0);
 end=clock();
 printf("Time taken:%f\n",(((double)(end-start))/CLOCKS_PER_SEC));
 if(b==5)
 printf("Number not found\n");
 else
 printf("Number found at position: %d\n",b+1);
}
int linears(int i)
{
    if(i==5)
    return 5;
    else if(a[i]==key)
    return i;
    else
    linears(++i);
}


