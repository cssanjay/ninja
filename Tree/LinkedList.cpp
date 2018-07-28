#include <iostream>
#include "Node.cpp"

using namespace std;

Node* takeInpu_Better() {
	int data;
	cin >> data;
	Node *head = NULL;
	Node *tail = NULL;
	while(data != -1) {
		Node *newNode = new Node(data);
		if(head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail -> next = newNode;
			tail = tail -> next;
			// OR
			// tail = newNode;
		}

		cin >> data;
	}
	return head;
}

void print(Node *head) {
	while(head != NULL) {
		cout << head -> data << " ";
		head = head -> next;
	}
}

/*
	Node *temp = head;
	  Node *prev = head;
	  if(i == 0){
	    head = head -> next;
	    return head;
	  }
	  temp = temp->next;
	  
	  int count = 1;
	  while(temp && count <= i){
	    prev = temp;
	    temp = temp->next;
	    count++;
	  }
	  prev->next = temp->next;
	  return head;
*/
Node* deleteNode(Node *head, int i) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
	if(i == 0){
		head = head->next;
		return head;
	}
	Node *temp = head;
	Node *prev = temp;

	int count = 1;
	temp = temp -> next;
	while(temp && count < i){
		cout << temp->data << "---";
		prev = temp;
		temp = temp -> next;
		count++;
	}
	prev->next = temp->next;
	return head;

}


Node* insertNodeRec(Node *head, int i, int data) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */

  if(head == NULL && i >= 1) return NULL;
  if(head == NULL){
  	cout <<"i am here "<< i <<"++"<<endl;
    Node* newNode = new Node(data);
    head = newNode;
    return head;
  }
  
  if(i == 1){
    Node *newNode = new Node(data);
	Node* temp = head->next;
    head->next = newNode;
    newNode->next = temp;
    return head;
  }

  if(i == 0){
  	Node* newNode = new Node(data);
  	newNode->next = head;
  	head = newNode;
  	return head;
  }
  
  
  if(i > 0){
    head->next = insertNodeRec(head->next, i-1, data);
    cout << "iiiiiiiii"<<i <<endl;
  }
  cout << "----"<<i << endl;
  return head;
  
}

// Node* arrangeOddEven(Node* head){
// 	Node* oddStart 	= NULL;
// 	Node* evenStart = NULL;
// 	Node* evenEnd = NULL;
// 	Node* oddEnd 	= NULL;
// 	Node* startEnd 	= NULL;
// 	Node* current 	= head;

// 	while(current){
// 		if(current->data % 2){
// 			if(oddStart == NULL){
// 				oddStart = current;
// 				oddEnd	 = current;
// 			}
// 			else{
// 				oddEnd->next = current;
// 				oddEnd = oddEnd->next;
// 			}
// 		}
// 		else{
// 			if(evenStart == NULL){
// 				evenStart = current;
// 				evenEnd	  = evenStart;
// 			}
// 			else{
// 				evenEnd->next = current;
// 				evenEnd = evenEnd->next;
// 			}
// 		}
// 		current = current->next;
// 	}

// 	if(oddStart == NULL || evenStart == NULL){
// 		return;
// 	}
// 	oddEnd->next = evenStart;
// 	evenEnd->next = NULL;

// 	*head = oddStart;
// }

int main() {
	int index ,data;
	Node *head = takeInpu_Better();
	print(head);
	// cout << "enter the index to be deleted :: ";
	// cin >> index;
	// head = deleteNode(head, index);
	// cout << "enter the node to be added :: ";
	// cin >> data;
	// head = insertNodeRec(head, index, data);
	// head = arrangeOddEven(head);
	print(head);
	
	/*
	// Statically
	Node n1(1);
	Node *head = &n1;

	Node n2(2);

	Node n3(3);
	Node n4(4);
	Node n5(5);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	print(head);

ee	print(head);
	*/
	/*
	// Dynamically
	Node *n3 = new Node(10);
	Node *head = n3;
	
	Node *n4 = new Node(20);
	n3 -> next = n4;

	*/

}

