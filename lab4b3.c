#include <stdio.h>
void main()
{
    int n1,n2,i,j;
    printf("enter array size:");
    scanf("%d", &n1);
    int a[50],b[50],c[100];
    for (i = 0; i < n1; i++)
    {
        printf("enter element:");
        scanf("%d", &a[i]);
    }
        printf("enter array size:");
    scanf("%d", &n2);
     for ( i = 0; i < n2; i++)
    {
        printf("enter element:");
        scanf("%d", &b[i]);
    }
    for( i=0;i<n1;i++){
        c[i]=a[i];
    }
    for( j=0;j<n2;j++){
        
        c[i+j]=b[j];
    }
        printf("merged array:");
    for( i=0;i<n1+n2;i++){
        printf("%d ",c[i]);
    }


}