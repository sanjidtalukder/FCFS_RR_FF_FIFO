#include <iostream>
using namespace std;

int main() {
    int n, quantum;
    int burst_time[100], remaining_burst_time[100];

    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter Burst Time for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> burst_time[i];
        remaining_burst_time[i] = burst_time[i];
    }

    cout << "Enter the Time Quantum: ";
    cin >> quantum;

    int current_time = 0;
    bool all_done = false;

    cout << "\n Execution Order \n";


    while (!all_done) {
        all_done = true;

        for (int i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0) {
                all_done = false;

                if (remaining_burst_time[i] > quantum) {
                    current_time += quantum;
                    remaining_burst_time[i] -= quantum;
                    cout << "Process " << i + 1 << " runs for " << quantum << " units. (Total Time: " << current_time << ")\n";
                } else {
                    current_time += remaining_burst_time[i];
                    cout << "Process " << i + 1 << " finishes at time " << current_time << ".\n";
                    remaining_burst_time[i] = 0;
                }
            }
        }
    }
    return 0;
}
