#include <iostream> 
#include <vector>.
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây nhị phân
struct TreeNode {
    int data;       // Dữ liệu của nút .
    TreeNode* left;    // Con trỏ đến nút con bên trái.
    TreeNode* right;   // Con trỏ đến nút con bên phải.

    // Hàm tạo của nút.  Khởi tạo data với value, left và right là nullptr.
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Hàm để chèn một nút vào BST
TreeNode* insertTreeNode(TreeNode* root, int value) {
    if (root == nullptr) { // Nếu cây rỗng
        return new TreeNode(value); // tạo nút mới và trả về.
    }

    if (value < root->data) { // Nếu giá trị nhỏ hơn nút hiện tại,
        root->left = insertTreeNode(root->left, value); // chèn vào bên trái.
    }
    else if (value > root->data) { // Nếu giá trị lớn hơn nút hiện tại,
        root->right = insertTreeNode(root->right, value); // chèn vào bên phải.
    }

    return root; // Trả về nút gốc (có thể đã được cập nhật).
}

// Hàm để tìm nút có giá trị nhỏ nhất trong cây con bên phải
TreeNode* findMin(TreeNode* node) {
    while (node->left != nullptr) { // Đi xuống nhánh trái cho đến khi không còn nút trái nào.
        node = node->left;
    }
    return node; // Trả về nút có giá trị nhỏ nhất.
}

// Hàm để xóa một nút khỏi BST
TreeNode* deleteTreeNode(TreeNode* root, int value) {
    if (root == nullptr) { // Nếu cây rỗng hoặc không tìm thấy nút, trả về nullptr.
        return nullptr;
    }

    if (value < root->data) { // Nếu giá trị cần xóa nhỏ hơn nút hiện tại, xóa ở bên trái.
        root->left = deleteTreeNode(root->left, value);
    }
    else if (value > root->data) { // Nếu giá trị cần xóa lớn hơn nút hiện tại, xóa ở bên phải.
        root->right = deleteTreeNode(root->right, value);
    }
    else { // Đã tìm thấy nút cần xóa
        // Trường hợp 1: Nút lá hoặc có một con
        if (root->left == nullptr) {
            TreeNode* temp = root->right; // Lưu con phải (có thể là nullptr).
            delete root;             // Xóa nút hiện tại.
            return temp;            // Trả về con phải.
        }
        else if (root->right == nullptr) {
            TreeNode* temp = root->left;  // Lưu con trái.
            delete root;             // Xóa nút hiện tại.
            return temp;            // Trả về con trái.
        }
        // Trường hợp 2: Nút có hai con
        else {
            // Tìm nút nhỏ nhất trong cây con bên phải
            TreeNode* temp = findMin(root->right);
            root->data = temp->data;             //Thay thế giá trị
            root->right = deleteTreeNode(root->right, temp->data); // Xóa nút thay thế (nút nhỏ nhất bên phải).
        }
    }
    return root; // Trả về nút gốc (có thể đã được cập nhật).
}

// Hàm để in BST theo thứ tự inorder (để kiểm tra)
void printInorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    // 1. Tạo BST từ danh sách ban đầu: 2, 1, 10, 6, 3, 8, 7, 13, 20
    vector<int> initialValues = { 2, 1, 10, 6, 3, 8, 7, 13, 20 };
    TreeNode* root = nullptr;
    for (int value : initialValues) {
        root = insertTreeNode(root, value); // Chèn từng giá trị vào BST.
    }

    cout << "Binary Search Tree ban dau:\n";
    printInorder(root); // In cây ban đầu.

    // 2. Chèn các giá trị: 14, 0, 35
    root = insertTreeNode(root, 14);
    root = insertTreeNode(root, 0);
    root = insertTreeNode(root, 35);
    cout << "\nBinary Search Tree sau khi chen 14, 0, 35:\n";
    printInorder(root); // In cây sau khi chèn.

    // 3. Xóa các giá trị: 6, 13, 35
    root = deleteTreeNode(root, 6);
    root = deleteTreeNode(root, 13);
    root = deleteTreeNode(root, 35);
    cout << "\nBinary Search Tree sau khi xoa 6, 13, 35:\n";
    printInorder(root); // In cây sau khi xóa.

    return 0; // Kết thúc chương trình.
}

