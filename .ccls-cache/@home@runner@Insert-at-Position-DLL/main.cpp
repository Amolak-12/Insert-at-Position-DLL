#include <iostream>
using namespace std;


// Making Node for making Linked List
class Node {
public:
  int data;
  Node *prev;
  Node *next;

  Node() {
    this->data = 0;
    this->prev = NULL;
    this->next = NULL;
  }
  Node(int data) {
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
  }
};

//Inserting at head as done in earlier code
void insertAtHead(Node *&head, Node *&tail, int data) {
  if (head == NULL) {
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
  }
  Node *newNode = new Node(data);
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
}

//Inserting at tail as done in earlier code
void insertAtTail(Node *&head, Node *&tail, int data) {
  if (head == NULL) {
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
  }
  Node *newNode = new Node(data);
  newNode->prev = tail;
  tail->next = newNode;
  tail = newNode;
}
// Function for finding the length of a Linked List
int findlen(Node *&head) {
  int length = 0;
  Node *temp = head;
  while (temp != NULL) {
    length++;
    temp = temp->next;
  }
  return length;
}

void insertAtPosition(Node *&head, Node *&tail, int data, int position) {
  if (head == NULL) {
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
  }
  int length = findlen(head);
  if (position > length+1 || position <= 0) {
    cout << "Please enter a valid position to insert. " << endl;
    return;
  }
  if (position == 1) {
    insertAtHead(head, tail, data);
    return;
  }
  if (position > length) {
    insertAtTail(head, tail, data);
    return;
  }

  // //1st method
  // // Step 1 : Find prevN and currN
  // int i = 1;
  // Node *prevN = head;
  // while (i < position-1) {
  //   prevN = prevN->next;
  //   i++;
  // }
  // Node *currN = prevN->next;
  
  // // Step 2 : Create a new node
  // Node *newNode = new Node(data);

  // // Step 3 : Make prevN->next = newNode
  // prevN ->next = newNode;
  
  // // Step 4 : Make newNode->prev = prevN
  // newNode->prev = prevN;
  
  // // Step 5 : Make curr->prev = newNode
  // currN->prev = newNode;
  
  // // Step 6 :  newNode->next = currN
  // newNode->next = currN;

  //2nd method
  
  // Step 1 : Find prevN 
  int i = 1;
  Node *prevN = head;
  while(i < position-1) {
    prevN = prevN->next;
    i++;
  }
  
  //Step 2 : Create a new node
  Node *newNode = new Node(data);
  
  //Step 3 : newNode->next = prevN->next
  newNode->next = prevN->next;
  
  //Step 4 : prevN->next->prev = newNode
  prevN->next ->prev = newNode;
  
  //Step 5 : newNode->prev = prevN
  newNode->prev = prevN;
  
  //Step 6 : preN->next = newNode
  prevN->next = newNode;

}

// Function for printing the whole of Linked List
void print(Node *&head) {
  Node *temp = head;
  cout << "Printing the Linked List : " << endl;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }

  cout << endl;
}
int main() {

  Node *first = new Node(10);
  Node *second = new Node(20);
  Node *third = new Node(30);

  first->next = second;
  second->prev = first;
  second->next = third;
  third->prev = second;

  //Printing the Linked List
  print(first);
  
  //Inserting at any position
  insertAtPosition(first ,third ,300 ,0);
  //Printing the modified Linked List
  print(first);

}