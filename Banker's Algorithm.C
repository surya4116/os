#include <stdio.h>

#define P 5 // Processes
#define R 3 // Resources

int main() {
    int available[] = {3, 3, 2};
    int max[][R] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int allot[][R] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    int need[P][R], finish[P] = {0}, work[R];
    
    for (int i = 0; i < R; i++) work[i] = available[i];
    for (int i = 0; i < P; i++) 
        for (int j = 0; j < R; j++) need[i][j] = max[i][j] - allot[i][j];

    int count = 0;
    while (count < P) {
        int found = 0;
        for (int p = 0; p < P; p++) {
            if (!finish[p]) {
                int canFinish = 1;
                for (int r = 0; r < R; r++) if (need[p][r] > work[r]) canFinish = 0;
                if (canFinish) {
                    for (int r = 0; r < R; r++) work[r] += allot[p][r];
                    finish[p] = 1;
                    count++;
                    found = 1;
                }
            }
        }
        if (!found) break;
    }

    if (count == P) printf("Safe State\n");
    else printf("Unsafe State\n");

    return 0;
}
