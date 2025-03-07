class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}

    // Thêm phần tử vào ngăn xếp
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    // Lấy phần tử ra khỏi ngăn xếp
    int pop() {
        if (top == nullptr) throw std::out_of_range("Ngan xếp rỗng");
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    // Lấy phần tử ở đỉnh ngăn xếp mà không xóa
    int peek() {
        if (top == nullptr) throw std::out_of_range("Ngăn xếp rỗng");
        return top->data;
    }

    // Kiểm tra ngăn xếp có rỗng hay không
    bool isEmpty() {
        return top == nullptr;
    }

    // Giải phóng bộ nhớ
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};