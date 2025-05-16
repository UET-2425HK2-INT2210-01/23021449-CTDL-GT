#include <iostream>
#include <vector>

using namespace std;

// Hàm để thực hiện tìm kiếm theo chiều sâu (DFS)
void dfs(int a, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[a] = true; // Đánh dấu nút hiện tại là đã được thăm

    // Duyệt qua tất cả các nút kề của nút hiện tại
    for (int i : adj[a]) {
        if (!visited[i]) { // Nếu nút kề chưa được thăm
            dfs(i, adj, visited); // Gọi đệ quy hàm DFS trên nút kề
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Tạo danh sách kề để biểu diễn đồ thị
    vector<vector<int>> adj(n + 1); // Sử dụng n+1 để các nút được đánh số từ 1 đến n

    // Đọc các cạnh và thêm chúng vào danh sách kề (đồ thị vô hướng)
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); // Thêm cạnh từ x đến y
        adj[y].push_back(x); // Thêm cạnh từ y đến x (vì đồ thị vô hướng)
    }

    // Mảng để theo dõi các nút đã được thăm
    vector<bool> visited(n + 1, false);

    // Biến để đếm số lượng thành phần liên thông
    int connectedComponents = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) { // Nếu nút i chưa được thăm
            dfs(i, adj, visited); // Bắt đầu DFS từ nút i
            connectedComponents++; // Tăng số lượng thành phần liên thông
        }
    }

    // In ra kết quả
    cout << connectedComponents << endl;

    return 0;
}
