#include <stdio.h>
#include<stdlib.h>
int linearSearch(int a[],int key,int size)
{
    for(int i=0;i<size;i++)
    {
        if(a[i]==key) return i;
    }
    return -1;
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
    printf("enter value to find:");
    scanf("%d",&value);
   int array= linearSearch(a,value,n);
   if(array==-1){
    printf("not found\n");
   }else{
    printf("index at position: %d",array);
   }

}