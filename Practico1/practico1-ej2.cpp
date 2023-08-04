#include <stdio.h>
#include <math.h>

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    int limit = sqrt(n);
    for (int i = 5; i <= limit; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

int main() {
    int A, B;
    printf("Ingrese los valores de A y B: ");
    scanf("%d %d", &A, &B);

    printf("Números primos entre %d y %d:\n", A, B);
    for (int i = A; i <= B; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
