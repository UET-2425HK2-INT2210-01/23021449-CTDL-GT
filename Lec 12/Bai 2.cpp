#include <iostream>
#include <vector>

using namespace std;

// Cấu trúc cạnh: gồm 2 đỉnh u, v và trọng số d (chi phí)
struct Edge {
    int u, v, d;
};

// Hàm sắp xếp các cạnh theo trọng số tăng dần (selection sort)
void sortEdges(vector<Edge> &edges) {
    int n = edges.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (edges[j].d < edges[minIdx].d) {
                minIdx = j;
            }
        }
        // Hoán đổi cạnh nhỏ nhất với vị trí hiện tại
        if (minIdx != i) {
            Edge temp = edges[i];
            edges[i] = edges[minIdx];
            edges[minIdx] = temp;
        }
    }
}

// Hàm tìm gốc của một đỉnh (thuật toán DSU - Union Find)
int findRoot(int parent[], int x) {
    if (parent[x] != x)
        parent[x] = findRoot(parent, parent[x]); // nén đường đi
    return parent[x];
}

// Hàm hợp nhất hai tập hợp lại (gán gốc của y về gốc của x)
void unionSet(int parent[], int x, int y) {
    int rootX = findRoot(parent, x);
    int rootY = findRoot(parent, y);
    if (rootX != rootY)
        parent[rootY] = rootX;
}

int main() {
    int n, m;
    cin >> n >> m; // Nhập số lượng máy tính và số cạnh

    vector<Edge> edges; // Danh sách cạnh

    // Nhập m cạnh từ bàn phím
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        edges.push_back({u, v, d});
    }

    // Sắp xếp các cạnh theo trọng số tăng dần
    sortEdges(edges);

    int parent[1001]; // Mảng cha dùng cho DSU, giả sử n <= 1000
    for (int i = 1; i <= n; i++)
        parent[i] = i; // Ban đầu mỗi đỉnh là một tập riêng

    vector<Edge> mst; // Danh sách cạnh thuộc cây khung nhỏ nhất
    int totalCost = 0; // Tổng chi phí

    // Duyệt các cạnh đã sắp xếp
    for (int i = 0; i < m && mst.size() < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int d = edges[i].d;

        // Nếu u và v chưa cùng một tập, thêm cạnh vào MST
        if (findRoot(parent, u) != findRoot(parent, v)) {
            unionSet(parent, u, v);
            mst.push_back(edges[i]);
            totalCost += d;
        }
    }

    // In tổng chi phí
    cout << totalCost << endl;

    // In danh sách các cạnh thuộc cây khung nhỏ nhất
    for (int i = 0; i < mst.size(); i++) {
        cout << mst[i].u << " " << mst[i].v << " " << mst[i].d << endl;
    }
}