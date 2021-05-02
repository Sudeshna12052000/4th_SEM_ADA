#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int status;

int linearSearch(int arr[], int n, int key) {
    int res=-1;
    status = -1;
    for(int i = 0;i < n;i++) {
        if(arr[i] == key) {
            status=0;
            res=i;
            break;
        }
    }
    return res;
}
void sortArray(int arr[], int n) {
    for(int b=0;b<n;b++) {
        for(int e=b+1;e<n;e++) {
            if(arr[b]>arr[e]){
                arr[b] = arr[b]+arr[e];
                arr[e] = arr[b]-arr[e];
                arr[b] = arr[b]-arr[e];
            }
        }
    }
}
int binarySearch(int arr[], int n, int key) {
    int res;
    status=-1;
    int b=0,m=0,e=0;
    //Sort first
    
    b = 0;
    e = n-1;
    
    while(b<e) {
        m = b + (e-b)/2;
        if(arr[m]==key) {
            res=m;
            status=0;
            break;
        }
        else if(arr[m]>key)
            e=m-1;
        else
            b=m+1;
    }
    return res;
}

int main() {
    int l;
    printf("Enter length of random array : ");
    scanf("%d",&l);
    int arr[l];
    int key = (rand()%100) - 50;
    for(int i = 0;i<l;i++) {
        arr[i] = (rand()%100) - 50;
    }
    double resl,resb;
    clock_t start, end;

    start = clock();
    int li = linearSearch(arr, l, key);
    end = clock();
    resl = ((double) (end - start)) / CLOCKS_PER_SEC;

    

    start = clock();
    sortArray(arr,l);
    int bi = binarySearch(arr, l, key);
    end = clock();
    resb = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nKey : %d\n",key);

    printf("\n--LINEAR SEARCH---\n");
    if(status==0) {
        printf("\n%d found at index %d\n", key,li);
    }
    else {
        printf("\n%d not found in array\n",key);
    }
    printf("\nTime taken by linear search : %lf\n", resl);
    
    printf("\n---BINARY SEARCH---\n");  
    if(status==0) {
        printf("\n%d found at index %d\n", key,bi);
    }
    else {
        printf("\n%d not found in array\n",key);
    }
    printf("\nTime taken by binary search : %lf\n", resb);
}
