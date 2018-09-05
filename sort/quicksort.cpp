//
// Created by Tony on 2018/6/9.
//

#include "quicksort.h"
#include "common.h"

int partition(int source[], int left, int right, int pivot)
{
    int pivot_value = source[pivot];
    swap(&source[pivot], &source[right]);
    int store_index = left;
    for (int i = left; i < right ; i++)
    {
        if (source[i] <= pivot_value)
        {
            swap(&source[store_index], &source[i]);
            store_index++;
        }
    }
    swap(&source[store_index], &source[right]);
    return store_index;
}

void quicksort(int source[], int left, int right)
{
    if (right > left)
    {
        int init_pivot = (right - left) / 2 + left;
        int new_part = partition(source, left, right, init_pivot);
        quicksort(source, left, new_part - 1);
        quicksort(source, new_part + 1, right);
    }
}