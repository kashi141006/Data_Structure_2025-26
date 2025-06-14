#include <stdio.h>
int main()
{
    int n;
    int a[100];
    printf("enter number:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("enter element:");
        scanf("%d", &a[i]);
    }
    int loc=n, n1;
    printf("location element: ");
    scanf("%d",&n1);
    
     
  for(int i=0;i<n;i++){
    if(n1<a[i]){
          loc=i;
        printf("posi: %d\n", loc);
        break;
    }
}

 for  (int i = n; i > loc; i--) {
        a[i] = a[i - 1];
    }

  a[loc]=n1;
  n++;
 printf("inserting array in asscending order:\n");
for(int i=0;i<n;i++){
    printf("%d ",a[i]);
  
}
}