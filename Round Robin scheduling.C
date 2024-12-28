#include <stdio.h>
int main() {
    int n, tq, bt[10], rt[10], i, time = 0, done;
    printf("Enter number of processes and time quantum: ");
    scanf("%d %d", &n, &tq);
    printf("Enter burst times: ");
    for (i = 0; i < n; i++) scanf("%d", &bt[i]), rt[i] = bt[i];   
    do {
        done = 1;
        for (i = 0; i < n; i++) {
            if (rt[i] > 0) {
                done = 0;
                if (rt[i] > tq) time += tq, rt[i] -= tq;
                else time += rt[i], rt[i] = 0;
                printf("P%d ", i + 1);
            }
        }
    } while (!done);
     printf("\nTotal time: %d\n", time);
    return 0;
}
