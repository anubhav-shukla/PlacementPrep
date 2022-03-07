#include <iostream>
#include <climits>
using namespace std;
 
// Data structure to store a binary tree node
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
 
int hasChildrenSumProperty(Node* root)
{
    if (root == nullptr) {
        return 0;
    }
 
    if (root->left == nullptr && root->right == nullptr) {
        return root->data;
    }
 
    int left = hasChildrenSumProperty(root->left);
    int right = hasChildrenSumProperty(root->right);
 
    if (left != INT_MIN && right != INT_MIN && root->data == left + right) {
        return root->data;
    }
 
    return INT_MIN;
}
 
int main()
{
 
    Node* root = new Node(25);
    root->left = new Node(12);
    root->right = new Node(13);
    root->left->left = new Node(7);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
 
    if (hasChildrenSumProperty(root) != INT_MIN) {
        cout << "Binary tree holds children-sum property";
    }
    else {
        cout << "Binary tree does not hold children-sum property";
    }
 
    return 0;
}
