#include <iostream>
#include "quicksort.h"

int main() {
//    std::cout << "Hello, World!" << std::endl;
    int arr[] = {5, 6, 3, 2, 1, 4, 7, 8, 9, 11, 14, 19, 10, 15, 17, 20};
    quicksort(arr, 0, 15);
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}