#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void push_front(int value) {
        try {
            if (value < 0) {
                throw exception("ERROR! Value < 0!");
            }
            Node* newNode = new Node();
            newNode->data = value;
            newNode->prev = nullptr;
            newNode->next = head;

            if (head != nullptr) {
                head->prev = newNode;
            }

            head = newNode;
        }
        catch (exception ex) {
            cout << ex.what() << endl;
        }
    }

    void push_back(int value) {
        try {
            if (value > 20) {
                throw exception("Error! value > 20!");
            }
            Node* newNode = new Node();
            newNode->data = value;
            newNode->prev = nullptr;
            newNode->next = nullptr;

            if (head == nullptr) {
                head = newNode;
                return;
            }

            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }

            current->next = newNode;
            newNode->prev = current;
        }
        catch (exception ex) {
            cout << ex.what() << endl;
        }
    }

    void display() {
        try {
            Node* current = head;
            while (current != nullptr) {
                if (current->data < 5) {
                    throw exception("Error! Current->data < 5!");
                }
                else {
                    cout << current->data << " ";
                    current = current->next;
                }
            }
            cout << endl;
        }
        catch (exception ex) {
            cout << ex.what() << endl;
        }
    }
};

int main() {
    DoublyLinkedList myList;

    //myList.push_back(40);
    myList.push_back(10);
    myList.push_back(20);
    //myList.push_front(-2);
    myList.push_front(5);
    //myList.push_front(2);

    myList.display();  

    return 0;
}