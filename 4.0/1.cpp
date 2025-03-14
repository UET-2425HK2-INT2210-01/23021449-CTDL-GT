#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void search(int value) {
        Node* temp = head;
        int index = 0;
        while (temp) {
            if (temp->value == value) {
                cout << index << endl;
                return;
            }
            temp = temp->next;
            index++;
        }
        cout << "NO" << endl;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    int n;
    cin >> n;
    LinkedList linkedList;

    for (int i = 0; i < n; ++i) {
        string command;
        cin >> command;

        if (command == "append") {
            int value;
            cin >> value;
            linkedList.append(value);
        } else if (command == "search") {
            int value;
            cin >> value;
            linkedList.search(value);
        } else if (command == "reverse") {
            linkedList.reverse();
        }
    }

    linkedList.display();
    return 0;
}
