#include <iostream>
using namespace std;
 
struct Node
{
    int data;
    Node* left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
Node* push(Node* root, Node* head)
{
    root->right = head;
 
    if (head != nullptr) {
        head->left = root;
    }
 
    head = root;
    return head;
}
 
int size(Node* node)
{
    int counter = 0;
 
    while (node)
    {
        counter++;
        node = node->right;
    }
 
    return counter;
}
 
void preorder(Node* root)
{
    if (root == nullptr) {
        return;
    }
 
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
Node* convertSortedDLLToBalancedBST(Node* &headRef, int n)
{
    if (n <= 0) {
        return nullptr;
    }
 
    Node* leftSubTree = convertSortedDLLToBalancedBST(headRef, n/2);
 
    Node* root = headRef;
 
    root->left = leftSubTree;
 
    headRef = headRef->right;
 
    root->right = convertSortedDLLToBalancedBST(headRef, n - (n/2 + 1));
                                            /* +1 for the root node */
 
    return root;
}
 
Node* convertBSTtoSortedDLL(Node* root, Node* head)
{
    if (root == nullptr) {
        return head;
    }
 
    head = convertBSTtoSortedDLL(root->right, head);
 
    head = push(root, head);
 
    head = convertBSTtoSortedDLL(root->left, head);
 
    return head;
}
 
Node* sortedMerge(Node* first, Node* second)
{
    if (first == nullptr) {
        return second;
    }
 
    if (second == nullptr) {
        return first;
    }
 
    if (first->data < second->data)
    {
        first->right = sortedMerge(first->right, second);
        first->right->left = first;
 
        return first;
    }
 
    else {
        second->right = sortedMerge(first, second->right);
        second->right->left = second;
 
        return second;
    }
}
 
Node* merge(Node* first, Node* second)
{
    Node* head = sortedMerge(convertBSTtoSortedDLL(first, nullptr),
                                convertBSTtoSortedDLL(second, nullptr));
 
    return convertSortedDLLToBalancedBST(head, size(head));
}
 
int main()
{
 
    Node* first = new Node(20);
    first->left = new Node(10);
    first->right = new Node(30);
    first->right->left = new Node(25);
    first->right->right = new Node(100);
    Node* second = new Node(50);
    second->left = new Node(5);
    second->right = new Node(70);
 
    Node* root = merge(first, second);
 
    preorder(root);
 
    return 0;
}