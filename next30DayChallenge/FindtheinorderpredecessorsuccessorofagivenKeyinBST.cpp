#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node
{
	int data;
	Node* left,*right;
};
Node* getnode(int info)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = info;
	p->right = NULL;
	p->left = NULL;
	return p;
}
void find_p_s(Node* root,int a,
			Node** p, Node** q)
{
	// If root is null return
	if(!root)
		return ;
		
	find_p_s(root->left, a, p, q);
	
	if(root&&root->data > a)
	{
		if((!*q) || (*q) && (*q)->data > root->data)
				*q = root;
	}
	else if(root && root->data < a)
	{
		*p = root;
	}
	
	find_p_s(root->right, a, p, q);
}

int main()
{
	Node* root1 = getnode(50);
	root1->left = getnode(20);
	root1->right = getnode(60);
	root1->left->left = getnode(10);
	root1->left->right = getnode(30);
	root1->right->left = getnode(55);
	root1->right->right = getnode(70);
	Node* p = NULL, *q = NULL;

	find_p_s(root1, 55, &p, &q);
	
	if(p)
		cout << p->data;
	if(q)
		cout << " " << q->data;
	return 0;
}
