 #include <stdio.h>

int main() {
    int n;
    int a[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element : ");
        scanf("%d", &a[i]);
    }

    int n1, loc= 0;
    printf("Enter element to delete: ");
    scanf("%d", &n1);
 
    for (int i = 0; i < n; i++) {
        if (a[i] == n1) {
            loc = 1;
            for (int j = i; j < n - 1; j++) {
                a[j] = a[j + 1];  
            }
            n--;  
            break; 
        }
    }

    if (loc) {
         
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
    } 

    return 0;
}
