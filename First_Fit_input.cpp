#include <iostream>
using namespace std;

int main() {
    int num_blocks, num_processes;
    int blocks[100], processes[100], allocation[100];

    cout << "Enter the number of memory blocks: ";
    cin >> num_blocks;
    cout << "Enter the size of each block:\n";
    for(int i = 0; i < num_blocks; i++) {
        cout << "Block " << i + 1 << ": ";
        cin >> blocks[i];
    }

    cout << "\nEnter the number of processes: ";
    cin >> num_processes;
    cout << "Enter the size of each process:\n";
    for(int i = 0; i < num_processes; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> processes[i];
        allocation[i] = -1;
    }

    // First Fit Logic
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_blocks; j++) {
            if (blocks[j] >= processes[i]) {
                allocation[i] = j;
                blocks[j] -= processes[i];
                break;
            }
        }
    }

    // Print the results
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < num_processes; i++) {
        cout << " " << i + 1 << "\t\t" << processes[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1 << "\n";
        else
            cout << "Not Allocated\n";
    }
    return 0;
}
