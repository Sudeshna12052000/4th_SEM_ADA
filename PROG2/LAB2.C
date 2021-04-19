#include <stdio.h>
#include<time.h>
int binaryS(int,int);
int a[10],key;
void main()
{
    int i,b;
    clock_t start,end;
    start=clock();
    printf("Enter 10 numbers in ascending order\n");
    for(i=0;i<=9;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the number to be searched\n");
    scanf("%d",&key);
    b=binaryS(0,9);
    end=clock();
    printf("Time taken:%f\n",(((double)(end-start))/CLOCKS_PER_SEC));
    if(b==-1)
    {
        printf("Number not found\n");
    }
    else 
    {
        printf("Number %d found at position:%d",key,(b+1));
    }
}
int binaryS(int f,int l)
{
    int m;
    m=((f+l)/2);
    if(key==a[m])
    {
        return m;
    }
    else if(key>a[m])
    {
        return binaryS(++m,l);
    }
    else if(key<a[m])
    {
        return binaryS(f,--m);
    }
    else if(f>l)
    {
        return -1;
    }
}
