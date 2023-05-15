#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

const int N = 5;

mutex forks[N];

void philosopher(int id) {
    int left = id;
    int right = (id + 1) % N;

    while (true) {
        // Think for a while
        cout << "Philosopher " << id << " is thinking." << endl;
        this_thread::sleep_for(chrono::milliseconds(rand() % 10000));

        // Pick up left fork
        forks[left].lock();
        cout << "Philosopher " << id << " picks up fork " << left << "." << endl;

        // Pick up right fork
        forks[right].lock();
        cout << "Philosopher " << id << " picks up fork " << right << "." << endl;

        // Eat for a while
        cout << "Philosopher " << id << " is eating." << endl;
        this_thread::sleep_for(chrono::milliseconds(rand() % 10000));

        // Put down right fork
        forks[right].unlock();
        cout << "Philosopher " << id << " puts down fork " << right << "." << endl;

        // Put down left fork
        forks[left].unlock();
        cout << "Philosopher " << id << " puts down fork " << left << "." << endl;
    }
}

int main() {
    thread philosophers[N];
    for (int i = 0; i < N; i++) {
        philosophers[i] = thread(philosopher, i);
    }

    for (int i = 0; i < N; i++) {
        philosophers[i].join();
    }

    return 0;
}