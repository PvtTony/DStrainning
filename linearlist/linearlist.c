#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"linearlist.h"

LinearList *initList(LinearList **pnt, int maxSize) {
    if (maxSize == 0) {
        return NULL;
    }
    LinearList *list = (LinearList*)malloc(sizeof(LinearList));
    list->data = (int*)malloc(sizeof(int) * maxSize);
    list->length = 0;
    list->maxSize = maxSize;
    if (*pnt == NULL) {
        *pnt = list;
    }
    return list;
}

bool isEmpty(LinearList *list) {
    return list == NULL;
}

void add(LinearList *list, int itemValue) {  
    if (!isEmpty(list)) {
        if (list->maxSize != 0) {
            int len = list->length;
            if (len >= list->maxSize) {
                resize(list);
                // printf("List expanded.\n");
            }
            list->data[len] = itemValue;
            len++;
            list->length = len;
        }
    }
}

int getLinearListLength(LinearList *list) {
    if (!isEmpty(list)) {
        return list->length;
    }
    return 0;
}

int getItemIdx(LinearList *list, int itemValue) {
    if (!isEmpty(list)) {
        int len = list->length;
        int *data = list->data;
        if (len != 0) {
            for (int i = 0; i < len; i++) {
                if (itemValue == data[i]) {
                    return i;
                }
            }
        }
    }
    return -1;
}

int getItemByIdx(LinearList *list, int idx) {
    if (!isEmpty(list)) {
        int len = list->length;
        int *data = list->data;
        if (len != 0 && idx < list->length) {
            return data[idx];
        }
    }
    return 0;
}

void insert(LinearList *list, int itemValue, int idx) {
    if (!isEmpty(list)) {
        if (idx < 0 || idx > list->maxSize) {
            return ;
        }
        if (idx == list->maxSize) {
            add(list, itemValue);
            return ;
        }
        int len = list->length, mxsize = list->maxSize;
        if (len >= mxsize) {
            resize(list);
        }
        for (int i = len; i > idx; i--) {
            (list)->data[i] = (list)->data[i - 1];
        }
        (list)->data[idx] = itemValue;
        (list)->length++;
    }
}

void delByIdx(LinearList *list, int idx) {
    if (!isEmpty(list)) {
        if (idx < 0 || idx > list->maxSize) {
            return ;
        }
        if (idx == list->length - 1) {
            list->data[idx] = 0;
            return ;
        }
        list->data[idx] = 0;
        for (int i = idx; i < list->length - 1; i++) {
            list->data[i] = list->data[i + 1];
        }
        list->length--;
        return ;
    }
}

void resize(LinearList *list) {
    if (!isEmpty(list)) {
        int currentLen = (list)->length;
        int *currentData = (list)->data;
        int newMaxSize = (list)->maxSize * SIZE_INCREASE_MULTIPLIER;
        int *newdata = (int*) malloc(sizeof(int) * newMaxSize);
        memcpy(newdata, currentData, currentLen * sizeof(int));
        free(currentData);
        (list)->data = newdata;
        (list)->maxSize = newMaxSize;
    }
}

void freeList(LinearList **list) {
    if (!isEmpty(*list)) {
        free((*list)->data);
        free(*list);
    }
}

void printList(LinearList *list) {
    if (!isEmpty(list)) {
        printf("Printing list: ");
        int len = list->length;
        int *data = list->data;
        if (len != 0) {
            for (int i = 0; i < len; i++) {
                printf(i != len -1 ? "%d, " : "%d\n", data[i]);
            }
        // printf("End of List \n");
        }
    }
}

int main(int argc, char* argv[]) {
    LinearList *test;
    initList(&test, 5);
    add(test, 1);
    add(test, 2);
    add(test, 3);
    add(test, 5);
    add(test, 6);
    printList(test);
    add(test, 7);
    insert(test, 4, 3);
    printList(test);
    delByIdx(test, 0);
    printList(test);
    int idx = getItemIdx(test, 5);
    printf("Value 5 idx = %d\n", idx);
    freeList(&test);
}