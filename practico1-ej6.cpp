#include <stdio.h>

int* ordenarPorInsercion(const int* arr, int size) {
    int* newArr = new int[size];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }

    for (int i = 1; i < size; i++) {
        int key = newArr[i];
        int j = i - 1;
        while (j >= 0 && newArr[j] > key) {
            newArr[j + 1] = newArr[j];
            j = j - 1;
        }
        newArr[j + 1] = key;
    }

    return newArr;
}

int main() {
    int size;
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &size);

    int* arr = new int[size];
    printf("Ingrese los elementos del arreglo:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Arreglo antes de ordenar: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int* sortedArr = ordenarPorInsercion(arr, size);

    printf("Arreglo después de ordenar: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortedArr[i]);
    }
    printf("\n");

    delete[] arr;
    delete[] sortedArr;

    return 0;
}
