#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Hàm để tìm đường đi ngắn nhất giữa tất cả các cặp đỉnh
// Sử dụng thuật toán Floyd-Warshall
void floydWarshall(int n, vector<vector<int>>& dist) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] != -1 && dist[k][j] != -1) { // Thay INT_MAX bằng -1
                    if (dist[i][j] == -1) {
                         dist[i][j] = dist[i][k] + dist[k][j];
                    }
                    else {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
}

int main() {
    ifstream inputFile("dirty.txt");
    if (!inputFile.is_open()) {
        cerr << "Không thể mở file dirty.txt" << endl;
        return 1;
    }

    int n, m, s, e;
    inputFile >> n >> m >> s >> e;

    // Ma trận kề để lưu trữ khoảng cách giữa các thành phố
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, -1)); // Thay INT_MAX bằng -1
    for (int i = 1; i <= n; ++i) {
        adj[i][i] = 0; // Khoảng cách từ một thành phố đến chính nó là 0
    }

    for (int i = 0; i < m; ++i) {
        int u, v, d;
        inputFile >> u >> v >> d;
        adj[u][v] = d;
    }
    inputFile.close();

    // Áp dụng thuật toán Floyd-Warshall
    floydWarshall(n, adj);

    ofstream outputFile("dirty.out");
    if (!outputFile.is_open()) {
        cerr << "Không thể mở file dirty.out" << endl;
        return 1;
    }

    // In ma trận khoảng cách ngắn nhất
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (adj[i][j] == -1)
                outputFile << "INF ";
            else
                outputFile << adj[i][j] << " ";
        }
        outputFile << endl;
    }
    outputFile.close();

    cout << "Kết quả đã được ghi vào file dirty.out" << endl;
    return 0;
}


