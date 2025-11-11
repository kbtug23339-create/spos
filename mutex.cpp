#include <iostream>
using namespace std;

int mutex = 1, full = 0, emptySlots = 3, x = 0;

void wait(int &s) { s--; }
void signal(int &s) { s++; }

void producer() {
    wait(mutex);
    wait(emptySlots);
    x++;
    cout << "Producer produces item " << x << endl;
    signal(full);
    signal(mutex);
}

void consumer() {
    wait(mutex);
    wait(full);
    cout << "Consumer consumes item " << x << endl;
    x--;
    signal(emptySlots);
    signal(mutex);
}

int main() {
    int ch;
    while (true) {
        cout << "\n1. Produce\n2. Consume\n3. Exit\nEnter choice: ";
        cin >> ch;
        if (ch == 1 && (mutex == 1 && emptySlots != 0))
            producer();
        else if (ch == 2 && (mutex == 1 && full != 0))
            consumer();
        else if (ch == 3)
            break;
        else
            cout << "Operation not possible!\n";
    }
}