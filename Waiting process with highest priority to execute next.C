#include <stdio.h>
int main() {
    int n, i, j, bt[10], p[10];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        p[i] = i + 1; 
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                int t = bt[i];
                bt[i] = bt[j];
                bt[j] = t;
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
    printf("Process execution order: ");
    for (i = 0; i < n; i++) {
        printf("P%d ", p[i]);
    }
    printf("\n");
    return 0;
}
