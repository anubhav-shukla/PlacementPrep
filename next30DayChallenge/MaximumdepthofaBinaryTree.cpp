#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    struct Node* left, *right;
};
   
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}
   
int height(struct Node* root){
 
      int depth = 0;
   
    queue<Node*>q;
     
      q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
       
        if(temp == NULL){
            depth++;
        }
        if(temp != NULL){
            if(temp->left){
                  q.push(temp->left);
            }
              if(temp->right){
                q.push(temp->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
    return depth;
}
 
int main()
{
    Node *root  = newNode(1);
    root->left  = newNode(12);
    root->right = newNode(13);
   
    root->right->left   = newNode(14);
    root->right->right  = newNode(15);
   
    root->right->left->left   = newNode(21);
    root->right->left->right  = newNode(22);
    root->right->right->left  = newNode(23);
    root->right->right->right = newNode(24);
   
      cout<<"Height(Depth) of tree is: "<<height(root);
}
