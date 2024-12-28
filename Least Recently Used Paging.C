#include <stdio.h>
int main() {
    int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5}, frames[3] = {-1, -1, -1}, time[3] = {0}, faults = 0, n = 12, t = 0;
    for (int i = 0; i < n; i++) {
        int page = pages[i], found = 0;
        for (int j = 0; j < 3; j++) if (frames[j] == page) found = time[j] = ++t;
        if (!found) {
            int lru = 0; for (int j = 1; j < 3; j++) if (time[j] < time[lru]) lru = j;
            frames[lru] = page; time[lru] = ++t; faults++;
        }
    }
    printf("Page Faults: %d\n", faults);
    return 0;
}
