#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define n 10
struct pair{
    char key[10];
    int value;

};
struct pair hashMap[n];
int function(char key[])
{  int index=0;
    for(int i=0;i<strlen(key);i++)
    {
        index=index+key[i];

    }
    return index%n;
}
void add(char k[],int v)
{
    int index=function(k);
    if(hashMap[index].key[0]=='\0'){
        strcpy(hashMap[index].key,k);
        hashMap[index].value=v;
        return;
    }
    else if(strcmp(hashMap[index].key,k)==0){
        hashMap[index].value=v;
        return;
    }
    else{
        for(int probe=1;probe<n;probe++){
            int i=((index+probe)%n);
            if(hashMap[i].key[0]=='\0')
            {
                strcpy(hashMap[i].key,k);
                hashMap[i].value=v;
                return;
            }
            if(strcmp(hashMap[i].key,k)==0)
            {
                hashMap[i].value=v;
                return;
            }
        }
    }
}
void display()
{    
    for (int i = 0; i < n; i++)
    {
        printf(" index: %d   %s : %d  \n",i,hashMap[i].key, hashMap[i].value);
    }
}

void main()
{
    int choice;
    int x;
     char k[10];
    while (1)
    {
        printf("\n1.insert elemnet\n");
        printf("2.display\n");
        printf("3.exit\n");
        printf("enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf(" enter element:");
             scanf("%d",&x);
             printf("entr key:");
             scanf("%s",k);
           add(k,x);
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
        }
    }+
}