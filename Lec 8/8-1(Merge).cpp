#include <iostream>
#include <vector>

using namespace std;

// Hàm trộn hai mảng con đã sắp xếp
void merge(vector<double>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tạo các mảng tạm
    vector<double> L(n1);
    vector<double> R(n2);

    // Sao chép dữ liệu vào các mảng tạm L[] và R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của L[], nếu có
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của R[], nếu có
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Hàm Merge Sort đệ quy
void mergeSort(vector<double>& arr, int left, int right) {
    if (left < right) {
        // Tương tự như (left+right)/2, nhưng tránh tràn cho các giá trị lớn của left và right
        int mid = left + (right - left) / 2;

        // Sắp xếp đệ quy nửa đầu và nửa sau
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Trộn các mảng đã sắp xếp
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;

    vector<double> numbers;
    for (int i = 0; i < n; ++i) {
        double num;
        cin >> num;
        numbers.push_back(num);
    }

    mergeSort(numbers, 0, numbers.size() - 1);

    // In các số đã sắp xếp
    for (int i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
