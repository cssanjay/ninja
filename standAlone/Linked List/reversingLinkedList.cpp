// reversingLinkedList.cpp


#include <iostream.h>
using namespace std;

/*
/*	Time		: O(n),
/*	Space		: O(1)
*/
void reverse(Node** head){
	Node* current 	= head;
	Node* previous	= NULL;
	Node* next 		= NULL;

	while(current != NULL){
		//store next
		next = current->next;
		//Reverse pointer of current
		current->next = previous;
		//move pointer one position
		prev    = current;
		current = next;
	}
	head = prev;
}

/*
/*	`Recursive method`
/*	Time		: O(n),
/*	Space		: O(1)
*/
void recursiveReverse(Node** head){
	Node* first;
	Node* rest;

	//empty list
	if(*head_ref == NULL)
		return;

	first 	= *head_ref;
	rest 	= first->next;

	if(rest == NULL)
		return;

	recursiveReverse(&rest);
	first->next->next = first;

	first-> next = NULL;

	*head_ref = rest;
}

void reverse(Node** head){
	if(!head)
		return;
	// prev as NULL
	__reverse(*head, null, head);
}

void __reverse(Node* current, Node* previous, Node ** head){
	if(!current->next){
		*head = current;
		current->next = previous;
		return;
	}

	Node* next = current->next;

	current->next = prev;
	__reverse(next, curr, head);
}