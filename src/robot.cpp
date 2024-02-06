#include "robot.h"
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

robot::robot() {
  x = 0;
  y = 0;
  distance = 0;
}

robot::robot(std::string n) { name = n; }

int robot::get_x() { return x; }
int robot::get_y() { return y; }
int robot::get_distance() { return distance; }

void robot::set_name(std::string n) { name = n; }
std::string robot::get_name() { return name; }

char robot::get_lastcommand() { return lastcommand; }
    // Name: Move Robot
    // Parameters:
    //  d: the direction to move a robot
    // Return: none
    // Side Efects: the members of robot class will be updated
void robot::moverobot(char d) {
  // I have used toupper() to make character uppercase

  switch (toupper(d)) {
  case 'U':

    if (lastcommand == 's') {
      cout << name << " cannot move while stopped" << endl;
      break;
    }

    if ((lastcommand == 'u') && (currentSpeed == 1)) {
      y += 2;
      lastcommand = 'u';
      currentSpeed = 2;
      distance += 2;
    } else if ((lastcommand == 'u') && (currentSpeed == 2)) {
      y += 3;
      lastcommand = 'u';
      currentSpeed = 3;
      distance += 3;
    } else if ((lastcommand == 'u') && (currentSpeed == 3)) {
      y += 4;
      lastcommand = 'u';
      currentSpeed = 4;
      distance += 4;
    } else if ((lastcommand == 'u') && (currentSpeed >= 4)) {
      y += 4;
      lastcommand = 'u';
      distance += 4;
    } else {
      y += 1;
      lastcommand = 'u';
      currentSpeed = 1;
      distance += 1;
    }
    break;

  case 'D':
    if (lastcommand == 's') {
      cout << name << " cannot move while stopped" << endl;
      break;
    }
    if ((lastcommand == 'd') && (currentSpeed == 1)) {
      y -= 2;
      lastcommand = 'd';
      currentSpeed = 2;
      distance += 2;
    } else if ((lastcommand == 'd') && (currentSpeed == 2)) {
      y -= 3;
      lastcommand = 'd';
      currentSpeed = 3;
      distance += 3;
    } else if ((lastcommand == 'd') && (currentSpeed == 3)) {
      y -= 4;
      lastcommand = 'd';
      currentSpeed = 4;
      distance += 4;
    } else if ((lastcommand == 'd') && (currentSpeed >= 4)) {
      y -= 4;
      lastcommand = 'd';
      distance += 4;
    } else {
      y -= 1;
      lastcommand = 'd';
      currentSpeed = 1;
      distance += 1;
    }
    break;
  case 'R':
    if (lastcommand == 's') {
      cout << name << " cannot move while stopped" << endl;
      break;
    }

    if ((lastcommand == 'r') && (currentSpeed == 1)) {
      x += 2;
      lastcommand = 'r';
      currentSpeed = 2;
      distance += 2;
    } else if ((lastcommand == 'r') && (currentSpeed == 2)) {
      x += 3;
      lastcommand = 'r';
      currentSpeed = 3;
      distance += 3;
    } else if ((lastcommand == 'r') && (currentSpeed == 3)) {
      x += 4;
      lastcommand = 'r';
      currentSpeed = 4;
      distance += 4;
    } else if ((lastcommand == 'r') && (currentSpeed >= 4)) {
      x += 4;
      lastcommand = 'r';
      distance += 4;
    } else {
      x += 1;
      lastcommand = 'r';
      currentSpeed = 1;
      distance += 1;
    }
    break;

  case 'L':
    if (lastcommand == 's') {
      cout << name << " cannot move while stopped" << endl;
      break;
    }
    if ((lastcommand == 'l') && (currentSpeed == 1)) {
      x -= 2;
      lastcommand = 'l';
    currentSpeed = 2;
      distance += 2;
    } else if ((lastcommand == 'l') && (currentSpeed == 2)) {
      x -= 3;
      lastcommand = 'l';
      currentSpeed = 3;
      distance += 3;
    } else if ((lastcommand == 'l') && (currentSpeed == 3)) {
      x -= 4;
      lastcommand = 'l';
      currentSpeed = 4;
      distance += 4;
    } else if ((lastcommand == 'l') && (currentSpeed >= 4)) {
      x -= 4;
      lastcommand = 'l';
      distance += 4;
    } else {
      x -= 1;
      lastcommand = 'l';
      currentSpeed = 1;
      distance += 1;
    }
    break;

  case 'S':
    if (lastcommand == 's') {
      cout << name << " is now started\n";
      lastcommand = '/';
    } else {
      cout << name << " is stopped\n";
      lastcommand = 's';
    }
    break;

  default:
    cout << "\nInvalid Direction\n" << endl;
    break;
  }
}
