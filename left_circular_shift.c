#include<stdio.h>
#include<stdlib.h>

void decToBinary(short int num)
{

    int i;
    printf("\n");
    for(i=15;i>=0;i--)
    {
        printf("|%d|",((num >> i) & 1));
    }
    printf("\n");
}


int main (void)
{
    unsigned short int num = 65245;
    int bits = 4;
    //printf ("%08x\n", from);
    //reverse bytes cd and ab
    decToBinary(num);
    num = (num << bits) | (num >> (16-bits));
    decToBinary(num);
    return 0;

}
