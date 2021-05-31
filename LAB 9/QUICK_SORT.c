#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the correct index of pivot lement
int partition(int array[], int low, int high) {
  
  
  int pivot = array[high];// selecting the a[high] (rightmost) element as pivot
  int i = (low - 1); //points to first greater element visited

  
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) { 
      // if element smaller than pivot is found, swap it with the first greater element visited, pointed by i
      i++;
      
      if(i!=j)
        swap(&array[i], &array[j]);
    }
  }

  
  if(i+1!=high)
  swap(&array[i + 1], &array[high]);// swap the pivot element with the greater element at i
  
  
  return (i + 1);// return the partition point
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
    printf("  OK  \n");
}
void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    int pivotIndex = partition(array, low, high);// finding the correct index of the pivot element
    
    quickSort(array, low, pivotIndex - 1);// recursive call on the left of pivot
    
    quickSort(array, pivotIndex + 1, high);// recursive call on the right of pivot
  }
}

void generateArray(int arr[],int n) {
    for(int i=0;i<n;i++)
        arr[i] = (rand()%100) - 50;// -50 to 50
}

void main() {
    srand(time(NULL));
    int n =0;
    int s,e,step;
    printf("-----Quick Sort-----\n\n");
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
     quickSort(arr,0, i-1);
     end=clock();
     res = ((double) (end - start)) / CLOCKS_PER_SEC;
     printf("\nn = %d\nTime taken by quick sort : %lf",i,res);
     test(arr, i);
    }
    printf("\n\n");
}
