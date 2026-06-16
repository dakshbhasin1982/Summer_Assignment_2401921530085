#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

bool hasCycle(Node* head) {
    unordered_set<Node*> visited;

    while (head != nullptr) {
        if (visited.find(head) != visited.end()) {
            return true;
        }

        visited.insert(head);
        head = head->next;
    }

    return false;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    // Creating a cycle
    head->next->next->next->next = head->next;

    if (hasCycle(head))
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle Found" << endl;

    return 0;
}