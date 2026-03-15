#include "bubbleSort.h"

int* copyArray(int source[], int n) {
    int* copy = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        copy[i] = source[i];
    }
    return copy;
}

void generatePartiallySortedArray(int data[], int n, int degreeOfOrder) {
    for (int i = 0; i < n; i++) {
        data[i] = i;
    }

    int numToShuffle = (n * (100 - degreeOfOrder)) / 100;

    for (int k = 0; k < numToShuffle; k++) {
        int i = rand() % n;
        int j = rand() % n;

        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
}

double measureTime(void (*sortFunc)(int[], int), int data[], int n) {
    int* temp = copyArray(data, n);

    clock_t start = clock();
    sortFunc(temp, n);
    clock_t end = clock();

    free(temp);
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

void saveResultsToCSV(const char* filename, int sizes[], int numSizes,
                      int degrees[], int numDegrees, double results[][6][4]) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }

    fprintf(file, "ArraySize,DegreeOfOrder,BubbleDefault,BubbleCheck,ShakerSort,CombSort\n");

    for (int s = 0; s < numSizes; s++) {
        for (int d = 0; d < numDegrees; d++) {
            fprintf(file, "%d,%d,%.6f,%.6f,%.6f,%.6f\n",
                    sizes[s], degrees[d],
                    results[s][d][0], results[s][d][1],
                    results[s][d][2], results[s][d][3]);
        }
    }

    fclose(file);
    printf("\nResults saved to %s\n", filename);
}

int main() {
    srand(time(NULL));

    int arraySizes[] = {10, 100, 1000, 10000, 100000, 1000000};
    int numSizes = sizeof(arraySizes) / sizeof(arraySizes[0]);

    int degreesOfOrder[] = {0, 20, 40, 60, 80, 100};
    int numDegrees = sizeof(degreesOfOrder) / sizeof(degreesOfOrder[0]);

    double results[6][6][4] = {0};

    for (int s = 0; s < numSizes; s++) {
        int size = arraySizes[s];

        for (int d = 0; d < numDegrees; d++) {
            int degree = degreesOfOrder[d];

            int* data = (int*)malloc(size * sizeof(int));
            generatePartiallySortedArray(data, size, degree);

            double t1, t2, t3, t4;

            //BubbleSortDefault is too slow for large data sets
            if (size > 10000)
                t1 = -1;
            else
                t1 = measureTime(BubbleSortDefault, data, size);

            t2 = measureTime(BubbleSortWithCheck, data, size);
            t3 = measureTime(ShakerSort, data, size);
            t4 = measureTime(combSort, data, size);

            results[s][d][0] = t1;
            results[s][d][1] = t2;
            results[s][d][2] = t3;
            results[s][d][3] = t4;

            free(data);
        }
    }

    //Save to CSV
    saveResultsToCSV("sorting_results.csv", arraySizes, numSizes,
                     degreesOfOrder, numDegrees, results);

    return 0;
}
