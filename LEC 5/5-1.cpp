#include <iostream>
using namespace std;

//Cấu trúc treeNode đại diện cho mỗi nút trong cây
struct treeNode {
    int data; // Lưu giá trị của nút
    treeNode* firstChild;  //  trỏ đến con đầu tiên
    treeNode* sibling;    // trỏ đến anh chị em tiếp theo
};
treeNode* createNode(int data) {
    treeNode* newNode = new treeNode;
    newNode->data = data;
    newNode->firstChild = nullptr;
    newNode->sibling = nullptr;
    return newNode;
}
void addChild(treeNode* parent, treeNode* child) {
    if (parent->firstChild == nullptr) {
        parent->firstChild = child; // Nếu nút cha chưa có con, nút con sẽ là con đầu tiên
    }
    else {
        treeNode* current = parent->firstChild;
        while (current->sibling != nullptr) {
            current = current->sibling; // Duyệt đến nút con cuối cùng
        }
        current->sibling = child; // Thêm nút con vào cuối danh sách các con
    }
}
int treeHeight(treeNode* root) {
    if (root == nullptr) return 0;

    int maxHeight = 0;
    treeNode* child = root->firstChild;
    while (child != nullptr) {
        int height = treeHeight(child);
        if (height > maxHeight) {
            maxHeight = height;
        }
        child = child->sibling;
    }
    return maxHeight + 1;
}
// Duyệt thứ tự Preorder
void preorder(treeNode* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    for (treeNode* child = root->firstChild; child != nullptr; child = child->sibling) {
        preorder(child);
    }
}

// Duyệt thứ tự Postorder)
void postorder(treeNode* root) {
    if (root == nullptr) return;

    for (treeNode* child = root->firstChild; child != nullptr; child = child->sibling) {
        postorder(child);
    }
    cout << root->data << " ";
}

