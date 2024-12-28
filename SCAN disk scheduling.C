#include <stdio.h>
#include <stdlib.h>
void SCAN(int arr[], int n, int head, int direction) {
    int total = 0;
    for (int i = 0; i < n; i++) total += abs(head - arr[i]);
    printf("Total seek time: %d\n", total);
}
int main() {
    int arr[] = {176, 79, 34, 50, 92, 11, 41, 114};
    SCAN(arr, 8, 50, 0);  // head=50, direction=0 (left to right)
    return 0;
}
