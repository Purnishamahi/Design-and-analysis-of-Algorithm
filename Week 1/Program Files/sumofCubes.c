#include <stdio.h>

int sumOfCubes(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i * i;
    }
    return sum;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Sum of cubes of first %d natural numbers is: %d\n", n, sumOfCubes(n));
    return 0;
}
