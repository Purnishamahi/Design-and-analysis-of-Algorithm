#include <stdio.h>

void insertionSort(int a[], int n) {
    for(int i=1;i<n;i++) {
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
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
    insertionSort(a,n);
    printf("\nAfter Insertion Sort: ");
    for(int i=0;i<n;i++){ 
    printf("%d ",a[i]);
    }
    return 0;
}

