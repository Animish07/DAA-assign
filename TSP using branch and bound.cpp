#include <bits/stdc++.h> 
using namespace std; 

const int N = 12; 

int n, graph[N][N]; 

int minCost = INT_MAX; 

void TSP(int u, int mask, int cost) { 
    if (mask == (1 << n) - 1) { 
        minCost = min(minCost, cost + graph[u][0]); 
        return; 
    } 

    for (int v = 0; v < n; v++) { 
        if ((mask & (1 << v)) == 0) { 
            int newCost = cost + graph[u][v]; 
            if (newCost < minCost) { 
                TSP(v, mask | (1 << v), newCost); 
            } 
        } 
    } 
} 

int main() { 
    cin >> n; 

    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            cin >> graph[i][j]; 
        } 
    } 

    TSP(0, 1, 0); 

    cout << "Minimum cost of Hamiltonian cycle: " << minCost << endl; 

    return 0; 
}