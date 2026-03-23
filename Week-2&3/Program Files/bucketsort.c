#include <stdio.h>

void bucketSort(int a[], int n) {
    int b[101]={0};
    for(int i=0;i<n;i++) b[a[i]]++;
    int k=0;
    for(int i=0;i<101;i++)
        while(b[i]--) a[k++]=i;
}

int main() {
    int n;
    printf("Enter size: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements (0-100): ");
    for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    }
    printf("Before sorting: ");
    for(int i=0;i<n;i++){ 
    printf("%d ",a[i]);
    }
    bucketSort(a,n);
    printf("\nAfter Bucket Sort: ");
    for(int i=0;i<n;i++) {
    printf("%d ",a[i]);
    }
    return 0;
}

