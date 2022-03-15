#include <iostream>
#include <queue>
using namespace std;
 
struct TreeNode
{
    int data;
    TreeNode *left, *right;
 
    TreeNode(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// A Linked List Node
struct ListNode
{
    int data;
    ListNode* next;
 
    ListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
 
ListNode* push(ListNode* head, int data)
{
    ListNode* node = new ListNode(data);
    node->next = head;
    head = node;
    return head;
}
 
void preorder(TreeNode* root)
{
    if (root == nullptr) {
        return;
    }
 
    cout << root->data << ' ';
    preorder(root->left);
    preorder(root->right);
}
TreeNode* convertListToBinaryTree(ListNode* head)
{
    // base case
    if (head == nullptr) {
        return nullptr;
    }
 
    TreeNode* root = new TreeNode(head->data);
 
    head = head->next;
 
    queue<TreeNode*> q;
    q.push(root);
    while (head)
    {
        TreeNode* front = q.front();
        q.pop();
 
        front->left = new TreeNode(head->data);
        q.push(front->left);
 
        head = head->next;
 
        if (head != nullptr)
        {
            front->right = new TreeNode(head->data);
            q.push(front->right);
            head = head->next;
        }
    }
 
    return root;
}
 
int main()
{
    ListNode* head = nullptr;
    int n = 6;
 
    for (int i = n; i > 0; i--) {
        head = push(head, i);
    }
 
    TreeNode* root = convertListToBinaryTree(head);
    preorder(root);
 
    return 0;
}
