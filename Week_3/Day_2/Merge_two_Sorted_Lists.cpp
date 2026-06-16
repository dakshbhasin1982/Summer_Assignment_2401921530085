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

Node* mergeSortedLists(Node* firstList, Node* secondList) {

    if (firstList == nullptr) {
        return secondList;
    }

    if (secondList == nullptr) {
        return firstList;
    }

    if (firstList->data <= secondList->data) {
        firstList->next = mergeSortedLists(firstList->next, secondList);
        return firstList;
    }

    secondList->next = mergeSortedLists(firstList, secondList->next);
    return secondList;
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

    Node* list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(4);

    Node* list2 = new Node(1);
    list2->next = new Node(3);
    list2->next->next = new Node(4);

    cout << "First List : ";
    printList(list1);

    cout << "Second List: ";
    printList(list2);

    Node* mergedHead = mergeSortedLists(list1, list2);

    cout << "Merged List: ";
    printList(mergedHead);

    return 0;
}