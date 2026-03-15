#include "bubbleSort.h"

void swap(int *a, int *b)
{
    int tempVal = *a;
    *a = *b;
    *b = tempVal;
}

void BubbleSortDefault(int data[], int n)
{
    int end = n - 1;
    int temp_val;

    for (int i = 0; i < end; i++) {
        for (int j = 0; j < end - i; j++) {
            if (data[j] > data[j + 1]) {
                swap(&data[j], &data[j+1]);
            }
        }
    }
}

void BubbleSortWithCheck(int data[], int n)
{
    int end = n - 1;
    int temp_val;
    bool flag;

    for (int i = 0; i < end; i++) {
        flag = false;
        for (int j = 0; j < end - i; j++) {
            if (data[j] > data[j + 1]) {
                swap(&data[j], &data[j+1]);
                flag = true;
            }
        }

        if (!flag)
            break;
    }
}

void ShakerSort(int data[], int n)
{
    int start = 0;
    int end = n - 1;
    bool flag = true;
    int temp_val;

    while (flag) {
        flag = false;

        for (int i = start; i < end; ++i) {
            if (data[i] > data[i + 1]) {
                swap(&data[i], &data[i + 1]);
                flag = true;
            }
        }

        if (!flag)
            break;

        flag = false;

        --end;

        for (int i = end - 1; i >= start; --i) {
            if (data[i] > data[i + 1]) {
                swap(&data[i], &data[i + 1]);
                flag = true;
            }
        }

        ++start;
    }
}

void combSort(int data[], int n) {
    int step = n;
    bool flag = false;
    float factor = 1.25;

    while (step > 1 || flag) {
        if (step > 1) {
            step = (int)(step / factor);
        }

        flag = false;
        int i = 0;
        while (i + step < n) {
            if (data[i] > data[i + step]){
                flag = true;
                swap(&data[i], &data[i + step]);
            }
            i += step;
        }
    }
}
