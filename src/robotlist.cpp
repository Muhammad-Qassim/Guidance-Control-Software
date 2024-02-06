#include "robotlist.h"
#include "robot.h"
#include <cstring>
#include <iostream>
#include <string>

using namespace std;
        //Constructor
        //Parameters: none
        //Side Effects: sets default values of one robot

robotlist::robotlist() {
  head = nullptr;
  size = 0;
}
        //ins
        //Parameters:
        // name of one robot
        //Returns: none
        //Side Effect: creates new node in list
void robotlist::ins(std::string newName) {
  Node *newNode = new Node;
  newNode->val = new robot(newName);
  newNode->next = head;
  head = newNode;
  size++;
}
        //Add
        //Parameters:none
        //Returns: none
        //Side Effect: creates new node in list
void robotlist::add() {
  string name;
  cout << "Enter name of robot ";
  cin >> name;
  ins(name);
}
        //pop
        //Parameters: name of robot
        //Returns: none
        //Side Effect: delete robotr

void robotlist::pop(std::string n) {
  if (head->val->get_name() == n) {
    head = head->next;
    return;
  }
  Node *temp = head;
  if (temp != nullptr) {
    temp = temp->next;
  }
  temp->next = temp->next->next;
}
        //sort
        //Parameters:none
        //Returns: none
        //Side Effect: puts list in sorted order
void robotlist::sort() {
  Node *pos, *comp, *big;
  pos = head;
  while (pos != nullptr) {
    big = pos;
    comp = pos->next;
    while (comp != nullptr) {
      if (comp->val->get_distance() > big->val->get_distance()) {
        big = comp;
      }
      comp = comp->next;
    }
    if (big != pos) {
      robot *temp;
      temp = big->val;
      big->val = pos->val;
      pos->val = temp;
    }
    pos = pos->next;
  }
}
        //Print
        //Parameters:none
        //Returns: none
        //Side Effect: print robot info to console

void robotlist::printlist() {
  Node *temp = head;
  while (temp != NULL) {
    cout << temp->val->get_name() << " : ";
    cout << temp->val->get_distance() << "\n";
    temp = temp->next;
  }
}
        //Destructor
        //Parameters: none
        //Side Effects: deletes all list nodes
robotlist::~robotlist() {
  Node *temp = head;
  while (head != nullptr) {
    head = head->next;
    delete temp;
    temp = head;
    size--;
  }
  return;
}
        // Name: Find Robot
        // Parameters:
        //  identifier: name of Robot to search for
        // Returns: either ptr of a Robot in robolist, or null
        // Side Efects: none

robot *robotlist::findrobot(std::string identifier) {
  Node *temp = head;
  while (temp != NULL) {
    if (temp->val->get_name() == identifier) {
      return temp->val;
    }
    temp = temp->next;
  }
  return NULL;
}