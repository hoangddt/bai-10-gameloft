#pragma once
#include "People.h"

class Node
{
public:
	Node();
	People* data;
	Node* next;
	static void add(Node* &node, People *element);

	// remove last element
	static void remove(Node* &node);
};