#include <stdio.h>

int s[100];
int top = -1;

void push(int x) {
    if (top >= 99)
        printf("stack overflow\n");
    else
        s[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("underflow\n");
        return -1;
    } else {
        return s[top--];
    }
}

int peep() {
    if (top == -1) return -1;
    return s[top];
}

int check(int a[], int n) {
    int b[100];
    int index = 0;
    int expected = 1;
    top = -1; // reset stack

    for (int i = 0; i < n; i++) {
        push(a[i]);
        while (top != -1 && peep() == expected) {
            b[index++] = pop();
            expected++;
        }
    }

    while (top != -1) {
        b[index++] = pop();
    }

      

    return expected == n + 1;
}

int main() {
   int a[] = {1, 2, 4, 3}; //yes
    //int a[] = {1, 3, 4, 2};  //no 
    int n = 4;

    if (check(a, n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
