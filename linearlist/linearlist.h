#ifndef linearlist
#define linearlist
#define MAXSIZE 50
#define SIZE_INCREASE_MULTIPLIER 2
typedef struct {
    int data[MAXSIZE];
    int length;
} PreallocLinearList;

typedef struct {
    int *data;
    int length, maxSize;
} LinearList;

LinearList *initList(LinearList **pnt, int maxSize);
int getLinearListLength(LinearList *list);
int getItemIdx(LinearList *list, int itemValue);
int getItemByIdx(LinearList *list, int idx);
void add(LinearList *list, int itemValue);
void insert(LinearList *list, int itemValue, int idx);
void delByIdx(LinearList *list, int idx);
void printList(LinearList *list);
bool isEmpty(LinearList *list);
void freeList(LinearList **list);
void resize(LinearList *list);

#endif
