#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Hàm BFS để tìm đường đi ngắn nhất
void bfs(int n, vector<vector<int>>& adj, int start, vector<int>& dist) {
    // Khởi tạo tất cả khoảng cách là -1 (biểu thị vô cực)
    for (int i = 1; i <= n; ++i) {
        dist[i] = -1;
    }
    dist[start] = 0; // Khoảng cách từ nút bắt đầu đến chính nó là 0

    // Hàng đợi cho BFS
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Duyệt qua các nút láng giềng của u
        for (int v : adj[u]) {
            if (dist[v] == -1) { // Nếu nút láng giềng v chưa được thăm
                dist[v] = dist[u] + 1; // Cập nhật khoảng cách
                q.push(v);
            }
        }
    }
}

// Hàm shortestPath sử dụng BFS để tìm đường đi ngắn nhất
int shortestPath(int n, vector<vector<int>>& adj, int start, int end) {
    vector<int> dist(n + 1); // Vector để lưu khoảng cách
    bfs(n, adj, start, dist); // Gọi hàm BFS để tính khoảng cách

    return dist[end]; // Trả về khoảng cách đến nút kết thúc
}

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    // Tạo danh sách kề để biểu diễn đồ thị
    vector<vector<int>> adj(n + 1);

    // Đọc các cạnh của đồ thị
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Thêm cạnh có hướng từ u đến v
    }

    // Tìm và in đường đi ngắn nhất
    cout << shortestPath(n, adj, x, y) << endl;

    return 0;
}
