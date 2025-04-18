#include <iostream>

using namespace std;

// Hàm đệ quy để tìm GCD của hai số
int gcd(int x, int y) {
    // Trường hợp cơ sở: Nếu y là 0, thì GCD là x
    if (y == 0) {
        return x;
    }
    // Bước đệ quy: Sử dụng thuật toán Euclid
    return gcd(y, x % y);
}

int main() {
    int x, y;
    cin >> x >> y;
    // Tìm và in GCD
    int gcd = gcd(x, y);
    cout <<  gcd << endl;

    return 0;
}
