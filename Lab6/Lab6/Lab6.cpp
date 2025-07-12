/*
Name: Nur Adrianahafiy binti Muhammad Yazid
Student ID: 24006963
Group: G1
Topic: Circular Linked List
*/

#include <iostream>
using namespace std;

struct Node {
	string name;
	Node* nextPtr;

	Node(string name, Node* nextPtr = nullptr) {
		this->name = name;
		this->nextPtr = nextPtr;
	}
};

class LinkedList {
private:
	Node* head;
	Node* tail;

public:
	LinkedList() {
		head = nullptr;
		tail = head;
	}

	void add(string name) {
		Node* newNode = new Node(name);
		if (head == nullptr) {
			head = tail = newNode;
			tail->nextPtr = head;
		}
		else {
			tail->nextPtr = newNode;
			tail = newNode;
			tail->nextPtr = head;
		}
	}

	void remove(string name) {
		if (head == nullptr) {
			return;  // Empty list
		}

		// Case: Only one node in the list
		if (head == tail && head->name == name) {
			delete head;
			head = tail = nullptr;
			return;
		}

		// Case: Head needs to be removed
		if (head->name == name) {
			Node* temp = head;
			head = head->nextPtr;
			tail->nextPtr = head;
			delete temp;
			return;
		}

		// Case: Remove node other than head
		Node* current = head;
		do {
			if (current->nextPtr->name == name) {
				Node* temp = current->nextPtr;
				current->nextPtr = temp->nextPtr;

				if (temp == tail) {
					tail = current;
				}
				delete temp;
				return;
			}
			current = current->nextPtr;
		} while (current != head);
	}



	void display() {
		if (head == nullptr) return;

		Node* current = head;
		for (int i = 0; i < 3; i++) {
			do {
				cout << current->name << " -> ";
				current = current->nextPtr;
			} while (current != head);
		}
		cout << "(head)" << endl;
	}

	~LinkedList() {
		if (head == nullptr) return;

		Node* current = head;
		Node* temp;

		do {
			temp = current;
			current = current->nextPtr;
			delete temp;
		} while (current != head);

		head = nullptr;
		tail = nullptr;
	}



};

int main() {
	LinkedList list;

	list.add("Ali");
	list.add("Imran");
	list.add("Khairul");

	cout << "Linked List: ";
	list.display();

	cout << "Remove Ali..." << endl;
	list.remove("Ali");

	cout << "Linked List after removal: ";
	list.display();

	return 0;
}