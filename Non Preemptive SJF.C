#include <stdio.h>

int main() {
    int n, i, j, bt[10], pr[10], wt[10] = {0}, tat[10], p[10], temp;
    scanf("%d", &n); // Number of processes
    for (i = 0; i < n; i++) {
        scanf("%d %d", &bt[i], &pr[i]); 
        p[i] = i + 1;
    }

    for (i = 0; i < n - 1; i++) // Sort by burst time and priority
        for (j = 0; j < n - i - 1; j++)
            if (bt[j] > bt[j + 1] || (bt[j] == bt[j + 1] && pr[j] > pr[j + 1])) {
                temp = bt[j]; bt[j] = bt[j + 1]; bt[j + 1] = temp;
                temp = pr[j]; pr[j] = pr[j + 1]; pr[j + 1] = temp;
                temp = p[j]; p[j] = p[j + 1]; p[j + 1] = temp;
            }

    for (i = 1; i < n; i++) wt[i] = wt[i - 1] + bt[i - 1]; // Waiting time
    for (i = 0; i < n; i++) tat[i] = wt[i] + bt[i]; // Turnaround time

    printf("P\tBT\tPr\tWT\tTAT\n");
    for (i = 0; i < n; i++) printf("%d\t%d\t%d\t%d\t%d\n", p[i], bt[i], pr[i], wt[i], tat[i]);
}
