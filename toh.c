#include<stdio.h>
void TOH(int n, char src, char temp, char dest) 
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", src, dest); 
    }
    else
    {
    TOH(n - 1, src, dest, temp);
    printf("Move disk %d from %c to %c\n", n, src, dest);
    TOH(n - 1, temp, src, dest);
}
}

int main() 
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("The sequence of moves for %d disks:\n", n);
    TOH(n, 'A', 'B', 'C');

    return 0;
}
