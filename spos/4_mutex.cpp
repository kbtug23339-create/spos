#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <cstdlib>
using namespace std;

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;
int itemCount = 0;   // renamed from 'count' to 'itemCount'

mutex mtx;
condition_variable not_full, not_empty;

void producer() {
    for (int i = 0; i < 10; i++) {
        int item = rand() % 100;
        unique_lock<mutex> lock(mtx);

        not_full.wait(lock, [] { return itemCount < BUFFER_SIZE; });

        buffer[in] = item;
        cout << "Producer produced: " << item << endl;
        in = (in + 1) % BUFFER_SIZE;
        itemCount++;

        lock.unlock();
        not_empty.notify_one();

        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

void consumer() {
    for (int i = 0; i < 10; i++) {
        unique_lock<mutex> lock(mtx);

        not_empty.wait(lock, [] { return itemCount > 0; });

        int item = buffer[out];
        cout << "Consumer consumed: " << item << endl;
        out = (out + 1) % BUFFER_SIZE;
        itemCount--;

        lock.unlock();
        not_full.notify_one();

        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main() {
    thread prod(producer);
    thread cons(consumer);

    prod.join();
    cons.join();

    cout << "\nAll items produced and consumed successfully.\n";
    return 0;
}
