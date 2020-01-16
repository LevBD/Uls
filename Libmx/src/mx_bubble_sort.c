#include "libmx.h"

int mx_bubble_sort(char **arr, int size) {
    char *temp;
    int count = 0;

    for (int i = 0; i < size - 1; i++) {
        for (int t = 0; t < size - 1 - i; t++) {
            if (mx_strcmp(arr[t], arr[t + 1]) > 0) {
                temp = arr[t];
                arr[t] = arr[t + 1];
                arr[t + 1] = temp;
                count++;
            }
        }
    }
    return count;
}
