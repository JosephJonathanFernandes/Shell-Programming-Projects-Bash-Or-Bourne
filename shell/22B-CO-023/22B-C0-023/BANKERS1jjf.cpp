#include <iostream>
#include <iomanip>

using namespace std;

int m, n;  // m = number of resource types, n = number of processes
int allocation[10][10], maximum[10][10], need[10][10];
int available[10], total_resources[10];

bool safety() {
    int safe[10], work[10];
    bool finish[10] = { false };
    int count = 0;

    // Initialize work array with available resources
    for (int i = 0; i < m; i++)
        work[i] = available[i];

    while (count < n) {
        bool found = false;
        for (int p = 0; p < n; p++) {
            if (!finish[p]) {
                // Check if the process can be finished
                bool canFinish = true;
                for (int r = 0; r < m; r++) {
                    if (need[p][r] > work[r]) {
                        canFinish = false;
                        break;
                    }
                }

                if (canFinish) {
                    // Simulate the allocation to see if it leads to a safe state
                    for (int r = 0; r < m; r++)
                        work[r] += allocation[p][r];
                    
                    safe[count++] = p;
                    finish[p] = true;
                    found = true;
                }
            }
        }

        // If no process can be finished, the system is not in a safe state
        if (!found)
            break;
    }

    // Print safe sequence if found
    if (count == n) {
        cout << endl << "Safe Sequence: ";
        for (int i = 0; i < n; i++)
            cout << "P" << safe[i] << " -> ";
        cout << "END" << endl;
        return true;
    } else {
        cout << endl << "No safe sequence exists." << endl;
        return false;
    }
}

void display() {
    cout << endl << "Allocation\tMaximum\t\tNeed\t\tAvailable" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P" << i << "\t";
        for (int j = 0; j < m; j++)
            cout << allocation[i][j] << " ";
        cout << "\t";

        for (int j = 0; j < m; j++)
            cout << maximum[i][j] << " ";
        cout << "\t";

        for (int j = 0; j < m; j++)
            cout << need[i][j] << " ";
        cout << "\t";

        if (i == 0) {
            for (int j = 0; j < m; j++)
                cout << available[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Enter the number of Processes: ";
    cin >> n;

    cout << "Enter the number of Resource types: ";
    cin >> m;

    cout << "Enter the Total Resources for each type:" << endl;
    for (int i = 0; i < m; i++)
        cin >> total_resources[i];

    cout << "Enter Allocated Resources for each process:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P" << i << ": ";
        for (int j = 0; j < m; j++)
            cin >> allocation[i][j];
    }

    cout << endl << "Enter Maximum Resources for each process:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P" << i << ": ";
        for (int j = 0; j < m; j++)
            cin >> maximum[i][j];
    }

    // Calculate the total allocated resources
    int allocated[10] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            allocated[j] += allocation[i][j];
    }

    // Calculate the available resources
    for (int i = 0; i < m; i++)
        available[i] = total_resources[i] - allocated[i];

    // Calculate Need matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            need[i][j] = maximum[i][j] - allocation[i][j];
    }

    // Display matrices
    display();

    // Check if the system is in a safe state
    bool isSafe = safety();

    // Resource request algorithm
    char ans = 'y';
    do {
        int request[10], p;
        cout << endl << "Enter Process Number: ";
        cin >> p;

        cout << "Enter Request: ";
        for (int i = 0; i < m; i++)
            cin >> request[i];

        bool canGrant = true;
        for (int i = 0; i < m; i++) {
            if (request[i] > need[p][i]) {
                cout << endl << "Process has exceeded its maximum claim." << endl;
                canGrant = false;
                break;
            }
            if (request[i] > available[i]) {
                cout << endl << "Resources not available, process must wait." << endl;
                canGrant = false;
                break;
            }
        }



        if (canGrant) {
            cout<<"\n";
        cout<<"DOING THE RESOURCE REQUEST ALGO"<<endl;
        cout<<"TEMP ALLOCATION SEEN";
            // Tentatively allocate resources
            for (int i = 0; i < m; i++) {
                available[i] -= request[i];
                allocation[p][i] += request[i];
                need[p][i] -= request[i];
            }

            display();

            // Check if the allocation leads to all types of resources being zero
            bool allZero = true;
            for (int i = 0; i < m; i++) {
                if (available[i] > 0) {
                    allZero = false;
                    break;
                }
            }

            if (allZero) {
                cout << endl << "Request cannot be granted as it leads to all resource types being zero." << endl;
                // Rollback
                for (int i = 0; i < m; i++) {
                    available[i] += request[i];
                    allocation[p][i] -= request[i];
                    need[p][i] += request[i];
                }
                cout << endl << "State restored:" << endl;
                display();
            } else {
                cout<<"\n";
                cout<<"EXECUTING SAFETY ALGO"<<endl;
                // Check for safety
                cout << endl << "Checking system safety after tentative allocation..." << endl;
                isSafe = safety();

                if (!isSafe) {
                    cout << "Request cannot be granted as it leads to an unsafe state." << endl;
                    // Rollback
                    for (int i = 0; i < m; i++) {
                        available[i] += request[i];
                        allocation[p][i] -= request[i];
                        need[p][i] += request[i];
                    }
                    cout << endl << "State restored:" << endl;
                    display();
                } else {
                    cout << "Safe sequence exists. Request can be granted." << endl;
                    cout<<"NEW PERMANENT ALLOCATION"<<endl;
                    display();
                }
            }
        }

        cout << endl << "Try another process? (Y/N): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    return 0;
}