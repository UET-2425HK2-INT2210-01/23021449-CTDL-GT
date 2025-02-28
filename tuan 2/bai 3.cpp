#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() : head(nullptr) {}

    void append(int data) {
        Node* newNode = new Node{data, nullptr, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    int count_triplets() {
        int count = 0;
        Node* current = head;
        while (current && current->next && current->next->next) {
            if (current->data + current->next->data + current->next->next->data == 0) {
                count++;
            }
            current = current->next;
        }
        return count;
    }
};
int main() {
    int n;
    cin >> n;
    DoublyLinkedList list;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        list.append(num);
    }
    cout << list.count_triplets() << endl;
    return 0;
}
