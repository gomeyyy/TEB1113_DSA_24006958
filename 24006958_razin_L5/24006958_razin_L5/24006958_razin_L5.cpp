/*
Name: Muhammad Razin Rahimi Bin Abdul Shukur
Student ID: 24006958
Group: G1
Lab: 5
--Stack--
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

class Stack {
private:
	Node* top;

public:
	Stack() {
		top = nullptr;
	}

	void push(string name) {
		cout << "Pushing " << name << " onto stack..." << endl;
		Node* newNode = new Node(name, top);
		top = newNode;
		cout << name << " pushed onto stack." << endl;
	}

	void pop() {
		if (top == nullptr) {
			cout << "Stack empty, nothing to pop.\n";
			return;
		}
		else {
			Node* temp = top;
			cout << "Popping the top " << temp->name << " ...\n\n";
			top = top->nextPtr;
			delete temp;
		}
	}

	string peek() {
		if (top == nullptr) {
			throw runtime_error("Stack empty, cannot peek");
		}
		return top->name;
	}

	void display() {
		Node* current = top;
		while (current != nullptr) {
			cout << current->name << "->";
			current = current->nextPtr;
		}
		cout << "NULL" << endl;
	}

};

int main() {
	Stack stack;

	stack.pop();

	stack.push("Ali");
	stack.display();

	stack.push("Ghazali");
	stack.display();

	stack.push("Aliya");
	stack.display();

	cout << "Top of stack: " << stack.peek();

	cout << "\n\nPop stack...\n\n";
	stack.pop();

	cout << "Stack after pop: ";
	stack.display();

	cout << "Top of stack after pop: " << stack.peek() << endl;

	return 0;
}

