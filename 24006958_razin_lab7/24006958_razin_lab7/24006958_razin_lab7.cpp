/*
Name: Muhammad Razin Rahimi Bin Abdul Shukur
Student ID: 24006958
Group: G1
Lab: 7
--Tree--
*/

#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    void add_root(string name) {
        root = new Node(name);
    }

    void add_left(Node* parent, string name) {
        parent->left = new Node(name);
    }

    void add_right(Node* parent, string name) {
        parent->right = new Node(name);
    }

    void display_tree() {
        // display_tree(node, depth/spacing, Label)
        // start with empty label, no depth
        display_tree(root, 0, "Root-");  
    }

    // Helper with label
    void display_tree(Node* node, int depth, string label) {
        if (node == nullptr) return; //end of recursion

        // Indentation
        for (int i = 0; i < depth; ++i)
            cout << "   ";

        // Print with label
        cout << label << node->name << endl;

        // Recursive calls to display Left and Right Child
        display_tree(node->left, depth + 1, "Left-");
        display_tree(node->right, depth + 1, "Right-");
    }
};

int main() {
    Tree tree;

    tree.add_root("A");
    tree.add_left(tree.root, "B");
    tree.add_right(tree.root, "C");
    tree.add_left(tree.root->left, "D");
    tree.add_right(tree.root->left, "E");
    tree.add_left(tree.root->right, "F");
    tree.add_right(tree.root->right, "G");
    tree.display_tree();

    return 0;
}