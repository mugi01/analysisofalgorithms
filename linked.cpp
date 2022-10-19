#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

// We start by making the structure of the Node. By initializing data items and pointers pointing to the next node
struct Node {
  int data;
  Node * next;
};

class LinkedList {
  // Head Node pointer
  Node * head;
  // Tail Node pointer
  Node * tail;
  public:
  LinkedList();
  ~LinkedList();
  LinkedList(int size);
  LinkedList(const LinkedList & l1);
  void updateTail();
  void insertAtBeginning(int val);
  void insertAtEnd(int val);
  void operator = (const LinkedList & l);
  Node * getHead();
  Node * getTail();
  bool search(int val);
  void remove(int val);
  void removeDuplicate();
  void selectionSort();
  void reverse();  
  void display();
  };
  // default constructor. Initializing head pointer
   LinkedList:: LinkedList() {
      head = NULL;
      tail = NULL;
    }
 void LinkedList::updateTail() {
    // if head is null set the tail to null also
    if (head == NULL) {
      tail = NULL;
      return;
    }
    Node * temp = head;

    //  Else traverse till the last node
    while (temp -> next != NULL) {
      temp = temp -> next;
    }

    //  Assign the last node to tail
    tail = temp;
    return;
  }

  LinkedList::LinkedList(int size) {
    // Seed stand with random numbers
    srand(time(0));
    for (int i = 0; i < size; i++)
      // Add random numbers into our linked list
      insertAtBeginning(rand() % 20);
  }
  // Copy constructor
  LinkedList::LinkedList(const LinkedList & l1) {
    head = l1.head;
    tail = l1.tail;
  }
  // Destructor
 LinkedList:: ~LinkedList() {
    Node * current = head;
    while (current != 0) {
      Node * next = current -> next;
      delete current;
      current = next;
    }
    head = NULL;
  }
  //Operator overloading
 void LinkedList:: operator = (const LinkedList & l) {
    head = l.head;
    tail = l.tail;
  }
  // Return the head of the linked list
 Node * LinkedList:: getHead() {
    return head;
  }
  // Return tail of the linked list
  Node *LinkedList::getTail() {
    if (tail == NULL)
       return NULL;
    return tail;
  }
  // inserting elements (At start of the list)
  void LinkedList:: insertAtBeginning(int val) {
    // make a new node
    Node * new_node = new Node;
    new_node -> data = val;
    new_node -> next = NULL;

    // If list is empty, make the new node, the head
    if (head == NULL) {
    head = new_node;	
	}

    // else, make the new node the head and its next, the previous
    // head
    else {
      new_node -> next = head;
      head = new_node;
    }
    this -> updateTail();
  }

  // inserting elements (At the end of the list)
 void LinkedList::insertAtEnd(int val) {
    // make a new node
    Node * new_node = new Node;
    new_node -> data = val;
    new_node -> next = NULL;

    // If list is empty, make the new node, the head
    if (head == NULL) head = new_node;

    // else, make the new node the head and its next, the previous
    // head
    else {
      tail -> next = new_node;
      tail = new_node;
    }
    //      this->printTail();
  }
  // loop over the list. return true if element found
 bool LinkedList::search(int val) {
    Node * temp = head;
    while (temp != NULL) {
      if (temp -> data == val) return true;
      temp = temp -> next;
    }
    return false;
  }

 void LinkedList::remove (int val) {
    // If the head is to be deleted
    if (head -> data == val) {
      delete head;
      head = head -> next;
      return;
    }

    // If there is only one element in the list
    if (head -> next == NULL) {
      // If the head is to be deleted. Assign null to the head
      if (head -> data == val) {
        delete head;
        head = NULL;
        return;
      }
      // else print, value not found
      cout << "Value not found!" << endl;
      return;
    }

    // Else loop over the list and search for the node to delete
    Node * temp = head;
    while (temp -> next != NULL) {
      // When node is found, delete the node and modify the pointers
      if (temp -> next -> data == val) {
        Node * temp_ptr = temp -> next -> next;
        delete temp -> next;
        temp -> next = temp_ptr;
        return;
      }
      temp = temp -> next;
    }
    // Else, the value was not in the list
    cout << "Value not found" << endl;
  }

 void LinkedList::display() {
    Node * temp = head;
    while (temp != NULL) {
      cout << temp -> data << " ";
      temp = temp -> next;
    }
    cout << endl;
  }

  /* Function to reverse the nodes in a linked list. */
 void  LinkedList::reverse() {
    if (head == NULL) return;

    Node * prev = NULL, * current = NULL, * next = NULL;
    current = head;
    while (current != NULL) {
      next = current -> next;
      current -> next = prev;
      prev = current;
      current = next;
    }
    // now let the head point at the last node (prev)
    head = prev;
  }
  // Function
 void LinkedList::removeDuplicate() {
    this -> selectionSort();
    // temp pointing to head
    Node * temp = head;
    while (temp -> next != NULL && temp != NULL) {
      // Duplicate Found
      if (temp -> data == temp -> next -> data) {
        // DUplicate Removed
        temp -> next = temp -> next -> next;
      } else {
        // No Duplicate Present
        temp = temp -> next;
      }
    }
  }

 void  LinkedList::selectionSort() {
    Node * temp = head;

    // Traverse the List
    while (temp) {
      Node * min = temp;
      Node * r = temp -> next;

      // Traverse the unsorted sublist
      while (r) {
        if (min -> data > r -> data) min = r;
        r = r -> next;
      }

      // Swap Data
      int x = temp -> data;
      temp -> data = min -> data;
      min -> data = x;
      temp = temp -> next;
    }
  }


int main() {
  LinkedList l(4);
  LinkedList l2 = l;
  cout << "Displaying randomly generated list:";

  l2.display();
  cout<<endl;
  // inserting elements
  l.insertAtBeginning(12);
  l.insertAtBeginning(29);
  l.insertAtBeginning(1);
  l.insertAtEnd(32);
  l.insertAtBeginning(45);
  l.insertAtBeginning(0);
  l.insertAtEnd(32);
  cout<<endl;
  cout << "Current Linked List After Inserting At the beginning: ";
  l.display();

cout<<endl;
  cout << "Deleting 1: ";
  l.remove(1);
  l.display();
  cout << "Reversed linked list: ";
  l.reverse();
  l.display();
  cout << "Deleting 29: ";
  l.remove(13);

  cout << "Searching for 7: ";
  cout << l.search(7) << endl;
  //  l.selectionSort();
  //  l.removeDuplicate();
  cout << "Displaying the linked List:";
  l.display();
  l2 = l;
  cout << "Displaying the randomly generated Linked List:";
  l2.display();

  cout << "Searching for 13: ";     //The time complexity T(n)= O(n)
  cout << l.search(13) << endl;

}
