#include <iostream>
using namespace std;

int main() {
    int n;
    int burst_time[100], waiting_time[100], turnaround_time[100];

    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter Burst Time for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> burst_time[i];
    }

    waiting_time[0] = 0;

    for (int i = 1; i < n; i++) {
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
    }

    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
    }

    // Print the results
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t\t" << burst_time[i] << "\t\t"
             << waiting_time[i] << "\t\t" << turnaround_time[i] << "\n";
    }

    return 0;
}
