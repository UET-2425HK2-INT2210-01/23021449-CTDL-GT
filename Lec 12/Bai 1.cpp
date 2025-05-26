#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Danh sách kề biểu diễn đồ thị có hướng giữa các nhiệm vụ
vector<int> graph[10005];

// Mảng đánh dấu các nhiệm vụ đã được duyệt
bool visited[10005];

// Ngăn xếp lưu thứ tự thực hiện sau khi sắp xếp topo
stack<int> taskOrder;

// Hàm duyệt DFS từ một nhiệm vụ cụ thể
void performDFS(int task) {
    visited[task] = true;  // Đánh dấu nhiệm vụ đã được duyệt
    for (int nextTask : graph[task]) {  // Duyệt các nhiệm vụ phụ thuộc
        if (!visited[nextTask]) {
            performDFS(nextTask);       // Đệ quy tiếp tục DFS
        }
    }
    taskOrder.push(task);  // Sau khi xử lý xong, đẩy vào ngăn xếp
}

// Hàm sắp xếp topo sử dụng DFS
void topologicalSort(int totalTasks) {
    fill(visited, visited + totalTasks + 1, false);  // Reset trạng thái duyệt

    for (int task = 1; task <= totalTasks; ++task) {
        if (!visited[task]) {
            performDFS(task);  // Bắt đầu DFS nếu nhiệm vụ chưa duyệt
        }
    }
}

int main() {
    ifstream inputFile("jobs.txt");   // Mở file chứa dữ liệu đầu vào
    ofstream outputFile("jobs.out");  // Mở file để ghi kết quả đầu ra

    int numTasks, numDependencies;
    inputFile >> numTasks >> numDependencies;  // Đọc số nhiệm vụ và ràng buộc

    // Đọc danh sách ràng buộc giữa các nhiệm vụ
    for (int i = 0; i < numDependencies; ++i) {
        int prerequisite, dependent;
        inputFile >> prerequisite >> dependent;  
        graph[prerequisite].push_back(dependent);  // Thêm cạnh: prerequisite -> dependent
    }

    topologicalSort(numTasks);  // Thực hiện sắp xếp topo

    // Ghi kết quả thứ tự nhiệm vụ ra file
    while (!taskOrder.empty()) {
        outputFile << taskOrder.top() << " ";  // Ghi nhiệm vụ trên cùng ngăn xếp
        taskOrder.pop();                       // Gỡ khỏi ngăn xếp
    }

    inputFile.close();   
    outputFile.close();  

    return 0;
}