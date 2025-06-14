 #include <stdio.h>
int main(){
  int n;
  int a[100];
  printf("enter number:");
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    printf("enter element:");
    scanf("%d",&a[i]);
  }
  int loc,n1;
  printf("location and inserted element: ");
  scanf("%d %d",&loc,&n1);
  for(int i=n;i>=loc;i--){
     a[i]=a[i-1];
     if(i==loc){
        a[loc]=n1;
        n++;
     }
      
  }
   for(int i=0;i<n;i++){
    printf("%d  ",a[i]);

   }

}