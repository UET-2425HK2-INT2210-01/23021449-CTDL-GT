#include <iostream>
#include <vector>

using namespace std;

int hoarePartition(vector<int>& arr, int low, int high)
{
    int pivot = arr[low]; // Chọn phần tử đầu tiên làm chốt.
    int i = low - 1;     // Khởi tạo chỉ số i ở bên ngoài đầu mảng.
    int j = high + 1;    // Khởi tạo chỉ số j ở bên ngoài cuối mảng.

    while(true){
        // Tăng chỉ số i cho đến khi tìm thấy phần tử >= chốt
        do{
            i++;
        }while(arr[i] < pivot);
        // Tăng chỉ số j cho đến khi tìm thấy phần tử <= chốt
        do{
            j--;
        }while(arr[j] > pivot);

        if(i >= j) return j; // nếu chỉ số i, j giao nhau thì trả về j

        swap(arr[i], arr[j]); // Hoán đổi 2 phần tử arr[i] và arr[j]
        }
    }


void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high) 
    {
        int pi = hoarePartition(arr, low, high); // Phân vùng mảng và lấy vị trí của chốt.

        // Sắp xếp đệ quy các phần tử trước và sau phân vùng
        quickSort(arr, low, pi);    // Sắp xếp nửa bên trái của mảng.
        quickSort(arr, pi + 1, high); // Sắp xếp nửa bên phải của mảng.
    }
}

void printArray(const vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}


void print(vector<int>& arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int n; 
    cin >> n; 
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i]; 
    }

    quickSort(arr, 0, n - 1); 
    print(arr); 
    return 0; 
}
