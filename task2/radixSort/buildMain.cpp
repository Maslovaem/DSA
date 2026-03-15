#include "radixSort.h"

#include <algorithm>

double getTimeInSeconds() {
    clock_t time = clock();
    return ((double)time) / CLOCKS_PER_SEC;
}

void runStdSort(unsigned int arr[], int n) {
    std::sort(arr, arr + n);
}

void writeResultsToCSV(const char* filename,
                       int arraySizes[], int numSizes,
                       int digits[], int numDigits,
                       int degreesOfOrder[], int numDegrees,
                       double results[][5][5][2]) { // [size][digit][degree][algorithm]
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }

    fprintf(file, "ArraySize,Digits,OrderDegree,RadixSortTime,StdSortTime\n");

    for (int s = 0; s < numSizes; s++) {
        for (int d = 0; d < numDigits; d++) {
            for (int o = 0; o < numDegrees; o++) {
                fprintf(file, "%d,%d,%d,%.6f,%.6f\n",
                        arraySizes[s],
                        digits[d],
                        degreesOfOrder[o],
                        results[s][d][o][0], // Radix Sort
                        results[s][d][o][1]); // std::sort
            }
        }
    }

    fclose(file);
    printf("Results saved to %s\n", filename);
}

int main() {
    int arraySizes[] = {100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000};
    int numSizes = sizeof(arraySizes) / sizeof(arraySizes[0]);

    int digits[] = {1, 2, 3, 4, 5};
    int numDigits = sizeof(digits) / sizeof(digits[0]);

    int degreesOfOrder[] = {0, 25, 50, 75, 100};
    int numDegrees = sizeof(degreesOfOrder) / sizeof(degreesOfOrder[0]);

    //Количество повторений для усреднения
    int numTrials = 3;

    double results[numSizes][5][5][2];

    srand(time(NULL));

    printf("Starting performance comparison...\n");
    printf("Array sizes: ");
    for (int i = 0; i < numSizes; i++) {
        printf("%d ", arraySizes[i]);
    }
    printf("\n");

    for (int s = 0; s < numSizes; s++) {
        int currentSize = arraySizes[s];
        printf("\nTesting size: %d\n", currentSize);

        for (int d = 0; d < numDigits; d++) {
            int currentDigits = digits[d];
            printf("  Digits: %d\n", currentDigits);

            for (int o = 0; o < numDegrees; o++) {
                int currentDegree = degreesOfOrder[o];
                printf("    Order degree: %d%%\n", currentDegree);

                unsigned int* originalArray = (unsigned int*)malloc(currentSize * sizeof(unsigned int));
                unsigned int* testArray1 = (unsigned int*)malloc(currentSize * sizeof(unsigned int));
                unsigned int* testArray2 = (unsigned int*)malloc(currentSize * sizeof(unsigned int));

                double totalTimeRadix = 0;
                double totalTimeStdSort = 0;

                for (int trial = 0; trial < numTrials; trial++) {
                    if (currentDegree == 0) {
                        generateArray(originalArray, currentSize, currentDigits);
                    } else {
                        generatePartiallySortedArray(originalArray, currentSize, currentDegree);
                    }

                    copyArray(testArray1, originalArray, currentSize);
                    double startTime = getTimeInSeconds();
                    radixSort(testArray1, currentSize);
                    double endTime = getTimeInSeconds();
                    totalTimeRadix += (endTime - startTime);

                    if (!isSorted(testArray1, currentSize)) {
                        printf("      WARNING: Radix sort failed at trial %d!\n", trial);
                    }

                    copyArray(testArray2, originalArray, currentSize);
                    startTime = getTimeInSeconds();
                    runStdSort(testArray2, currentSize);
                    endTime = getTimeInSeconds();
                    totalTimeStdSort += (endTime - startTime);
                }

                //Усреднение результатов
                results[s][d][o][0] = totalTimeRadix / numTrials;
                results[s][d][o][1] = totalTimeStdSort / numTrials;

                free(originalArray);
                free(testArray1);
                free(testArray2);

                printf("      Times: Radix=%.4fs, StdSort=%.4fs\n",
                       results[s][d][o][0], results[s][d][o][1]);
            }
        }
    }

    writeResultsToCSV("sort_comparison_results.csv",
                      arraySizes, numSizes,
                      digits, numDigits,
                      degreesOfOrder, numDegrees,
                      results);

    printf("\nPerformance comparison completed!\n");
    return 0;
}
