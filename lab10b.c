#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
 
 
struct node *first1 = NULL;
struct node *first2 = NULL;

void insertfirst1(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = first1;
    first1 = newnode;
    printf("node inserted\n");
}

void insertfirst2(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = first2;
    first2 = newnode;
    printf("node inserted\n");
}
 
void display1()
{

    struct node *save;
    save = first1;
    while (save != NULL)
    {
        printf("%d\n", save->info);
        save = save->link;
    }
}
void display2()
{

    struct node *save;
    save = first2;
    while (save != NULL)
    {
        printf("%d\n", save->info);
        save = save->link;
    }
}
 
void check(){
    while (first1->link!=NULL && first2->link!=NULL)
    {
         if(first1->info != first2->info){
            return;
         }
    
    first1=first1->link;
    first2=first2->link;
    }
    if(first1->link==NULL && first2->link==NULL){
        printf("same");

    }else{
        printf("not");
    }
    
}

void main()
{
    int n;
    int x;
    printf("enter node:");
    scanf("%d", &n);
     
    for (int i = 0; i < n; i++)
    {
        printf("enter value:");
        scanf("%d", &x);
        insertfirst1(x);
    }
    display1();
    printf("enter node:");
    scanf("%d", &n);
     
    for (int i = 0; i < n; i++)
    {
        printf("enter value:");
        scanf("%d", &x);
        insertfirst2(x);
    }
    display2();
    check();
     
}
