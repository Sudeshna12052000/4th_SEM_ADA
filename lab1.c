#include <stdio.h>
int gcd(int, int);
void towers(int, char, char, char);

int main() 
{
    int n1, n2,num;
    printf("Enter two positive integers: ");
    scanf("%d %d", &n1, &n2);
    printf("G.C.D of %d and %d is %d.\n", n1, n2, gcd(n1, n2));

    printf("Enter the number of disks : ");
    scanf("%d", &num);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(num, 'A', 'C', 'B');
    
    return 0;
}

int gcd(int n1, int n2) 
{
    if (n2 != 0)
        return gcd(n2, n1 % n2);
    else
        return n1;
}


void towers(int num, char frompeg, char topeg, char auxpeg)
{
    if (num == 1)
    {
        printf("\n Move disk 1 from peg %c to peg %c", frompeg, topeg);
        return;
    }
    towers(num - 1, frompeg, auxpeg, topeg);
    printf("\n Move disk %d from peg %c to peg %c", num, frompeg, topeg);
    towers(num - 1, auxpeg, topeg, frompeg);
}
