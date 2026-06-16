#include <iostream>
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

Node* removeNthFromEnd(Node* head, int n) {

    Node dummyNode(0);
    dummyNode.next = head;

    Node* leadPointer = &dummyNode;
    Node* trailPointer = &dummyNode;

    for (int step = 0; step < n; step++) {
        leadPointer = leadPointer->next;
    }

    while (leadPointer->next != nullptr) {
        leadPointer = leadPointer->next;
        trailPointer = trailPointer->next;
    }

    Node* nodeToDelete = trailPointer->next;
    trailPointer->next = trailPointer->next->next;

    delete nodeToDelete;

    return dummyNode.next;
}

void printList(Node* head) {

    while (head != nullptr) {
        cout << head->data;

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

    int n = 2;

    cout << "Original List: ";
    printList(head);

    head = removeNthFromEnd(head, n);

    cout << "Updated List : ";
    printList(head);

    return 0;
}