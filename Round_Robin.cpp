
#include <iostream>
using namespace std;

int main() {
    int n = 3;
    int burst_time[] = {10, 5, 8};
    int quantum = 2;

    int remaining_burst_time[n];
    for (int i = 0; i < n; i++) {
        remaining_burst_time[i] = burst_time[i];
    }

    int current_time = 0;
    bool all_done = false;

    cout << "Executing Round Robin (Quantum = " << quantum << ")...\n";

    while (!all_done) {
        all_done = true;

        for (int i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0) {
                all_done = false;

                if (remaining_burst_time[i] > quantum) {
                    current_time += quantum;
                    remaining_burst_time[i] -= quantum;
                    cout << "Process " << i + 1 << " runs for " << quantum << " units.\n";
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
