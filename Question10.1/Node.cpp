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

// remove last element
void Node::remove(Node* &node)
{
	if (node == NULL)
	{
		return;
	}

	Node *pivot = node;
	Node *last = NULL;
	// go to last element
	while (pivot != NULL)
	{
		last = pivot;
		// move forward
		pivot = pivot->next;
	}

	// free last element
	delete last->data;
	pivot = node;
	Node *end = NULL;
	while (pivot != last)
	{
		end = pivot;
		pivot = pivot->next;
	}
	end->next = NULL;
}