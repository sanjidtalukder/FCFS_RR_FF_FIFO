#include <iostream>
using namespace std;

int main() {
    int num_pages, frames;
    int pages[100], memory[100];

    cout << "Enter the number of pages in the reference string: ";
    cin >> num_pages;

    cout << "Enter the page reference string (separated by space):\n";
    for(int i = 0; i < num_pages; i++) {
        cin >> pages[i];
    }

    cout << "Enter the number of memory frames: ";
    cin >> frames;

    // Empty memory initially
    for(int i = 0; i < frames; i++) {
        memory[i] = -1;
    }

    int page_faults = 0;
    int index = 0;

    for (int i = 0; i < num_pages; i++) {
        int current_page = pages[i];
        bool found = false;

        // Check if page is already in memory
        for (int j = 0; j < frames; j++) {
            if (memory[j] == current_page) {
                found = true;
                break;
            }
        }

        // If not found, replace the oldest page
        if (!found) {
            memory[index] = current_page;
            index = (index + 1) % frames;
            page_faults++;
        }
    }

    cout << "\nTotal Page Faults using FIFO: " << page_faults << "\n";
    return 0;
}
