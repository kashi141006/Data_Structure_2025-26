#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
 
 struct node *first=NULL;
void insertAtEnd(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = NULL;

    if (first == NULL)
    {
        first = newNode;
    }
    else
    {
        struct node *save = first;
        while (save->link != NULL)
        {

            save = save->link;
        }
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
    if(first==NULL){
        printf("empty");
        return;
    }
    while (save!=NULL)
    {
        printf("%d->",save->info);
        save=save->link;
    }
    printf("NULL\n");
    
}

void main(){
  int n,x;
  printf("Enter Node:");
  scanf("%d",&n);
for(int i=0;i<n;i++)
{
    printf("enter value:");
    scanf("%d",&x);
    insertAtEnd(x);
}
printf("Linked List\n");
display();
printf("After Remove Duplicate Linked List\n");
removeDuplicate();
display();
}