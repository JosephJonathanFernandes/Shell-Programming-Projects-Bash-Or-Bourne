#include <stdio.h>
#include <stdlib.h>

int frames[20], pages[30];
int queue[20], front = -1, rear = -1; // Queue to manage page order in FIFO
int faults = 0, hits = 0;

// Function to check if a page is already in frames
int isInFrames(int page, int nf) {
    for (int i = 0; i < nf; i++) {
        if (frames[i] == page) {
            return 1; // Page is in frames
        }
    }
    return 0; // Page is not in frames
}

// Function to print frames
void printFrames(int nf) {
    for (int i = 0; i < nf; i++) {
        if (frames[i] != -1)
            printf("%5d", frames[i]);
        else
            printf("%5c", '-');
    }
    printf("  | Queue: ");
    // Print the current state of the queue
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Function to insert a page into the queue
void enqueue(int page) {
    if (front == -1) front = 0;
    queue[++rear] = page;
}

// Function to remove the first page from the queue
int dequeue() {
    return queue[front++];
}

int main() {
    int nf, np, i, j, removedPage;
    double hitRatio;

    printf("Enter number of Frames: ");
    scanf("%d", &nf);
    printf("Enter number of pages: ");
    scanf("%d", &np);

    printf("Enter the pages: ");
    for (i = 0; i < np; i++) {
        scanf("%d", &pages[i]);
    }

    // Initialize frames
    for (i = 0; i < nf; i++) {
        frames[i] = -1;
    }

    printf("\n%20s", "Iteration");
    for (i = 0; i < nf; i++) {
        printf("%5sF%d", "", i + 1);
    }
    printf("  | Queue\n");
    printf("------------------------------------------------------\n");

    // FIFO algorithm
    for (i = 0; i < np; i++) {
        printf("%18s Page %d", "", pages[i]);
        int hit = isInFrames(pages[i], nf); // Check for page hit

        if (hit) {
            hits++;
            printf(" (Hit)");
        } else {
            faults++;
            printf(" (Fault)");

            if (rear - front + 1 == nf) { // Queue is full
                removedPage = dequeue(); // Get the page to be removed (FIFO)
                // Find and replace the page in frames
                for (j = 0; j < nf; j++) {
                    if (frames[j] == removedPage) {
                        frames[j] = pages[i]; // Replace with the new page
                        break;
                    }
                }
                printf(" (Replaced %d)", removedPage);
            } else {
                // Insert into an empty frame
                for (j = 0; j < nf; j++) {
                    if (frames[j] == -1) {
                        frames[j] = pages[i];
                        break;
                    }
                }
            }
            enqueue(pages[i]); // Add the new page to the queue
        }

        // Print the state of the frames and queue
        printFrames(nf);
    }

    // Performance ratio: hits / total pages
    hitRatio = (double)hits / np;

    printf("\nTotal Page Faults: %d\n", faults);
    printf("Total Page Hits: %d\n", hits);
    printf("Hit Ratio: %.2f%%\n", hitRatio * 100);

    return 0;
}
