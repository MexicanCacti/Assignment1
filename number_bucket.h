#pragma once
#ifndef Number_bucket_h
#define Number_bucket_h

struct Node {
  Node* next = NULL;
  int data = NULL;
};


class Number_bucket {
private:
  Node* head;
  int size;

public:
  Number_bucket();  // construct
  ~Number_bucket(); // destruct
  bool isEmpty();   // checks to see if list empty, returns true if is
  void push(int n); // creates a new node in list with value of n
  void pop();       // makes node before last node point to NULL
  int get_size() { return size; }
  void print(std::ostream& out);     // prints the entirety of the linked list
};

Number_bucket::Number_bucket() {
  this->head = NULL;
  this->size = 0;
}

Number_bucket::~Number_bucket() {
  Node* list = this->head;
  while (list != NULL) { // go through each member of the linked list and delete
    Node* next = list->next;
    delete list;
    list = next;
  }
  delete list;
}

bool Number_bucket::isEmpty() {
  if (this->size > 0) {
    return false;
  }
  return true;
}

void Number_bucket::push(int n) {
  Node* value = new Node();  // new node to push into list
  value->data = n;
  this->size += 1;           // regardless always increasing size by 1

  if (this->head == NULL) { // list was empty so becomes first in list
    this->head = value;
    return;
  }

  Node* tail = this->head;  

  while (tail->next != NULL) {  // finds the end of the linked list and makes the next value pointing to the new Node
    tail = tail->next;
  }
  tail->next = value;
  return;
}

void Number_bucket::pop() { //LIFO so delete tail node
  if (this->size == 0) { //check to see if empty list
    return;
  }

  this->size -= 1;
  Node* tail = this->head;
  Node* Beforetail = tail; // to pop from list, we want to look at the node BEFORE the last node and make the node BEFORE the last node point to NULL
  while (tail->next != NULL) {
    Beforetail = tail;
    tail = tail->next;
  }
  Beforetail->next = NULL;
  delete tail;
  
  if (this->size == 0) { // made list empty so make head NULL
    head = NULL;
  }
  return;
}

void Number_bucket::print(std::ostream& out) {
  Node* list = this->head;
  out << "List: ";
  while (list != NULL) {
    out << "[" << list->data << "] ";
    list = list->next;
  }
  out << "\n";
}
#endif