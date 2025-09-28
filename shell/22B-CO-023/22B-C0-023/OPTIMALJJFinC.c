#include <stdio.h>
#include <stdlib.h>

int frames[20], pages[30], faults = 0, hits = 0;

// Function to find the optimal frame to replace
int Optimal(int nf, int current, int np) {
    int temp[20], k = 0;
    
    // Check each frame to see when its page will be used again in future
    for (int i = 0; i < nf; i++) {
        int found = 0;
        
        // Look ahead in the pages for each frame's page
        for (int j = current + 1; j < np; j++) {
            if (frames[i] == pages[j]) {
                temp[k++] = j; // Store index of future use
                found = 1;
                break;
            }
        }
        
        // If the page will not be used again, we can replace it
        if (!found)
            return i;
    }
    
    // If all pages are going to be used again, replace the one used farthest in the future
    int maxPos = temp[0], pos = 0;
    for (int i = 1; i < k; i++) {
        if (temp[i] > maxPos) {
            maxPos = temp[i];
            pos = i;
        }
    }
    return pos;
}

// Function to print the current state of frames
void printFrames(int nf) {
    printf("Frames: ");
    for (int j = 0; j < nf; j++) {
        if (frames[j] != -1)
            printf("%5d", frames[j]);
        else
            printf("%5s", "-");
    }
    printf("\n");
}

// Function to print result based on HIT or FAULT
void printResult(int isHit) {
    if (isHit) {
        printf(" (HIT)  "); // Green color for hit (use terminal coloring if supported)
    } else {
        printf(" (FAULT) "); // Red color for fault
    }
}

int main() {
    int nf, np, pos;

    // Input number of frames (with validation)
    do {
        printf("Enter the number of frames (positive integer): ");
        scanf("%d", &nf);
        if (nf <= 0) printf("Invalid number. Please try again.\n");
    } while (nf <= 0);
    
    // Input number of pages (with validation)
    do {
        printf("Enter the number of pages (positive integer): ");
        scanf("%d", &np);
        if (np <= 0) printf("Invalid number. Please try again.\n");
    } while (np <= 0);
    
    // Input page sequence
    printf("Enter the page sequence: ");
    for (int i = 0; i < np; i++) {
        scanf("%d", &pages[i]);
    }

    // Initialize frames to -1 (empty)
    for (int i = 0; i < nf; i++) {
        frames[i] = -1;
    }
    
    // Print table header
    printf("\n%-15s%-10s%-20s%-15s\n", "Iteration", "Page", "Frames", "Result");
    printf("------------------------------------------------------------\n");

    // Optimal page replacement logic
    for (int i = 0; i < np; i++) {
        printf("%-8d%-10d", i + 1, pages[i]);
        int hit = 0, replaced = 0;

        // Check if the page is already in one of the frames (HIT)
        for (int j = 0; j < nf; j++) {
            if (frames[j] == pages[i]) {
                hits++;
                hit = 1;
                break;
            }
        }

        // If it's not a hit, try to allocate or replace a frame (FAULT)
        if (!hit) {
            int allocated = 0;

            // Look for an empty frame to allocate the page
            for (int j = 0; j < nf; j++) {
                if (frames[j] == -1) {
                    faults++;
                    frames[j] = pages[i];
                    allocated = 1;
                    break;
                }
            }

            // If no empty frame, replace using Optimal strategy
            if (!allocated) {
                pos = Optimal(nf, i, np);
                faults++;
                frames[pos] = pages[i];
                replaced = 1;
            }
        }

        // Print result (HIT or FAULT)
        printResult(hit);
        
        // Print frames after allocation/replacement
        printFrames(nf);
    }

    // Display final results
    printf("\nSummary of Results\n");
    printf("--------------------\n");
    printf("Total Page Faults: %d\n", faults);
    printf("Total Page Hits: %d\n", hits);
    
    // Display the time and space complexity for better understanding
    printf("\nOptimal Page Replacement Time Complexity: O(np * nf)\n");
    printf("Space Complexity: O(nf)\n");

    return 0;
}
