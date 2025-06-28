 #include<stdio.h>
 #include<stdlib.h>
 struct node{
    int info;
    struct node *link;
 };
 struct node *newNode=NULL;
 void printData(){
    int x;
    newNode=(struct node *)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("failed");
    }
    printf("Enter Value:");
    scanf("%d",&x);
    newNode->info=x;
    newNode->link=NULL;
 }
 void display(){
    if(newNode==NULL)
    {
     printf("Linked List is empty\n");
    }
    printf("data:%d",newNode->info);
 }
 void main(){
    printData();
    display();
 }