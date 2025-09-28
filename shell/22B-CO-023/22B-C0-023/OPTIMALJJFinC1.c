#include <stdio.h>
#include <string.h>

int return_index(int *arr, int n, int search);
int ifpresent(int n, int *arr, int value, int start);
int last_page(int n, int *arr, int *frames, int curr, int fn);

int main() {
    int n, page_no, flag, replace_index, nop, frames_empty, lp, lp_index;
    int page_hits = 0, page_faults = 0;  // Counters for page hits and faults

    // Initial message
    printf("Note: Frame having value -1 indicates it is empty\n");
    
    // Taking number of frames as input
    printf("Enter the number of frames: ");
    scanf("%d", &n);
    
    // Initializing frame-related variables
    frames_empty = n;
    int frames[n], replace[n];  // Array initialization
    memset(frames, -1, sizeof(frames));  // Initialize frames with -1
    memset(replace, 0, sizeof(replace)); // Initialize replace array with 0

    // Display initial frames
    printf("Initially Frames are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", frames[i]);
    }
    printf("\n");

    // Taking number of page references
    printf("Enter number of page references: ");
    scanf("%d", &nop);
    int pages[nop];

    // Taking page reference string input
    printf("Enter Page Reference String: ");
    for (int i = 0; i < nop; i++) {
        scanf("%d", &pages[i]);
    }
    printf("\n");

    // Main page replacement logic
    for (int y = 0; y < nop; y++) {
        page_no = pages[y];  // Current page number
        printf("\nPage No: %d\n", page_no);

        // Check if the page is already present in the frames
        flag = 1;  // Assume page is not in the frame
        for (int i = 0; i < n; i++) {
            if (frames[i] == page_no) {
                flag = 0;  // Page is present in the frame
                break;
            }
        }

        if (flag == 1) {  // Page Fault occurs
            page_faults++;  // Increment the page fault counter
            printf("Page Fault!\n");
            if (frames_empty > 0) {
                frames[n - frames_empty] = page_no;  // Fill empty frame
                frames_empty--;
            } else {  // No empty frames, need to replace a page
                lp = last_page(nop, pages, frames, y, n);  // Get the last page
                lp_index = (lp != -1) ? return_index(frames, n, lp) : 0;
                frames[lp_index] = page_no;  // Replace the page
            }
        } else {
            page_hits++;  // Increment the page hit counter
            printf("Page Hit!\n");
        }

        // Display the current state of frames
        printf("Currently Frames are: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", frames[i]);
        }
        printf("\n");
    }

    // Final stats
    printf("\nTotal Page Hits: %d\n", page_hits);
    printf("Total Page Faults: %d\n", page_faults);
    printf("\n");
}

// Function to return the index of a page in an array
int return_index(int *arr, int n, int search) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            return i;
        }
    }
    return -1;
}

// Function to check if a value is present in an array starting from a given index
int ifpresent(int n, int *arr, int value, int start) {
    for (int i = start; i < n; i++) {
        if (arr[i] == value) {
            return 1;
        }
    }
    return 0;
}

// Function to find the last page in frames that is not used in the near future
int last_page(int n, int *arr, int *frames, int curr, int fn) {
    int got[fn], k = 0;

    // Find a page in the frames that won't be used in the future
    for (int i = 0; i < fn; i++) {
        if (!ifpresent(n, arr, frames[i], curr + 1)) {
            return frames[i];  // Return the frame to be replaced
        }
    }

    // If all pages will be used in the future, find the one used last
    int last = -1;
    for (int i = curr + 1; i < n; i++) {
        for (int j = 0; j < fn; j++) {
            if (arr[i] == frames[j] && !ifpresent(k, got, arr[i], 0)) {
                last = arr[i];
                got[k++] = last;
            }
        }
    }
    return got[--k];  // Return the last used page
}
