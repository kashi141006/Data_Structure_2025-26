#include <stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};
struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = value;
    newNode->lptr = NULL;
    newNode->rptr = NULL;
    return newNode;
}
 struct node *constructBST(int post[], int pre[], int *preInx, int size, int l, int h)
{
    if (*preInx > size || l>h)
    {
        return NULL;
    }
    struct node *root = createNode(pre[*preInx]);
   (*preInx)++;
    if (l == h || *preInx > size)
    {
        return root;
    }
    int k=pre[*preInx];
    int i = find(post, k, l, h);
    if (i != -1)
    {
        root->lptr = constructBST(post, pre,preInx,size, l,i);
        root->rptr = constructBST(post, pre, preInx,size, i+1, h - 1);
    }
    return root;
}

int find(int post[], int k, int l, int h)
{
    int s = l;
    for (; s <= h; s++)
    {
        if (k == post[s])
        {
            return s;
        }
    }
    if (k != post[s])
    {
        return -1;
    }
}
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->lptr);
    printf("%d", root->info);
    inorder(root->rptr);
}
int main()
{
    struct node *root;
    int size, l = 0;
    int *preInx=(int *)malloc(sizeof(int));
    *preInx=0;
    printf("enter array size:");
    scanf("%d", &size);
    int h = size - 1;
    int pre[size];
    int post[size];
    for (int i = 0; i < size; i++)
    {
        printf("enter preorder elment:");
        scanf("%d", &pre[i]);
    }
    for (int i = 0; i < size; i++)
    {
        printf("enter postorder elment:");
        scanf("%d", &post[i]);
    }
    root = constructBST(post, pre, preInx, size, l, h);
    inorder(root);

}