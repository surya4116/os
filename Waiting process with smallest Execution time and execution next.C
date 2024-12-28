#include <stdio.h>
int main() {
    int n, i, bt[10], wt[10] = {0}, tat[10];
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) scanf("%d", &bt[i]);
    for (i = 1; i < n; i++) wt[i] = wt[i - 1] + bt[i - 1];
    for (i = 0; i < n; i++) tat[i] = wt[i] + bt[i];
    printf("P\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) printf("%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    return 0;
}
