/*
Author == Hammad Ahmed
Microsoft VS
*/

#include<iostream>
using namespace std;

// Creating node class to represent a specific node for our list
class node
{
public:
	int data;
	node* next;
	node* prev;
};

// Creating DoublyLinkedList class to implement our data structure
class DoublyLinkedList
{
public:
	node* start = NULL; // special variable which stores address of head node.
	node* last = NULL; // special variable which stores address of the last node.

	node* ploc; //to be used by Search(value) method to store address of logical predecessor of value in a list.
	node* loc; //to be used by Search(value) method to store address of the node containing the searched value in a list. If it is not found it contains NULL

	bool isEmpty()
	{
		if (start == NULL)
		{
			return true;
		}
		return false;
	}

	void insertAtFront(int val)
	{
		node* nn = new node();
		nn->data = val;
		if (isEmpty())
		{
			start = nn;
			last = nn;
		}
		nn->next = start;
		start->prev = nn;
		start = nn;
		start->prev = NULL;
		last->next = NULL;
	}

	void insertAtEnd(int val)
	{
		node* nn = new node();
		nn->data = val;
		if (isEmpty())
		{
			start = nn;
			last = nn;
		}
		last->next = nn;
		nn->prev = last;
		last = nn;
		start->prev = NULL;
		last->next = NULL;
	}

	void printforward()
	{
		if (!isEmpty())
		{
			node* temp = start;
			while (temp != NULL)
			{
				cout << temp->data << " -> ";
				temp = temp->next;
			}
			cout << endl;
		}
		else
			cout << "\n LIST IS EMPTY !!" << endl;
	}

	void printbackward()
	{
		if (!isEmpty())
		{
			node* temp = last;
			while (temp != nullptr)
			{
				cout << temp->data << " -> ";
				temp = temp->prev;
			}
			cout << endl;
		}
		else
			cout << "\n LIST IS EMPTY !!" << endl;
	}
	void search(int val)
	{
		loc = start;
		ploc = loc->prev;
		while (loc != NULL and loc->data < val)
		{
			ploc = loc;
			loc = loc->next;
		}
		if (loc != NULL and loc->data != val)
		{
			loc = NULL;
		}
	}

	// Task to insert an element in a DLL in a sorted order
	void insertSorted(int val)
	{
		search(val);
		node* nn = new node();
		if (loc != NULL)
		{
			cout << "\n VALUE ALREADY EXISTS" << endl;
		}
		else
		{
			if (ploc == NULL)
			{
				insertAtFront(val);
			}
			else if (ploc == last)
			{
				insertAtEnd(val);
			}
			else
			{
				nn->next = ploc->next;
				nn->prev = ploc;
				ploc->next->prev = nn;
				ploc->next = nn;
			}
		}
	}

	// Task to delete an element in DLL
	void deleteElememnt(int val)
	{
		search(val);
		if (loc != NULL)
		{
			if (ploc == NULL)
			{
				start = loc->next;
				delete loc;
			}
			else if (loc == last)
			{
				last = loc->prev;
				last->next = NULL;
				delete loc;
			}
			else
			{
				ploc->next = loc->next;
				loc->next->prev = ploc;
				delete loc;
			}
		}
		else
			cout << "\n VALUE NOT FOUND" << endl;
	}

	// Task to delete the DLL
	void deleteList()
	{
		while (start != NULL)
		{
			node* temp = start;
			start = start->next;
			delete temp;
		}
	}

	// Task to reverse the DLL
	void reverse(node* loc, node* ploc, node* sloc)
	{
		if (sloc == NULL)
		{
			start = loc;
			start->next = ploc;
			start->prev = NULL;
		}
		else
		{
			reverse(loc->next, loc, sloc->next);
			loc->next = ploc;
			loc->prev = sloc;
			last = loc;
		}
	}


	void odd_even(node* loc, node* ploc, node* sloc)
	{
		if (sloc == NULL)
		{
			if (loc->data % 2 != 0)
			{
				node* temp = loc;
				last = ploc;
				last->next = NULL;
				temp->next = start;
				temp->prev = NULL;
				start->prev = temp;
				start = temp;
			}
		}
		else
		{
			if (loc->data % 2 != 0)
			{
				if (loc == start)
				{
					odd_even(loc->next, loc, sloc->next);
				}
				else
				{
					node* temp = loc;
					ploc->next = loc->next;
					sloc->prev = loc->prev;
					sloc = sloc->next;
					loc = loc->next;
					temp->next = start;
					temp->prev = NULL;
					start->prev = temp;
					start = temp;
					odd_even(loc, ploc, sloc);
				}
			}
			else
			{
				odd_even(loc->next, loc, sloc->next);
			}
		}
	}
	
};