#include "radixSort.h"

void countingSort(unsigned int arr[], int n, int exp) {
    unsigned int *output = (unsigned int*)malloc(n * sizeof(unsigned int));
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);
}

void radixSort(unsigned int arr[], int n) {
    if (n <= 1) return;

    unsigned int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

void radixSortWithDigits(unsigned int arr[], int n, int numDigits) {
    if (n <= 1 || numDigits <= 0) return;

    int exp = 1;
    for (int d = 0; d < numDigits; d++) {
        countingSort(arr, n, exp);
        exp *= 10;
    }
}

int isSorted(unsigned int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            return 0;
        }
    }
    return 1;
}

void generateArray(unsigned int arr[], int n, int digits) {
    unsigned int maxVal = 1;
    for (int i = 0; i < digits; i++) {
        maxVal *= 10;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % maxVal;
    }
}

void generatePartiallySortedArray(unsigned int arr[], int n, int degreeOfOrder) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    int swaps = (n * (100 - degreeOfOrder)) / 100;
    for (int s = 0; s < swaps; s++) {
        int i = rand() % n;
        int j = rand() % n;
        unsigned int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void copyArray(unsigned int dest[], unsigned int src[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}
