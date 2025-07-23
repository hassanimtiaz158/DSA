#include <iostream>
using namespace std;

class linkedlist {
private:
    typedef struct node {
        int data;
        node* next;
    }* nodeptr;

    nodeptr head;
    nodeptr current;
    nodeptr temp;

public:
    linkedlist() {
        head = nullptr;
        current = nullptr;
        temp = nullptr;
    }

    void insertatend(int value) {
        nodeptr n = new node;
        n->next = nullptr;
        n->data = value;

        if (head != nullptr) {
            current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = n;
        } else {
            head = n;
        }
    }

    void delnode(int value) {
        temp = head;
        current = head;

        while (current != nullptr && current->data != value) {
            temp = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Value not found in the list.\n";
        } else {
            if (current == head) {
                head = head->next;
                delete current;
            } else {
                temp->next = current->next;
                delete current;
            }
            cout << "Node with value " << value << " deleted.\n";
        }
    }

    void print() {
        current = head;
        if (current == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        cout << "Linked list: ";
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    linkedlist l;

    l.insertatend(10);
    l.insertatend(20);
    l.insertatend(30);
    l.print();         // Output: 10 -> 20 -> 30 -> NULL

    l.delnode(20);     // Deletes node with value 20
    l.print();         // Output: 10 -> 30 -> NULL

    l.delnode(40);     // Value not found
    l.print();         // Output: 10 -> 30 -> NULL

    return 0;
}

