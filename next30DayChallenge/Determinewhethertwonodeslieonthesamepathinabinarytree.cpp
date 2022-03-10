#include <iostream>
#include <unordered_map>
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
void printTree(Node* root,
            unordered_map<Node*, int> &arrival,
            unordered_map<Node*, int> &departure)
{
    if (root == nullptr) {
        return;
    }
 
    cout << "Node " << root->data << " (" << arrival[root] << ", "
         << departure[root] << ")" << endl;
 
    printTree(root->left, arrival, departure);
 
    printTree(root->right, arrival, departure);
}
void performDFS(Node* root,
                unordered_map<Node*, int> &arrival,
                unordered_map<Node*, int> &departure,
                int &time)
{
    if (root == nullptr) {
        return;
    }
    arrival[root] = ++time;
 
    performDFS(root->left, arrival, departure, time);
 
    performDFS(root->right, arrival, departure, time);
 
    departure[root] = ++time;
}
 
bool isAncestorOrDescendant(Node* x, Node* y,
                            unordered_map<Node*, int> &arrival,
                            unordered_map<Node*, int> &departure)
{
    if (!arrival[x] || !arrival[y]) {
        cout << "Node " << x->data << " or Node " << y->data <<
                " is not the actual node in the tree";
        return false;
    }
 
    bool isAncestor = arrival[x] < arrival[y] && departure[x] > departure[y];
    bool isDescendant = arrival[y] < arrival[x] && departure[y] > departure[x];
 
    if (isAncestor)
    {
        cout << "Node " << x->data << " is an ancestor of Node "
             << y->data << endl;
    }
    else if (isDescendant)
    {
        cout << "Node " << x->data << " is a direct descendant of Node "
             << y->data << endl;
    }
    else {
        cout << "Node " << x->data << " is a neither an ancestor nor a "
            "descendant of Node " << y->data << endl;
    }
 
    return isAncestor || isDescendant;
}
 
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->right = new Node(10);
    root->right->right->left = new Node(11);
    root->left->left->right->left = new Node(12);
    root->left->left->right->right = new Node(13);
    root->right->right->left->left = new Node(14);
 
    unordered_map<Node*, int> arrival;
 
    unordered_map<Node*, int> departure;
 
    int time = 0;
    performDFS(root, arrival, departure, time);
 
 
    isAncestorOrDescendant(root->right, root->right->right->left->left,
                                arrival, departure);
 
    isAncestorOrDescendant(root->left->left->right->left, root->left,
                                arrival, departure);
 
    isAncestorOrDescendant(root->left->left, root->left->right,
                                arrival, departure);
 
    isAncestorOrDescendant(new Node(root->left->left->data), root->left->right,
                                arrival, departure);
 
    return 0;
}
