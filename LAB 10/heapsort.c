#include<stdio.h>  
#include <time.h>
#include <stdlib.h>
void heapify(int arr[], int size, int i)  
{   
    int temp;  
    int largest = i;    
    int left = 2*i + 1;    
    int right = 2*i + 2;    
    
    if (left < size && arr[left] > arr[largest])  
        largest = left;  
    
    if (right < size && arr[right] > arr[largest])  
        largest = right;  
    
    if (largest != i)
    {
        temp = arr[i];  
        arr[i]= arr[largest];   
        arr[largest] = temp;  
        heapify(arr, size, largest);  
    }  
}  
  
void heapSort(int arr[], int size)  
{  
    int i, temp;  
    for (i = size / 2 - 1; i >= 0; i--)  
        heapify(arr, size, i);  
    for (i=size-1; i>=0; i--)  
    {  
        temp = arr[0];  
        arr[0]= arr[i];   
        arr[i] = temp;  
        heapify(arr, i, 0);  
    }
}  
void generateArray(int arr[],int n) {
    for(int i=0;i<n;i++)
        arr[i] = (rand()%n) - (n/2);// -(n/2) to +(n/2)
}
void test(int arr[], int n) {
    int i=0;
    for(i=0;i<n-1;i++) {
        if(arr[i]>arr[i+1])
        {
            printf("  ERROR  \n");
            return;
        }
    }
    printf("  SORTED  \n");
}

void main() {
    srand(time(NULL));
    int n = 0;
    int s,e,step;
    printf("-----Heap Sort-----\n\n");
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
     heapSort(arr, i);
     end=clock();
     res = ((double) (end - start)) / CLOCKS_PER_SEC;
     printf("\nn = %d\nTime taken by heap sort : %lf",i,res);
     test(arr, i);
    }
    printf("\n\n");
}

// void main()  
// {  
//     int arr[] = {5, 2, 25, -100, 66};  
//     int i;  
//     int size = sizeof(arr)/sizeof(arr[0]);  
    
//     heapSort(arr, size);  
    
//     printf("Sorted array;\n");  
//     for (i=0; i<size; ++i)  
//         printf("%d\n",arr[i]);  
// }  
