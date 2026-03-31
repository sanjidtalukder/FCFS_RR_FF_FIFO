#include <iostream>
using namespace std;

int main() {
    int n = 3; // Number of processes
    int processes[] = {1, 2, 3};
    int burst_time[] = {10, 5, 8}; // Time needed by each process

    int waiting_time[n], turnaround_time[n];

    // 1. Waiting time for first process is always 0
    waiting_time[0] = 0;

    // 2. Calculate waiting time for the rest
    for (int i = 1; i < n; i++) {
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
    }

    // 3. Calculate turnaround time (Waiting Time + Burst Time)
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
    }

    // Print the results
    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i] << "\t\t" << burst_time[i] << "\t\t"
             << waiting_time[i] << "\t\t" << turnaround_time[i] << "\n";
    }

    return 0;
}
