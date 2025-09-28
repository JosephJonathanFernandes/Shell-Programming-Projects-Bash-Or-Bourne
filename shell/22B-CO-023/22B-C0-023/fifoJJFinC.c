#include <stdio.h>
#include <stdbool.h>

#define MAX 50 // Maximum number of pages or frames

// Function to check if a page is in the frames (hit)
bool isHit(int frames[], int f, int page) {
    for (int i = 0; i < f; i++) {
        if (frames[i] == page) {
            return true;
        }
    }
    return false;
}

// Function to print the frames at each step
void printFrames(int frames[], int f) {
    for (int i = 0; i < f; i++) {
        if (frames[i] == -1) {
            printf("  - "); // empty slot
        } else {
            printf("  %d ", frames[i]); // page ID in frame
        }
    }
    printf("\n");
}

int main() {
    int f, n, ind = 0, faults = 0, hits = 0;

    // Input number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &f);

    // Input number of pages
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int data[n], frames[f];

    // Initialize all frames to -1 (indicating they are empty)
    for (int i = 0; i < f; i++) {
        frames[i] = -1;
    }

    // Input pages
    printf("Enter Page IDs: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    // Print the header for better output formatting
    printf("\n%10s%20s%10s\n", "Page", "Frames", "Status");
    printf("----------------------------------------------------\n");

    // FIFO Page Replacement Algorithm
    for (int i = 0; i < n; i++) {
        // Check if page is already in frames (hit)
        if (isHit(frames, f, data[i])) {
            hits++;
            printf("%8d%20s", data[i], "");
            printFrames(frames, f);
            printf("%10s\n", "Hit");
        } else {
            // Page Fault occurs, replace the oldest page using FIFO
            frames[ind] = data[i];
            ind = (ind + 1) % f;
            faults++;
            printf("%8d%20s", data[i], "");
            printFrames(frames, f);
            printf("%10s\n", "Fault");
        }
    }

    // Print total page faults and hits
    printf("\nTotal Page Faults: %d\n", faults);
    printf("Total Page Hits: %d\n", hits);

    // Calculate hit ratio and fault ratio
    double hitRatio = (double)hits / n;
    double faultRatio = (double)faults / n;

    printf("Hit Ratio: %.2f%%\n", hitRatio * 100);
    printf("Fault Ratio: %.2f%%\n", faultRatio * 100);

    return 0;
}
