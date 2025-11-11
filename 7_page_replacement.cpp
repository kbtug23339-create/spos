#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, framesCount;

    cout << "Enter number of pages: ";
    cin >> n;

    vector<int> pages(n);
    cout << "Enter page reference string: ";
    for (int i = 0; i < n; i++) cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> framesCount;

    vector<int> frames;
    queue<int> fifoQueue;
    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        bool found = false;

        // Check if page is already in frames
        for (int f : frames) {
            if (f == page) {
                found = true;
                break;
            }
        }

        if (!found) {
            // Page fault occurs
            if (frames.size() < framesCount) {
                frames.push_back(page);
                fifoQueue.push(page);
            } else {
                // Replace oldest page
                int oldPage = fifoQueue.front();
                fifoQueue.pop();

                // Remove oldPage from frames
                for (int j = 0; j < framesCount; j++) {
                    if (frames[j] == oldPage) {
                        frames[j] = page;
                        break;
                    }
                }
                fifoQueue.push(page);
            }
            pageFaults++;
        }

        // Print current state of frames
        cout << "Step " << i + 1 << " (Page " << page << "): ";
        for (int f : frames) cout << f << " ";
        if (!found)
            cout << "  <-- Page Fault";
        cout << endl;
    }

    cout << "\nTotal Page Faults = " << pageFaults << endl;
    cout << "Page Fault Rate = " << (float)pageFaults / n << endl;

    return 0;
}
// Enter number of pages: 8
// Enter page reference string: 7 0 1 2 0 3 0 4
// Enter number of frames: 3