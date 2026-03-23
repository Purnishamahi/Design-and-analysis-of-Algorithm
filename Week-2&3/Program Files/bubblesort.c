#include <stdio.h>

void bubbleSort(int a[], int n) {
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (a[j] > a[j+1]) {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
            }
            }
}

int main() {
    int n;
    printf("Enter size: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements: ");
    for(int i=0;i<n;i++) {
    scanf("%d",&a[i]);
    }
    printf("Before sorting: ");
    
    for(int i=0;i<n;i++) {
    printf("%d ",a[i]);
    }
    bubbleSort(a,n);
    printf("\nAfter Bubble Sort: ");
    
    for(int i=0;i<n;i++) {
    printf("%d ",a[i]);
    }
    return 0;
}

