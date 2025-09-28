#include<stdio.h>

// Function to find the least recently used frame
int LRU(int time[], int nf) {
    int i, minimum = time[0], pos = 0;
    // Find the frame with the smallest time (least recently used)
    for(i = 1; i < nf; i++) {
        if(time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int nf, np, alloc[20], pages[30], counter = 0, time[20];
    int flag1, flag2, i, j, pos, faults = 0, hits = 0;
    
    // Accept number of frames and pages
    printf("Enter number of Frames: ");
    scanf("%d", &nf);
    printf("Enter number of pages: ");
    scanf("%d", &np);
    
    // Enter page numbers
    printf("Enter the sequence of pages: ");
    for(i = 0; i < np; i++)
        scanf("%d", &pages[i]);
    
    // Initialize frame allocation and time
    for(i = 0; i < nf; i++)
        alloc[i] = -1;
    
    printf("\nFrame Allocation Table (after each page request):\n");
    printf("-------------------------------------------------\n");
    printf("Page\t");
    for(i = 0; i < nf; i++)
        printf("F%d\t", i + 1);
    printf("Status\n");
    printf("-------------------------------------------------\n");
    
    // Iterate through every page request
    for(i = 0; i < np; i++) {
        flag1 = flag2 = 0;
        
        // Check if the page is already in any frame (page hit)
        for(j = 0; j < nf; j++) {
            if(alloc[j] == pages[i]) {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                hits++;
                break;
            }
        }
        
        // If page is not found, handle page fault
        if(flag1 == 0) {
            // Check for empty frames and allocate the page
            for(j = 0; j < nf; j++) {
                if(alloc[j] == -1) {
                    counter++;
                    faults++;
                    alloc[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }
        
        // If no empty frames, replace the least recently used page
        if(flag2 == 0) {
            pos = LRU(time, nf);
            counter++;
            faults++;
            alloc[pos] = pages[i];
            time[pos] = counter;
        }
        
        // Display current frame allocation
        printf("%d\t", pages[i]);
        for(j = 0; j < nf; j++) {
            if(alloc[j] != -1)
                printf("%d\t", alloc[j]);
            else
                printf("-\t"); // Empty frame
        }
        if(flag1 == 1) {
            printf("Hit\n"); // Page hit
        } else {
            printf("Fault\n"); // Page fault
        }
    }
    
    // Results summary
    printf("-------------------------------------------------\n");
    printf("\nTotal Page Faults: %d", faults);
    printf("\nTotal Page Hits: %d", hits);
    
    // Hit ratio
    float hitRatio = (float)hits / np;
    printf("\nHit Ratio: %.2f\n", hitRatio);
    
    return 0;
}
