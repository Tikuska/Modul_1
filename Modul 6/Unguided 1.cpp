#include <iostream>
#include <string>

using namespace std;

class Stack {
public:
    Stack() : top(nullptr), size(0) {}

    void push(char a) {
        Node* tmp = new Node;
        tmp->data = a;
        tmp->next = top;
        top = tmp;
        size++;
    }

    char pop() {
        if (size == 0) {
            cerr << "Stack is empty!" << endl;
            exit(1);
        }
        char data = top->data;
        Node* tmp = top;
        top = top->next;
        delete tmp;
        size--;
        return data;
    }

    bool isEmpty() const {
        return size == 0;
    }

private:
    struct Node {
        char data;
        Node* next;
    };

    Node* top;
    int size;
};

int main() {
    Stack stack;
    string input;
    cout << "Masukkan kalimat: ";
    getline(cin, input);

    for (char c : input) {
        stack.push(c);
    }

    string reversed;
    while (!stack.isEmpty()) {
        reversed += stack.pop();
    }

    bool isPalindrome = (input == reversed);
    if (isPalindrome) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    return 0;
}
