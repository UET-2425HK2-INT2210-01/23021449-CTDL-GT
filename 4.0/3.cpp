#include <iostream>
#include <string>

using namespace std;

class Stack {
private:
    char elements[1000];
    int top;

public:
    Stack() {
        top = -1;
    }
    void push(char c) {
        if (top < 999) {
            elements[top++] = c;
        }
    }
    char pop() {
        if (top >= 0) {
            return elements[top--];
        }
        return '\0';
    }
    bool isEmpty() {
        return (top == -1);
    }
};
bool isValid(const string& s) {
    Stack st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            char topElement = st.pop();
            if ((c == ')' && topElement != '(') ||
                (c == ']' && topElement != '[') ||
                (c == '}' && topElement != '{')) {
                return false;
            }
        }
    }
    return st.isEmpty();
}
int main() {
    string s;
    cin >> s;
    if (isValid(s)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }
    return 0;
}
