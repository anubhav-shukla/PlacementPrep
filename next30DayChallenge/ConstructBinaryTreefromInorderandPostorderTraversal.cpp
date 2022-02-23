#include <bits/stdc++.h>
using namespace std;

struct Node
{
int data;
Node *left, *right;
Node(int x)
{
	data = x;
	left = right = NULL;
}
};

Node *buildTree(int in[], int post[], int n)
{

stack<Node*> st;

set<Node*> s;

int postIndex = n - 1;

Node* root = NULL;

for (int p = n - 1;int  i = n - 1; p>=0){

	Node* node = NULL;
	do
	{
	node = new Node(post[p]);

	if (root == NULL)
	{
		root = node;
	}
	if (st.size() > 0)
	{
		
		if (s.find(st.top()) != s.end())
		{
		s.erase(st.top());
		st.top()->left = node;
		st.pop();
		}
		else
		{
		st.top()->right = node;
		}
	}
	
	st.push(node);
	
	} while (post[p--] != in[i] && p >=0);

	node = NULL;
	
	while (st.size() > 0 && i>=0 &&
		st.top()->data == in[i])
	{
	node = st.top();
	
	st.pop();
	i--;
	}
	
	if (node != NULL)
	{
	s.insert(node);
	st.push(node);
	}
}

// Return root
return root;

}
void preOrder(Node* node)
{
if (node == NULL)
	return;
printf("%d ", node->data);
preOrder(node->left);
preOrder(node->right);
}

int main()
{

int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
int n = sizeof(in) / sizeof(in[0]);

Node* root = buildTree(in, post, n);

cout << "Preorder of the constructed tree : \n";

preOrder(root);
return 0;
}
