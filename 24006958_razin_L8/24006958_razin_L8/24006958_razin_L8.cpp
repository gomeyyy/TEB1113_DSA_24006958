
/*
Name: Muhammad Razin Rahimi Bin Abdul Shukur
Student ID: 24006958
Group: G1
Lab: 8
--Binary Search Tree--
*/

#include <iostream>
using namespace std;

class Node {
public:
    int name;
    Node* left;
    Node* right;

    Node(int n) {
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

    void insert(int n) {
        if (root == nullptr)
            root = new Node(n);
        else
            insertHelper(root, n);
    }

    void insertHelper(Node* current, int n) {
        if (n < current->name) {
            if (current->left == nullptr)
                current->left = new Node(n);
            else
                insertHelper(current->left, n);
        }
        else {
            if (current->right == nullptr)
                current->right = new Node(n);
            else
                insertHelper(current->right, n);
        }
    }

    void display_tree() {
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

    void inOrder(int target) {
        inOrder(root,target);
    }

    void inOrder(Node* parent, int target) {
        if (parent != nullptr) {
            inOrder(parent->left, target);
            if (parent->name == target) {
                cout << parent->name << "   FOUND";
            }
            inOrder(parent->right, target);
        }
    }
};

int main() {
    Tree tree;

    tree.insert(12);
    tree.insert(2);
    tree.insert(53);
    tree.insert(82);
    tree.insert(20);
    tree.insert(18);
    tree.insert(22);
    tree.insert(0);

    tree.display_tree();

    cout << "\n\n";
    tree.inOrder(82);

    return 0;
}
