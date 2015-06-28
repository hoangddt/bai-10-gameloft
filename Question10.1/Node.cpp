#include "Node.h"
#include <cstdio>
Node::Node()
{
	// this = NULL;
}

void Node::add(Node* &node, People *element)
{
	// check if empty, insert at first
	if (node == NULL)
	{
		Node *temp = new Node();
		temp->data = element;
		temp->next = NULL;
		node = temp;
	}
	else
	{
		// insert at k
		Node *pivot = node;
		while (pivot->next != NULL)
			pivot = pivot->next;

		Node *temp = new Node();
		temp->data = element;
		temp->next = NULL;

		pivot->next = temp;

	}
	
}