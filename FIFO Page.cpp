
#include <iostream>
using namespace std;

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3};
    int num_pages = sizeof(pages) / sizeof(pages[0]);
    int frames = 3;

    int memory[frames];
    for(int i = 0; i < frames; i++) memory[i] = -1;

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
        if (!found) {
            memory[index] = current_page;
            index = (index + 1) % frames;
            page_faults++;
        }
    }

    cout << "Total Page Faults using FIFO: " << page_faults << "\n";
    return 0;
}
