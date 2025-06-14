#include <stdio.h>
int main()
{
    int s, e;
    printf("enter number:");
    scanf("%d", &s);
    printf("enter number:");
    scanf("%d", &e);
    for (int i = s+1; i < e; i++)
    { 
        int count=0;

        for (int j = 1; j <=i ; j++)
        {
            
            if (i% j == 0)
            {
                count++;
            }
        }
        if(count==2){
            printf("%d ,",i);
        }
    }
   
}