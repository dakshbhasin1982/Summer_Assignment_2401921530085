#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int data) {
        value = data;
        next = nullptr;
    }
};

Node* findMiddleNode(Node* head) {
    Node* slowPointer = head;
    Node* fastPointer = head;

    while (fastPointer != nullptr && fastPointer->next != nullptr) {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
    }

    return slowPointer;
}

void displayList(Node* head) {
    while (head != nullptr) {
        cout << head->value;

        if (head->next != nullptr) {
            cout << " -> ";
        }

        head = head->next;
    }

    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    cout << "Linked List: ";
    displayList(head);

    Node* middleNode = findMiddleNode(head);

    cout << "Middle Node: " << middleNode->value << endl;

    return 0;
}