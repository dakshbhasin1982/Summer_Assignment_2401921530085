#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> incoming;
    stack<int> outgoing;

    void moveElements() {
        while (!incoming.empty()) {
            outgoing.push(incoming.top());
            incoming.pop();
        }
    }

public:
    void push(int x) {
        incoming.push(x);
    }

    int pop() {
        if (outgoing.empty()) {
            moveElements();
        }

        int value = outgoing.top();
        outgoing.pop();

        return value;
    }

    int peek() {
        if (outgoing.empty()) {
            moveElements();
        }

        return outgoing.top();
    }

    bool empty() {
        return incoming.empty() && outgoing.empty();
    }
};

int main() {
    MyQueue q;

    q.push(1);
    q.push(2);

    cout << "Front Element: " << q.peek() << endl;
    cout << "Removed Element: " << q.pop() << endl;

    if (q.empty()) {
        cout << "Queue is Empty" << endl;
    } else {
        cout << "Queue is Not Empty" << endl;
    }

    return 0;
}