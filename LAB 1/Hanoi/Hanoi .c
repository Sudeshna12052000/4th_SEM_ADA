#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void tower(int n, char src, char dest, char supp) {
    if(n>1) {
        tower(n-1, src, supp, dest);
        tower(1, src, dest, supp);
        tower(n-1, supp,dest,src);
    }
    printf("Move %c to %c using %c\n", src, dest, supp);
}

void main() {
    srand(time(NULL));
    double res;
    clock_t start, end;
    int n = (rand()%4) + 1;
    printf("\nn = %d\n", n);
    printf("\nSolution;\n");
    start = clock();
    tower(n,'A','C','B');
    end = clock();
    res = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("--------------");
    printf("\nTime taken : %lf\n\n",res);
    printf("--------------\n\n");

}
