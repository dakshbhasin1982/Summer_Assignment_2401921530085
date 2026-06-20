 #include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> inputStack;
    stack<int> outputStack;

    void transfer() {

        if(outputStack.empty()) {

            while(!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }

public:

    void push(int x) {
        inputStack.push(x);
    }

    int pop() {

        transfer();

        int front = outputStack.top();
        outputStack.pop();

        return front;
    }

    int peek() {

        transfer();

        return outputStack.top();
    }

    bool empty() {

        return inputStack.empty() &&
               outputStack.empty();
    }
};

int main() {

    MyQueue q;

    q.push(1);
    q.push(2);

    cout << "Front Element: "
         << q.peek() << endl;

    cout << "Removed: "
         << q.pop() << endl;

    cout << "Is Queue Empty? "
         << (q.empty() ? "Yes" : "No")
         << endl;

    return 0;
}