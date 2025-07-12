/*
Name: Muhammad Razin Rahimi Bin Abdul Shukur
Student ID: 24006958
Group: G1
Topic: Singly Linked List
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
		tail = nullptr;
	}

	void add(string name) {
		Node* newNode = new Node(name);
		if (head == nullptr) {
			head = tail = newNode;
		}
		else {
			tail->nextPtr = newNode;
			tail = newNode;
		}
		tail->nextPtr = head;
	}

	void remove(string name) {
		if (!head) return;

		if (head == tail && head->name == name) {
			delete head;
			head = tail = nullptr;
			return;
		}

		if (head->name == name) {
			Node* temp = head;
			head = head->nextPtr;
			tail->nextPtr = head;
			delete temp;
			return;
		}

		Node* current = head;
		while (current->nextPtr != head && current->nextPtr->name != name) {
			current = current->nextPtr;
		}

		if (current->nextPtr != head) {
			Node* temp = current->nextPtr;
			current->nextPtr = temp->nextPtr;
			if (temp == tail) {
				tail = current;
			}
			delete temp;
		}
	}

	void display() {
		if (head == nullptr) {
			cout << "Empty List\n";
			return;
		}

		Node* current = head;
		do {
			cout << current->name << "->";
			current = current->nextPtr;
		} while (current != head);
		cout << "(back to head)" << endl;
	}

	~LinkedList() {
		if (!head) return;

		Node* current = head;

		while (current) {
			Node* temp = current;
			current = current->nextPtr;
			delete temp;
		}
	}

};

int main() {
	LinkedList list;

	list.add("Ali");
	list.add("Ghazali");
	list.add("Aliya");
	list.add("Abu");

	cout << "Linked List: ";
	list.display();

	cout << "Remove Abu..." << endl;
	list.remove("Abu");

	cout << "Linked List after removal: ";
	list.display();

	return 0;
}
