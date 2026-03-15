#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void radixSort(unsigned int arr[], int n);
void radixSortWithDigits(unsigned int arr[], int n, int numDigits);
int  isSorted(unsigned int arr[], int n);
void generateArray(unsigned int arr[], int n, int digits);
void generatePartiallySortedArray(unsigned int arr[], int n, int degreeOfOrder);
void copyArray(unsigned int dest[], unsigned int src[], int n);

#endif //RADIXSORT_H
