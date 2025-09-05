
#include <stdio.h>
#include <stdlib.h>

int bubble(int a[], int size)
{
    int last = size - 1;
    for (int i = 0; i < size - 2; i++)
    {
        int count = 0;
        for (int j = 0; j < last - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp=a[j];
                a[j] = a[j + 1];
                a[j+1]=temp;
                count++;
            }
        }
        if (count == 0)
        {
            break;
             
        }
        else
        {
            last = last - 1;
        }
    }

    printf("!---------sorted array-----!");
     for (int i=0;i<size;i++){
        printf("%d   ",a[i]);
     }
     
}
void main(){
    int n,value;
    printf("enter array size:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("enter elment:");
        scanf("%d",&a[i]);

    }
     
    bubble(a,n);
     

}