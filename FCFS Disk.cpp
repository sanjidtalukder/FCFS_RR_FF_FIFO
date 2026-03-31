#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int requests[] = {82, 170, 43, 140, 24, 16, 190};
    int num_requests = sizeof(requests) / sizeof(requests[0]);
    int initial_head = 50;

    int total_head_movement = 0;
    int current_head = initial_head;

    cout << "Disk Head Path: " << initial_head;

    for (int i = 0; i < num_requests; i++) {
        int distance = abs(requests[i] - current_head);
        total_head_movement += distance;

        current_head = requests[i];

        cout << " -> " << current_head;
    }

    cout << "\nTotal Head Movement: " << total_head_movement << " cylinders\n";
    return 0;
}
