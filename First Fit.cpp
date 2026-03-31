#include <iostream>
using namespace std;

int main() {
    int blocks[] = {100, 500, 200, 300, 600};
    int processes[] = {212, 417, 112, 426};

    int num_blocks = sizeof(blocks) / sizeof(blocks[0]);
    int num_processes = sizeof(processes) / sizeof(processes[0]);

    int allocation[num_processes];

    for (int i = 0; i < num_processes; i++) {
        allocation[i] = -1;
    }

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
    cout << "Process No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < num_processes; i++) {
        cout << " " << i + 1 << "\t\t" << processes[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1 << "\n";
        else
            cout << "Not Allocated\n";
    }
    return 0;
}
