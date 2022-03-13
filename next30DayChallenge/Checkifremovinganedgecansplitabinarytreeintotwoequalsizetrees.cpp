#include <iostream>
using namespace std;
 
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
int size(Node* root) {
    return root ? (1 + size(root->left) + size(root->right)): 0;
}
int checkSize(Node* root, int n, bool &result)
{
    if (!root || result) {
        return 0;
    }
 
    int size = 1 + checkSize(root->left, n, result) +
                checkSize(root->right, n, result);
 
    if (!result) {
        result = (2 * size == n);
    }
 
    return size;
}
bool splitTree(Node* root)
{
    int n = size(root);
    if (n & 1) {
        return false;
    }
 
    bool result = false;
    checkSize(root, n, result);
    return result;
}
 
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
 
    if (splitTree(root)) {
        cout << "The binary tree can be split" << endl;
    }
    else {
        cout << "The binary tree cannot be split" << endl;
    }
 
    return 0;
}
