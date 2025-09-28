#include <stdio.h>
#include <limits.h>

// Function to find the Least Recently Used page's position in frames
int findLRU(int time[], int nf) {
    int i, minimum = time[0], pos = 0;
    
    for (i = 1; i < nf; i++) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    
    return pos;
}

// Function to display the current state of the frames
void displayFrames(int frames[], int nf, int iteration) {
    printf("Iteration %d: ", iteration);
    for (int i = 0; i < nf; i++) {
        if (frames[i] != -1) {
            printf("%d ", frames[i]);
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

int main() {
    int np, nf, i, j, counter = 0, pos, faults = 0, hits = 0;
    
    // Input number of frames
    while (1) {
        printf("Enter number of Frames: ");
        scanf("%d", &nf);
        if (nf > 0) break;
        printf("Invalid input. Please enter a positive integer.\n");
    }
    
    // Input number of pages
    while (1) {
        printf("Enter number of Pages: ");
        scanf("%d", &np);
        if (np > 0) break;
        printf("Invalid input. Please enter a positive integer.\n");
    }
    
    int pages[np];
    int frames[nf];
    int time[nf];  // To store the last used time of each frame

    // Initialize frames and time array
    for (i = 0; i < nf; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    // Input page references
    printf("Enter page references: ");
    for (i = 0; i < np; i++) {
        scanf("%d", &pages[i]);
    }

    // LRU algorithm
    for (i = 0; i < np; i++) {
        int pageHit = 0;

        // Check if page is already in a frame (page hit)
        for (j = 0; j < nf; j++) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = counter;  // Update the last used time
                hits++;
                pageHit = 1;
                printf("Page %d hit.\n", pages[i]);
                break;
            }
        }

        // If page miss
        if (!pageHit) {
            // Look for an empty frame
            int emptyFrame = 0;
            for (j = 0; j < nf; j++) {
                if (frames[j] == -1) {
                    counter++;
                    frames[j] = pages[i];
                    time[j] = counter;  // Update the last used time
                    faults++;
                    emptyFrame = 1;
                    printf("Page %d allocated to empty frame.\n", pages[i]);
                    break;
                }
            }

            // If no empty frame is found, replace the least recently used page
            if (!emptyFrame) {
                pos = findLRU(time, nf);  // Find the least recently used frame
                printf("Page %d replaced by %d (LRU).\n", frames[pos], pages[i]);
                counter++;
                frames[pos] = pages[i];  // Replace the LRU page with the new page
                time[pos] = counter;     // Update the last used time
                faults++;
            }
        }

        // Display current frame status after each page reference
        displayFrames(frames, nf, i + 1);
    }

    // Output total page hits and faults
    printf("\nTotal Page Faults: %d\n", faults);
    printf("Total Page Hits: %d\n", hits);

    return 0;
}
