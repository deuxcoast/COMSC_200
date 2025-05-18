#include <iostream>
using namespace std;

const int SIZE = 100;  // Maximum size of the stack

class Stack {
   private:
    char arr[SIZE];  // array to store stack elements
    int top;

   public:
    Stack() { top = -1; }

    bool isFull() { return top == SIZE - 1; }

    bool isEmpty() { return top == -1; }

    void push(char c) {
        if (!isFull()) {
            arr[++top] = c;
        } else {
            cout << "Stack overflow!\n";
        }
    }

    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        } else {
            cout << "Stack underflow!\n";
            return '\0';  // return null character if stack is empty
        }
    }
};

int main() {
    Stack s;
    string word;

    cout << "Enter a word: ";
    cin >> word;

    // Push each character onto the stack
    for (char c : word) {
        s.push(c);
    }

    cout << "Reversed word: ";
    // Pop characters from the stack to print in reverse
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;

    return 0;
}
