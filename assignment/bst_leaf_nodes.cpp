#include <iostream>
#include <vector>

// Simple Binary Search Tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Insert a value into the BST
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    // If val == root->data, do nothing (no duplicates)
    return root;
}

// Collect leaf nodes in-order
void collectLeaves(Node* root, std::vector<int>& leaves) {
    if (!root) return;
    if (!root->left && !root->right) {
        leaves.push_back(root->data);
        return;
    }
    collectLeaves(root->left, leaves);
    collectLeaves(root->right, leaves);
}

// Print leaf nodes
void printLeaves(Node* root) {
    std::vector<int> leaves;
    collectLeaves(root, leaves);
    std::cout << "Leaf nodes: ";
    for (size_t i = 0; i < leaves.size(); ++i) {
        std::cout << leaves[i];
        if (i + 1 < leaves.size()) std::cout << ", ";
    }
    std::cout << std::endl;
}

int main() {
    Node* root = nullptr;
    // Example data – you can change this list
    std::vector<int> data = {50, 30, 70, 20, 40, 60, 80, 35, 45, 55, 65};
    for (int v : data) {
        root = insert(root, v);
    }
    printLeaves(root);
    // Clean up memory (optional for this short program)
    return 0;
}
