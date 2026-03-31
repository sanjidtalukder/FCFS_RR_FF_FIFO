
#include <iostream>
#include <cmath> // For abs()
using namespace std;

int main() {
    int num_requests, initial_head;
    int requests[100];

    cout << "Enter the number of disk requests: ";
    cin >> num_requests;

    cout << "Enter the request track numbers (separated by space):\n";
    for(int i = 0; i < num_requests; i++) {
        cin >> requests[i];
    }

    cout << "Enter the initial position of the disk head: ";
    cin >> initial_head;

    int total_head_movement = 0;
    int current_head = initial_head;

    cout << "\nDisk Head Path: " << initial_head;

    // Process requests
    for (int i = 0; i < num_requests; i++) {
        int distance = abs(requests[i] - current_head);
        total_head_movement += distance;
        current_head = requests[i];

        cout << " -> " << current_head;
    }

    cout << "\nTotal Head Movement: " << total_head_movement << " cylinders\n";
    return 0;
}
