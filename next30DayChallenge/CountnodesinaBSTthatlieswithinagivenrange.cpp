#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int data){
        this->data=data;
        this->left=this->right=nullptr;

    }
};

Node* insert(Node* root, int key){
    if(root == nullptr){
        return new Node(key);
    }
    if(key < root->data){
        root ->left=insert(root->left,key);
    }
    else{
        root ->right=insert(root->right,key);

    }
    return root;
}

int countNode(Node* root, int low, int high){
    if(root == nullptr){
        return 0;
    }
    if(root->data>=low && root->data<=high){
        return 1 + countNode(root->left, low, high)+countNode(root->right,low,high);
    }
    if(root->data>high){
        return countNode(root->left,low,high);
    }
    if(root->data<low){
        return countNode(root->right,low,high);
    }
}

int main(){
    int low = 12, high = 20;
 
    int keys[] = { 15, 25, 20, 22, 30, 18, 10, 8, 9, 12, 6 };
 Node* root = nullptr;
    for (int key: keys) {
        root = insert(root, key);
    }
 
    cout << "The total number of nodes is " << countNode(root, low, high) << endl;
 
    return 0;
}
