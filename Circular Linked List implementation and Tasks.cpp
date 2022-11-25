/*
Author == Hammad Ahmed
Microsoft VS
*/

#include <iostream>
using namespace std;

// Creating node class to represent a specific node for our list
class node
{
public:
	int data;
	node* next;
};

// Creating CLL( CircularLinkedList ) class to implement our data structure

class CLL
{
public:

	CLL()
	{
		last = NULL;
	}

	node* loc;
	node* ploc;
	node* last;

	bool isEmpty()
	{
		return last == NULL;
	}

	void InsertAtFront(int value)
	{
		node* nn = new node();
		if (isEmpty()) {
			nn->data = value;
			nn->next = nn;
			last = nn;
		}
		else {
			nn->data = value;
			nn->next = last->next; //this line connects the new node to the already existing node
			last->next = nn; //this command connects the last node of the list to the first new node, making a circular list
		}
	}

	void InsertAtEnd(int value)
	{
		node* nn = new node();
		if (isEmpty()) {
			nn->data = value;
			nn->next = nn;
		}
		else {
			nn->data = value;
			nn->next = last->next;
			last->next = nn;
			last = nn; //the function works the same as in InsertAtFront except that we make the newly inserted node to be pointed by the last pointer. We suppose that the node to which the ' last ' pointer points is the last node.
		}
	}

	// Task to reverse the CLL
	void reverse(node* curr, node* ploc)
	{
		if (curr == last)
		{
			last = curr->next;
			last->next = ploc;
		}
		else
		{
			reverse(curr->next, ploc->next);
			curr->next = ploc;
		}
	}

	void print()
	{
		if (!isEmpty())
		{
			cout << last->data << endl;
			cout << " -> ";
			node* temp = last->next;
			do
			{
				cout << temp->data << " -> ";
				temp = temp->next;
			} while (temp != last->next);
			cout << endl;
		}
		else
		{
			cout << "Cannot print list as the list is empty!" << endl;
		}
	}

	// Task to separate the odd and even nodes (with odd and even values)
	void odd_even(node*curr, node*ploc)
	{
		if (curr == last)
		{
			if (curr->data % 2 != 0)
			{
				last = ploc;
			}
		}
		else
		{
			if (curr->data % 2 != 0)
			{
				if (curr == last->next)
				{
					odd_even(curr->next, ploc->next);
				}
				else
				{
					node* temp = curr;
					ploc->next = curr->next;
					curr = curr->next;
					temp->next = last->next;
					last->next = temp;
					odd_even(curr, ploc);
				}
			}
			else
			{
				odd_even(curr->next, ploc->next);
			}
		}
	}

};