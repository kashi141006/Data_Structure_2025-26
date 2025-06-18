#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
int main()
{
    int n;
    printf("enter the number of words:");
    scanf("%d", &n);
    char words[n][100];
    for (int i = 0; i < n; i++)
    {

        printf("enter words:");
        scanf("%s", &words[i]);
    }
    srand(time(0));
    int index = rand() % n;
    printf("random:%s", words[index]);
    char check[100];
    printf("\nenter word to check:");
    scanf("%s", &check);

    char temp1[100], temp2[100];
    strcpy(temp1, words[index]);
    strcpy(temp2, check);

    int len1 = strlen(temp1);  //sorting array
    int len2 = strlen(temp2);
char t; 
    for (int i = 0; i < len1-1; i++)
    {
        for(int j=i+1;j<len1;j++){
            if(temp1[i]>temp1[j])
            {
                  t=temp1[i];
                temp1[i]=temp1[j];
                temp1[j]=t;
            }
            if(temp2[i] > temp2[j]) 
            {
                 t=temp2[i];
                temp2[i]=temp2[j];
                temp2[j]=t; 
            }
        }
    }
    if(strcmp(temp1,temp2)==0)
    {
        printf("Word is anagram\n");

    }
    else{
        printf("Word is not anagram\n");
    }

    return 0;
}