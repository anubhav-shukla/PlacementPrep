#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node* left;
	node* right;
	node *nextRight;
	
	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->nextRight = NULL;
	}
};
node *getNextRight(node *p)
{
	node *temp = p->nextRight;

	while (temp != NULL)
	{
		if (temp->left != NULL)
			return temp->left;
		if (temp->right != NULL)
			return temp->right;
		temp = temp->nextRight;
	}
	return NULL;
}
void connectRecur(node* p)
{
	node *temp;

	if (!p)
	return;
	p->nextRight = NULL;
	while (p != NULL)
	{
		node *q = p;
		while (q != NULL)
		{
			if (q->left)
			{
				if (q->right)
					q->left->nextRight = q->right;
				else
					q->left->nextRight = getNextRight(q);
			}

			if (q->right)
				q->right->nextRight = getNextRight(q);

			q = q->nextRight;
		}

		if (p->left)
			p = p->left;
		else if (p->right)
			p = p->right;
		else
			p = getNextRight(p);
	}
}


int main()
{

	node *root = new node(10);
	root->left = new node(8);
	root->right = new node(2);
	root->left->left = new node(3);
	root->right->right	 = new node(90);

	connectRecur(root);

	cout << "Following are populated nextRight pointers in the tree"
		" (-1 is printed if there is no nextRight) \n";
	cout << "nextRight of " << root->data << " is "
		<< (root->nextRight? root->nextRight->data: -1) <<endl;
	cout << "nextRight of " << root->left->data << " is "
		<< (root->left->nextRight? root->left->nextRight->data: -1) << endl;
	cout << "nextRight of " << root->right->data << " is "
		<< (root->right->nextRight? root->right->nextRight->data: -1) << endl;
	cout << "nextRight of " << root->left->left->data<< " is "
		<< (root->left->left->nextRight? root->left->left->nextRight->data: -1) << endl;
	cout << "nextRight of " << root->right->right->data << " is "
		<< (root->right->right->nextRight? root->right->right->nextRight->data: -1) << endl;
	return 0;
}

