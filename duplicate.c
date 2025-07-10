 #include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
 
 struct node *first=NULL;

void insertAtOrd(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    if (first == NULL || x <= first->info)
    {

        newNode->link = first;
        first = newNode;
        return;
    }
    else
    {  
        struct node *save = first;
         while (save->link != NULL && x >= save->link->info)
        {
            save = save->link;
        }
        newNode->link = save->link;
        save->link = newNode;
    }
}
void removeDuplicate()
{
    struct node *save = first;
    struct node *ptr;
    while (save!=NULL && save->link!=NULL)
    {
         if(save->info==save->link->info)
         {
            ptr=save->link->link;
            free(save->link);
            save->link=ptr;
         }else{
            save=save->link;
         }
    }
    
}
void display()
{  
    struct node *save=first;
    if (save == NULL)
    {
        printf("empty");
        return;
    }
    while (save!= NULL)
    {
        printf("%d->",save->info);
        save= save->link;
    }
    printf("NULL\n");
}
void countValue(int x) {
    int count = 0;
    struct node *save = first;
    while (save != NULL) {
        if (save->info == x) {
            count++;
        }
        save = save->link;
    }
    printf("%d is repeated %d times\n", x, count);
}

void main(){
  int n,x;
  printf("Enter Node:");
  scanf("%d",&n);
for(int i=0;i<n;i++)
{
    printf("enter value:");
    scanf("%d",&x);
    insertAtOrd(x);
    

}
printf("Linked List\n");
display();
 printf("\nFrequency Count:\n");
    struct node *save = first;
    while (save != NULL) {
        countValue(save->info);
         
        int val = save->info;
        while (save != NULL && save->info == val) {
            save = save->link;
        }
    }
printf("After Remove Duplicate Linked List\n");
removeDuplicate();
display();
}