#include <stdio.h>
int main() {
    int p[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2}, n = 13, f[3] = {-1}, fc = 0, faults = 0;
    for (int i = 0; i < n; i++) {
        int found = 0, far = 0, pos = 0;
        for (int j = 0; j < fc; j++) if (f[j] == p[i]) found = 1;
        if (!found) {
            if (fc < 3) f[fc++] = p[i];
            else for (int j = 0; j < 3; j++) {
                int k; for (k = i + 1; k < n && f[j] != p[k]; k++);
                if (k > far) { far = k; pos = j; }
            }
            if (fc == 3) f[pos] = p[i];
            faults++;
        }
    }
    printf("Page Faults: %d\n", faults);
}
