#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int arr[], int n) 
{ 
    int i, j; 
    for (i = 0; i < n-1; i++)     
      
    for (j = 0; j < n-i-1; j++) 
        if (arr[j] > arr[j+1]) {
            arr[i] = arr[i]+arr[j];
            arr[j] = arr[i]-arr[j];
            arr[i] = arr[i]-arr[j];
        }
} 

void generateArray(int arr[],int n) {
    for(int i=0;i<n;i++)
        arr[i] = (rand()%100) - 50; // -50 to 50
}

void main() {
    srand(time(NULL));
    printf("-----Bubble Sort-----\n\n");

    int n =0;
    int s,e,step;
    printf("Enter start length : ");
    scanf("%d",&s);
    printf("Enter end length : ");
    scanf("%d",&e);
    printf("Enter step length : ");
    scanf("%d",&step);

    for(int i=s;i<=e;i=i+step) {
        int arr[i];
        generateArray(arr, i);
        double res;
        clock_t start, end;
        start=clock();
        sort(arr,i);
        end=clock();
        res = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("\nn = %d\nTime taken by bubble sort : %lf",i,res);
    }
    printf("\n\n");
}
