#include <stdio.h>
int main() {
    int pages[] = {1, 3, 0, 3, 5, 6}, n = 6, frames = 3, frame[3] = {-1, -1, -1}, front = 0, faults = 0;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) if (frame[j] == pages[i]) found = 1;
        if (!found) frame[front] = pages[i], front = (front + 1) % frames, faults++;
    }
    printf("Page Faults: %d\n", faults);
    return 0;
}
