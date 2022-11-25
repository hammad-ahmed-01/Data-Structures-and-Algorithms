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
};

// Creating SinglyLinkedList class to implement our data structure
class singlylinkedlist
{
public:
	node* start = NULL;
	node* last = NULL;
	node* ploc;
	node* loc;
	int length = 0;

	bool isEmpty()
	{
		return length == 0;
	}
	void insertAtFront(int value)
	{
		//Reserve space for a new node to be inserted in the list by creating 
		//object of class node and storing its address in a temporary pointer variable.
		node* nn = new node();
		nn->data = value;
		if (isEmpty())
		{
			start = nn;
			last = nn;
		}
		//link newnode at front of the linked list via following two statements
		// as we are inserting at front so the new node next will point to the start
		nn->next = start;
		start = nn;
		last->next = NULL;
		length++;
	}
	void insertAtEnd(int value)
	{
		node* nn = new node();
		nn->data = value;
		if (isEmpty())
		{
			start = nn;
			last = nn;
		}
		last->next = nn;
		last = nn;
		last->next = NULL;
		length++;
	}
	void printlist()
	{
		node* temp = start;
		cout << endl;
		if (!isEmpty())
		{
			while (temp != NULL)
			{
				cout << temp->data << " -> ";
				temp = temp->next;
			}
			cout << endl;
		}
		else
			cout << "\n LIST IS EMPTY" << endl;
	}

	// Task to print the SLL in reverse order
	void reverse_print(node* head)
	{
		if (head == NULL)
		{
			cout << endl;
		}
		else
		{
			cout << head->data << " -> ";
			reverse_print(head->next);
			cout << head->data << " -> ";
		}
	}
		
	// Task to reverse the SLL
	void reverse_list(node* head, node* ploc)
	{
		if (head == last)
		{
			start = head;
			start->next = ploc;
		}
		else
		{
			reverse_list(head->next, head);
			node* temp = head;
			head->next = ploc;
			last = head;
		}
	}

	// Task to separate the odd and even nodes (with odd and even values)
	void odd_even(node* head, node* ploc)
	{
		if (head == NULL)
		{
			cout << endl;
		}
		else
		{
			if (head->data % 2 != 0)
			{
				if(head == start)
				{
					ploc = head;
					head = head->next;
				}
				else
				{
					node* temp = head;
					head = head->next;
					ploc->next = head;
					head = head;
					temp->next = start;
					start = temp;
				}
				odd_even(head, ploc);
			}
			else
			{
				odd_even(head->next, head);
			}
		}
	}

	// A task to delete the even ordered nodes and reverse the remaining nodes
	void QUIZ(node* curr, node* ploc, int size)
	{
		if (curr == NULL)
		{
			start = ploc;
		}
		else
		{
			if (size % 2 == 0)
			{
				node* temp1 = curr;
				ploc->next = curr->next;
				curr = curr->next;
				delete temp1;
				QUIZ(curr, ploc, size + 1);
			}
			else
			{
				QUIZ(curr->next, curr, size + 1);
			}
			node* temp2 = curr;
			temp2->next = ploc;
			last = curr;
		}
	}
};
