#include <iostream>
using namespace std;

//Cấu trúc treeNode đại diện cho mỗi nút trong cây
struct Node {
    int data; // Lưu giá trị của nút
    Node* firstChild;  //  trỏ đến con đầu tiên
    Node* sibling;    // trỏ đến anh chị em tiếp theo
};
//Hàm createNode tạo một nút mới với giá trị cho trước và khởi tạo các con trỏ con va anh em về null.
Node* createNode(int data) {
    Node* newNode = new Node();  //Cấp phát bộ nhớ cho nút mới
    newNode->data = data;  //Gán giá trị data
    newNode->firstChild = nullptr; //Khởi tạo con đầu tiên là null
    newNode->sibling = nullptr; //Khởi tạo anh chị em là null
    return newNode; //Trả về nút mới tạo
}
void addChild(Node* parent,Node* child) {
    if (parent->firstChild == nullptr) { // Nếu cha chưa có con nào
        parent->firstChild = child; // Thêm làm con đầu tiên
    }
    else {
        Node* temp = parent->firstChild; // Bắt đầu từ con đầu tiên
        while (temp->sibling != nullptr) { // Duyệt đến cuối danh sách anh em
            temp = temp->sibling;
        }
        temp->sibling = child;  // Thêm vào cuối danh sách
    }
}
// Hàm tìm kiếm một nút trong cây
Node* findNode(Node* root, int data) {
    if (root == nullptr) return nullptr; // Nếu cây rỗng
    if (root->data == data) return root; // Nếu tìm thấy

    Node* found = findNode(root->firstChild, data); // Tìm trong các con
    if (found != nullptr) return found; // Nếu tìm thấy trong cây con

    return findNode(root->sibling, data); // Tìm trong các anh em
}

// Hàm tính chiều cao cây theo nguyên tắc: Chiều cao cây con lớn nhất + 1
int height(Node* root) {
    if (root == nullptr) return 0; // Cây rỗng cao 0

    int maxHeight = 0;
    Node* child = root->firstChild; // Bắt đầu từ con đầu tiên
    while (child != nullptr) { // Duyệt tất cả con
        int currentHeight = height(child); // Tính chiều cao cây con
        if (currentHeight > maxHeight) {
            maxHeight = currentHeight; // Cập nhật chiều cao lớn nhất
        }
        child = child->sibling; // Chuyển sang con kế tiếp
    }
    return maxHeight + 1; // Chiều cao = max con + 1
}
// Hàm duyệt cây theo thứ tự preorder (Nút gốc - Con trái - Con phải)
void preorder(Node* node) {
    if (node == nullptr) return;

    cout << node->data << " "; // In ra dữ liệu của nút hiện tại
    Node* child = node->firstChild;
    while (child != nullptr) {
        preorder(child); // Duyệt qua các nút con
        child = child->sibling;
    }
}

// Hàm duyệt cây theo thứ tự postorder (Con trái - Con phải - Nút gốc)
void postorder(Node* node) {
    if (node == nullptr) return;

    Node* child = node->firstChild;
    while (child != nullptr) {
        postorder(child); // Duyệt qua các nút con
        child = child->sibling;
    }
    cout << node->data << " "; // In ra dữ liệu của nút hiện tại
}
// Hàm kiểm tra xem cây có phải là cây nhị phân hay không
bool isBinary(Node* node) {
    if (node == nullptr) return true; // Cây rỗng là cây nhị phân
    int childCount = 0;
    Node* child = node->firstChild;
    while (child != nullptr) {
        childCount++;
        if (!isBinary(child)) return false; // Kiểm tra đệ quy các con
        child = child->sibling;
    }
    if (childCount > 2) return false; // Nếu nút có nhiều hơn 2 con, không phải cây nhị phân
    return true;
}
// Hàm duyệt cây theo thứ tự inorder (trái-gốc-phải) - điều chỉnh cho cây tổng quát
void inorder(Node* node) {
    if (node == nullptr) return;

    // Duyệt cây con đầu tiên (nếu có)
    if (node->firstChild != nullptr) {
        inorder(node->firstChild);
    }

    // In ra dữ liệu của nút hiện tại
    cout << node->data << " ";

    // Duyệt qua các nút anh chị em (nếu có)
    Node* sibling = node->firstChild != nullptr ? node->firstChild->sibling : nullptr;
    while (sibling != nullptr) {
        inorder(sibling);
        sibling = sibling->sibling;
    }
}
int main() {
    int N, M;
    cin >> N >> M; // Nhap số nút và số cạnh

    Node* root = nullptr;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v; // Nhap cặp cha-con

        if (root == nullptr) { // Nếu cây rỗng
            root = createNode(u); // Tạo nút gốc
            Node* child = createNode(v);
            addChild(root, child);
        }
        else {
            Node* parent = findNode(root, u); // Tìm nút cha
            if (parent != nullptr) {
                Node* child = createNode(v); // Tạo nút con
                addChild(parent, child); // Thêm vào cây
            }
        }
    }

    // Tính và in chiều cao
    int Height = height(root);
    cout << height << endl;

    // duyet kieu preorder
    preorder(root);
    cout << endl;

    // duyet kieu postrder
    postorder(root);
    cout << endl;

    // kiem tra xem co phai la cay nhi phan hay khong ---> neu la cay nhi phan duyet lieu inorder , beu khong thi cout .....
    if (isBinary(root)) {
        inorder(root);
        cout << endl;
    }
    else {
        cout << "NOT BINARY TREE" << endl;
    }

    return 0;
}