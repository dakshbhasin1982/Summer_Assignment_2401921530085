#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> stk;
    stack<int> minStk;

public:

    void push(int val) {

        stk.push(val);

        if(minStk.empty()) {
            minStk.push(val);
        }
        else {
            minStk.push(min(val, minStk.top()));
        }
    }

    void pop() {

        if(stk.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        stk.pop();
        minStk.pop();
    }

    int top() {

        if(stk.empty()) {
            return -1;
        }

        return stk.top();
    }

    int getMin() {

        if(minStk.empty()) {
            return -1;
        }

        return minStk.top();
    }
};

int main() {

    MinStack st;

    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout << "Top Element: " << st.top() << endl;
    cout << "Minimum Element: " << st.getMin() << endl;

    st.pop();

    cout << "After Pop" << endl;
    cout << "Top Element: " << st.top() << endl;
    cout << "Minimum Element: " << st.getMin() << endl;

    return 0;
}