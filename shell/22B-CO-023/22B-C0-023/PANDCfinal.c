#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Queue structure to hold the buffer information
typedef struct {
    char **buffer; // Dynamic buffer to store alphanumeric process IDs
    int front;     // Index for the front of the buffer
    int rear;      // Index for the rear of the buffer
    int size;      // Current size of the buffer
    int capacity;  // Maximum capacity of the buffer

    // Mutex for mutual exclusion
    int mutex;     // 1 means available, 0 means not available
    // Semaphores
    int empty;     // Count of empty slots
    int full;      // Count of filled slots
} Queue;

// Function prototypes
void wait(int *s);
void signal(int *s);
void produce(Queue *queue, const char *item);
char *consume(Queue *queue);
void displayBuffer(const Queue *queue);
void displayBufferAsArray(const Queue *queue);
bool isFull(const Queue *queue);
bool isEmpty(const Queue *queue);

// Main function
int main() {
    int bufferSize;
    printf("Enter buffer size: ");
    scanf("%d", &bufferSize);

    // Initialize queue with user-defined size
    Queue queue;
    queue.capacity = bufferSize;
    queue.buffer = (char **)malloc(bufferSize * sizeof(char *));
    for (int i = 0; i < bufferSize; i++) {
        queue.buffer[i] = (char *)malloc(30 * sizeof(char));  // Assuming max 30 chars for process ID
        strcpy(queue.buffer[i], "NULL");
    }
    queue.front = 0;
    queue.rear = 0;
    queue.size = 0;
    queue.empty = bufferSize; // Set initial empty slots
    queue.full = 0;           // No full slots initially
    queue.mutex = 1;          // Mutex available

    int choice;
    char item[30];  // Assuming process ID size up to 30 characters

    while (1) {
        printf("\n******MENU******\n\n1. Produce \n2. Consume \n3. Display Buffer\n4. Display Buffer as Array\n5. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull(&queue)) {
                    printf("\nBuffer is FULL!\n");
                } else {
                    printf("\nEnter alphanumeric process ID to be inserted in the buffer: ");
                    scanf("%s", item);

                    // Validate the input
                    int valid = 1;
                    for (int i = 0; item[i] != '\0'; i++) {
                        if (!((item[i] >= 'a' && item[i] <= 'z') || (item[i] >= 'A' && item[i] <= 'Z') || (item[i] >= '0' && item[i] <= '9'))) {
                            valid = 0;
                            break;
                        }
                    }

                    if (!valid) {
                        printf("Invalid input! Please enter an alphanumeric process ID.\n");
                    } else {
                        produce(&queue, item);
                        displayBuffer(&queue);
                        displayBufferAsArray(&queue);
                    }
                }
                break;

            case 2:
                if (isEmpty(&queue)) {
                    printf("\nBuffer is EMPTY!\n\n");
                } else {
                    char *consumed_item = consume(&queue);
                    printf("Consumed Item: %s\n", consumed_item);
                    displayBuffer(&queue);
                    displayBufferAsArray(&queue);
                }
                break;

            case 3:
                displayBuffer(&queue);
                break;

            case 4:
                displayBufferAsArray(&queue);
                break;

            case 5:
                // Free allocated memory
                for (int i = 0; i < queue.capacity; i++) {
                    free(queue.buffer[i]);
                }
                free(queue.buffer);
                exit(0);

            default:
                printf("Wrong choice entered\n");
        }
    }

    return 0;
}

void wait(int *s) {
    while (*s <= 0); // Busy wait (not ideal but simple)
    (*s)--;          // Decrease semaphore count
}

void signal(int *s) {
    (*s)++;          // Increase semaphore count
}

void produce(Queue *queue, const char *item) {
    wait(&queue->empty); // Wait for an empty slot
    wait(&queue->mutex); // Acquire the mutex

    // Add item to the buffer
    strcpy(queue->buffer[queue->rear], item);
    queue->rear = (queue->rear + 1) % queue->capacity; // Move the rear index circularly
    queue->size++; // Increase the size

    signal(&queue->mutex); // Release the mutex
    signal(&queue->full);  // Signal that there is a new full slot

    printf("\nProduced item added to buffer\n\n");
}

char *consume(Queue *queue) {
    wait(&queue->full);  // Wait for a full slot
    wait(&queue->mutex); // Acquire the mutex

    // Make a copy of the item before clearing it
    char *item = (char *)malloc(30 * sizeof(char));
    strcpy(item, queue->buffer[queue->front]);  // Copy the consumed item
    
    strcpy(queue->buffer[queue->front], "NULL"); // Clear the consumed item by marking it as NULL
    queue->front = (queue->front + 1) % queue->capacity; // Move the front index circularly
    queue->size--; // Decrease the size

    signal(&queue->mutex); // Release the mutex
    signal(&queue->empty); // Signal that there is a new empty slot

    return item;  // Return the copied item
}


void displayBuffer(const Queue *queue) {
    if (queue->size == 0) {
        printf("Buffer is empty!\n");
        return;
    }

    printf("------------- Buffer State -------------\n");
    printf("| Index | Process ID                    |\n");
    printf("|-------|-------------------------------|\n");

    int index = queue->front;
    for (int count = 0; count < queue->size; count++) {
        printf("| %5d | %-30s |\n", index, queue->buffer[index]);
        index = (index + 1) % queue->capacity;
    }

    printf("|-------|-------------------------------|\n");
    printf("Total Items: %d\n", queue->size);
    printf("-----------------------------------------\n");
}

void displayBufferAsArray(const Queue *queue) {
    printf("------------- Buffer Array -------------\n");
    printf("[ ");
    
    // Loop through the entire buffer capacity
    for (int i = 0; i < queue->capacity; i++) {
        // Display the element at the current position
        printf("\"%s\" ", queue->buffer[i]);
    }
    
    printf("]\n");
    printf("OUT: %d, IN: %d, Size: %d\n", queue->front, queue->rear, queue->size);
    printf("-----------------------------------------\n");
}

bool isEmpty(const Queue *queue) {
    return (queue->size == 0);  // Check if buffer is empty
}

bool isFull(const Queue *queue) {
    return (queue->size == queue->capacity);  // Check if buffer is full
}
