#include <iostream>
#include <thread>
#include <vector>
using namespace std;

const int N = 1000; // Matrix size

int A[N][N], B[N][N], C[N][N];

void multiply(int start, int end) {
    for (int i = start; i < end; i++) {
        for (int j = 0; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

int main() {
    // Initialize matrices
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    const int num_threads = 4;
    vector<thread> threads;

    // Launch threads
    for (int i = 0; i < num_threads; i++) {
        int start = i * N / num_threads;
        int end = (i + 1) * N / num_threads;
        threads.emplace_back(multiply, start, end);
    }

    // Join threads
    for (auto& thread : threads) {
        thread.join();
    }

    // Print result
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}