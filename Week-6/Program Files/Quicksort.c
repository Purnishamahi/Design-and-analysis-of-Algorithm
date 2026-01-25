#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* ---------- FIRST ELEMENT AS PIVOT ---------- */
int partitionFirst(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1, j = high;

    while (i <= j) {
        while (i <= high && a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j)
            swap(&a[i], &a[j]);
    }
    swap(&a[low], &a[j]);
    return j;
}

/* ---------- LAST ELEMENT AS PIVOT ---------- */
int partitionLast(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return i + 1;
}

/* ---------- RANDOM ELEMENT AS PIVOT ---------- */
int partitionRandom(int a[], int low, int high) {
    int randIndex = low + rand() % (high - low + 1);
    int pivot = a[randIndex];
    int i = low, j = high;

    while (i <= j) {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j) {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    }
    return i;
}

/* ---------- QUICK SORT ---------- */
void quickSort(int a[], int low, int high, int choice) {
    if (low < high) {
        int p;
        if (choice == 1) {
            p = partitionFirst(a, low, high);
            quickSort(a, low, p - 1, choice);
            quickSort(a, p + 1, high, choice);
        }
        else if (choice == 2) {
            p = partitionLast(a, low, high);
            quickSort(a, low, p - 1, choice);
            quickSort(a, p + 1, high, choice);
        }
        else if (choice == 3) {
            p = partitionRandom(a, low, high);
            quickSort(a, low, p - 1, choice);
            quickSort(a, p, high, choice);
        }
    }
}

int main() {
    int n, choice, cont = 1;

    srand(time(NULL));

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int original[n], a[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &original[i]);

    while (cont) {

        // Copy original array so sorting can be repeated
        for (int i = 0; i < n; i++)
            a[i] = original[i];

        printf("\n--- QUICK SORT MENU ---\n");
        printf("1. First Element as Pivot\n");
        printf("2. Last Element as Pivot\n");
        printf("3. Random Element as Pivot\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting program...\n");
            break;
        }

        quickSort(a, 0, n - 1, choice);

        printf("Sorted Array:\n");
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");

        printf("\nDo you want to choose another option?\n");
        printf("1. Yes\n2. No\nEnter choice: ");
        scanf("%d", &cont);
    }

    return 0;
}
