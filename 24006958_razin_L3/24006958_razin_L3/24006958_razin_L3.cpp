/*
name: Muhammad Razin Rahimi
id: 24006958
lab: 3
--Singly & Doubly Linked List--
*/

#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* nxtPtr;

    Node(string name) {
        this->name = name;
        this->nxtPtr = nullptr;
    }
};

class DoublyNode {
public:
    string name2;
    DoublyNode* prev;
    DoublyNode* next;

    DoublyNode(string name2) {
        this->name2 = name2;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void display(){

        cout << "Linked list: " << endl;
        Node* currentNode = head;
        while (currentNode != nullptr) {
            cout << currentNode->name << "->";
            currentNode = currentNode->nxtPtr;
        }
        cout << "NULL" << endl;
    }

    void add_element(string name) {
        Node* newNode = new Node(name);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->nxtPtr = newNode;
            tail = newNode;
        }
    }

    void deleteByVal(string name) {
        if (head == nullptr) {
            cout << "List is Empty" << endl;
            return;
        }
        // Delete if value found on first node
        if (head->name == name) {
            Node* temp = head;
            head = head->nxtPtr;
            delete temp;
            if (head == nullptr) {
                tail = nullptr;
                return;
            }
        }
        // Traversing list to search for value in the next node
        Node* currentNode = head;
        while (currentNode->nxtPtr != nullptr && currentNode->nxtPtr->name != name) {
            currentNode = currentNode->nxtPtr;
        }

        if (currentNode->nxtPtr != nullptr) {
            Node* temp = currentNode->nxtPtr;
            currentNode->nxtPtr = currentNode->nxtPtr->nxtPtr;
            if (temp == tail) {
                tail = currentNode;
                delete temp;
            }
        }
    }
};

class DoublyLinked {
private:
    DoublyNode* head;
    DoublyNode* tail;

public:
    DoublyLinked() {
        head = nullptr;
        tail = nullptr;
    }

    void add_element(string name) {
        DoublyNode* newNode = new DoublyNode(name);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteByVal(string name) {
        DoublyNode* current = head;

        while (current != nullptr && current->name2 != name) {
            current = current->next;
        }

        if (current == nullptr) {
            return;
        }

        if (current == head) {
            head = current->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
        }
        else if (current == tail) {
            tail = current->prev;
            tail->next = nullptr;
        }
        else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        delete current;
    }

    void displayForward() {
        cout << "Doubly Linked List Forward: " << endl;
        DoublyNode* current = head;
        while (current != nullptr) {
            cout << current->name2 << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    void displayBackward() {
        cout << "Doubly Linked List Backward: " << endl;
        DoublyNode* current = tail;
        while (current != nullptr) {
            cout << current->name2 << " <-> ";
            current = current->prev;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList list;

    list.add_element("Razin");
    list.add_element("Rahimi");
    list.add_element("Gomey");

    list.display();

    list.deleteByVal("Rahimi");

    list.display();

    DoublyLinked doublyList;

    doublyList.add_element("Razin2");
    doublyList.add_element("Rahimi2");
    doublyList.add_element("Gomey2");

    doublyList.displayForward();
    doublyList.displayBackward();

    doublyList.deleteByVal("Razin2");

    doublyList.displayForward();
    doublyList.displayBackward();

    return 0;
}

