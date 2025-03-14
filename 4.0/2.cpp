#include <iostream>
using namespace std;
struct Node {
    int x;
    int p;
    Node* prev;
    Node* next;

    Node(int x, int p) : x(x), p(p), prev(nullptr), next(nullptr) {}
};
class PriorityQueue {
private:
    Node* head;

public:
    PriorityQueue() : head(nullptr) {}

    void enqueue(int x, int p) {
        Node* newNode = new Node(x, p);
        if (head == nullptr || p > head->p) {
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr && current->next->p >= p) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != nullptr) {
                current->next->prev = newNode;
            }
            current->next = newNode;
        }
    }
    void dequeue() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
        }
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << "(" << current->x << ", " << current->p << ")";
            if (current->next != nullptr) {
                cout << "; ";
            }
            current = current->next;
        }
    }
};
int main() {
    int n;
    cin >> n;
    PriorityQueue pq;
    for (int i = 0; i < n; ++i) {
        string command;
        cin >> command;
        if (command == "enqueue") {
            int x, p;
            cin >> x >> p;
            pq.enqueue(x, p);
        } else if (command == "dequeue") {
            pq.dequeue();
        }
    }

    pq.display();
    return 0;
}
