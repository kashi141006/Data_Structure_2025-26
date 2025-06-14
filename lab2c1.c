

#include <stdio.h>
#include <math.h>

int main()
{
    int num, remainder, n = 0, result;

    printf("Armstrong numbers between 1 and 1000 are:\n");

    for (num = 1; num <= 1000; num++)
    {
        int temp = num;
        result = 0;
        n = 0;

        while (temp != 0)
        {
            temp /= 10;
            ++n;
        }

        temp = num;
        while (temp != 0)
        {
            remainder = temp % 10;
            result += pow(remainder, n);
            temp /= 10;
        }

        if (result == num)
        {
            printf("%d ", num);
        }
    }
    printf("\n");
    return 0;
}