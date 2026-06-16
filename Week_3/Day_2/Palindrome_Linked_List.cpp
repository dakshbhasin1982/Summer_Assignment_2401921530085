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

Node* reversePart(Node* startNode) {

    Node* previousNode = nullptr;
    Node* currentNode = startNode;

    while (currentNode != nullptr) {

        Node* nextNode = currentNode->next;

        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
    }

    return previousNode;
}

bool isPalindromeList(Node* head) {

    if (head == nullptr || head->next == nullptr) {
        return true;
    }

    Node* slowPointer = head;
    Node* fastPointer = head;

    while (fastPointer->next != nullptr &&
           fastPointer->next->next != nullptr) {

        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
    }

    Node* secondHalfHead = reversePart(slowPointer->next);

    Node* firstHalfNode = head;
    Node* secondHalfNode = secondHalfHead;

    while (secondHalfNode != nullptr) {

        if (firstHalfNode->data != secondHalfNode->data) {
            return false;
        }

        firstHalfNode = firstHalfNode->next;
        secondHalfNode = secondHalfNode->next;
    }

    return true;
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
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    cout << "Linked List: ";
    printList(head);

    if (isPalindromeList(head)) {
        cout << "Palindrome: True" << endl;
    }
    else {
        cout << "Palindrome: False" << endl;
    }

    return 0;
}