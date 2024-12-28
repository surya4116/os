
#include <stdio.h>

#define MEMORY_SIZE 10
int memory[MEMORY_SIZE] = {0}; // 0 means free

void firstFit(int size) {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (memory[i] == 0 && i + size <= MEMORY_SIZE) {
            printf("Allocated %d units using First Fit at block %d.\n", size, i);
            for (int j = i; j < i + size; j++) memory[j] = 1;
            return;
        }
    }
    printf("Not enough memory for First Fit.\n");
}

void bestFit(int size) {
    int bestIdx = -1;
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (memory[i] == 0 && i + size <= MEMORY_SIZE) {
            bestIdx = i;
            break;
        }
    }
    if (bestIdx != -1) {
        printf("Allocated %d units using Best Fit at block %d.\n", size, bestIdx);
        for (int j = bestIdx; j < bestIdx + size; j++) memory[j] = 1;
    } else {
        printf("Not enough memory for Best Fit.\n");
    }
}

void worstFit(int size) {
    int worstIdx = -1;
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (memory[i] == 0 && i + size <= MEMORY_SIZE) {
            worstIdx = i;
            break;
        }
    }
    if (worstIdx != -1) {
        printf("Allocated %d units using Worst Fit at block %d.\n", size, worstIdx);
        for (int j = worstIdx; j < worstIdx + size; j++) memory[j] = 1;
    } else {
        printf("Not enough memory for Worst Fit.\n");
    }
}

int main() {
    firstFit(3);
    bestFit(2);
    worstFit(4);
    return 0;
}

