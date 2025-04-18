#include <iostream>
#include <string>
#include <vector>

using namespace std;

void generateBinaryRecursive(int n, string currentBinary, vector<string>& result) {
    // Trường hợp cơ sở: Nếu độ dài của chuỗi nhị phân hiện tại bằng n, thêm nó vào kết quả
    if (currentBinary.length() == n) {
        result.push_back(currentBinary);
        return;
    }

    // Gọi đệ quy cho cả hai trường hợp: thêm '0' và thêm '1'
    generateBinaryRecursive(n, currentBinary + "0", result);
    generateBinaryRecursive(n, currentBinary + "1", result);
}

int main() {
    int n;
    cin >> n;

    vector<string> binaryNumbers;
    // Gọi hàm đệ quy để bắt đầu tạo số nhị phân từ chuỗi rỗng
    generateBinaryRecursive(n, "", binaryNumbers);

    // In các số nhị phân
    for (const string& binary : binaryNumbers) {
        cout << binary << endl;
    }

    return 0;
}
