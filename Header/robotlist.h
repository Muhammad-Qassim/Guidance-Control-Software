#ifndef robotlist_h
#define robotlist_h

#include "robot.h"
#include <cstring>
#include <string>

class robotlist {
private:
  class Node {
  public:
    robot *val;
    Node *next;
  };
  Node *head;
  int size;

public:
  robotlist();

        //ins
        //Parameters:
        // name of one robot
        //Returns: none
        //Side Effect: creates new node in list
  void ins(std::string newName);
        //Add
        //Parameters:none
        //Returns: none
        //Side Effect: creates new node in list
  void add();
        //pop
        //Parameters: name of robot
        //Returns: none
        //Side Effect: delete robotr
  void pop(std::string n);
        //Print
        //Parameters:none
        //Returns: none
        //Side Effect: print robot info to console
  void printlist();
        //Print
        //Parameters:none
        //Returns: none
        //Side Effect: puts list in sorted order
  void sort();
        // Name: Find Robot
        // Parameters:
        //  identifier: name of Robot to search for
        // Returns: either ptr of a Robot in robolist, or null
        // Side Efects: none
  robot *findrobot(std::string identifier);
        //Destructor
        //Parameters: none
        //Side Effects: deletes all list nodes
  ~robotlist();
};
#endif