#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compute(int a, int b) {
    if(a%b==0) {
        return b;
    }
    else {
        return compute(b,a%b);
    }
}

void main() {
    srand(time(NULL));
    clock_t start, end;
    int a = (rand()%100) + 1;
    int b = (rand()%100) + 1;
    start = clock();
    int ans = compute(a,b);
    end = clock();
    double res = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\na = %d, b = %d, GCD = %d",a,b,ans);
    printf("\nTime taken : %lf\n\n",res);
}
