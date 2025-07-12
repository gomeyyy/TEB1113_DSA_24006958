/*
Name: Muhammad Razin Rahimi Bin Abdul Shukur
Student ID: 24006958
Group: G1
Lab: 6
--Queue and Circular Queue--
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

class Queue {
private:
    Node* front;
    Node* back;

    
public:

    Queue() {
        front = nullptr;
        back = nullptr;
    }

    void enqueue(string name) {
        cout << "Enqueueing " << name << "..." << endl;
        Node* newNode = new Node(name);
        if (front == nullptr) { //Empty Q
            front = back = newNode;
        }
        else {
            back->nxtPtr = newNode;
            back = newNode;
        }
    }

    void dequeue() {
        cout << "Trying to dequeue..." << endl;
        if (front == nullptr) {
            cout << "Queue is Empty" << endl;
            return;
        }
        else {
            Node* temp = front;
            cout << "Dequeueing " << temp->name << " (front of Q)..." << endl;
            front = front->nxtPtr;
            delete temp;
        }
    }

    void display() {
        Node* current = front;
        while (current != nullptr) {
            cout << current->name << "->";
            current = current->nxtPtr;
        }
        cout << "NULL" << endl;
        cout << "Front of Q: " << front->name << endl;
        cout << "Back of Q: " << back->name << endl;
    }
};

class CircularQueue {
private:
    Node* front;
    Node* back;
    
public:

    CircularQueue() {
        front = nullptr;
        back = nullptr;
    }

    void enqueue(string name) {
        cout << "Enqueueing " << name << "..." << endl;
        Node* newNode = new Node(name);
        if (front == nullptr) { //Empty Q
            front = back = newNode;
            newNode->nxtPtr = front;
        }
        else {
            back->nxtPtr = newNode;
            back = newNode;
            back->nxtPtr = front; //Loop to front
        }
    }

    void dequeue() {
        cout << "Trying to dequeue..." << endl;

        if (front == nullptr) {
            cout << "Queue is Empty" << endl;
            return;
        }

        Node* temp = front;

        if (front == back) { // Only one node
            cout << "Dequeueing " << temp->name << " (only node)..." << endl;
            delete temp;
            front = back = nullptr;
        }
        else {
            cout << "Dequeueing " << temp->name << " (front of Q)..." << endl;
            front = front->nxtPtr;
            back->nxtPtr = front; // Maintain circularity
            delete temp;
        }
    }

    void display() {
        Node* current = front;
        for (int i = 0; i < 3; i++) {
            do {
                cout << current->name << " -> ";
                current = current->nxtPtr;
            } while (current != front);
        }
        cout << "NULL" << endl;
        cout << "Front of Q: " << front->name << endl;
        cout << "Back of Q: " << back->name << endl;
    }
};



int main()
{
    Queue q;

    q.enqueue("Ali");
    q.display();

    q.enqueue("Ghazali");
    q.display();

    q.enqueue("Aliya");
    q.display();

    q.dequeue();
    q.display();

    cout << endl << "\n===Circular Queue===" << endl;

    CircularQueue cq;

    cq.enqueue("Ali");
    cq.display();

    cq.enqueue("Ghazali");
    cq.display();

    cq.enqueue("Aliya");
    cq.display();

    cq.dequeue();
    cq.display();


}
