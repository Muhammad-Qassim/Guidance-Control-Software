//Muhammad Qassim

#include <iostream>
using namespace std;
#include <cstring>
#include <string>

#include "robot.h"
#include "robotlist.h"

int main() {
  cout << "Welcome.\n";

  int size;
  string n;
  char command;
  char options;
  string robotname;
  string rn;

  robotlist rl;
  robot r;
  // To get input of how many robots user wants

  cout << "Enter how many robos u need : ";
  cin >> size;

  for (int i = 1; i <= size; i++) {
    rl.add();
  }
  do {
    cout << "\nPlease select: "
            "\nM - Move"
            "\nD - Distance"
            "\nU - Update"
            "\nR - Rename"
            "\nQ - quit\n"
         << endl;
    cin >> options;

    if (tolower(options) == 'm') {
      cin >> robotname;

      // Using for loop and if statementt to check if the
      // name of robot is inside the robot list or not

      for (int j = 0; j < size; j++) {
        if (rl.findrobot(robotname) == NULL) {
          cout << "\ninvalid name" << endl;
          break;
        } else
          cin >> command;
        rl.findrobot(robotname)->moverobot(command);

        if ((r.get_lastcommand() == 's') || (r.get_lastcommand() == '/'))
          break;
        else
          cout << rl.findrobot(robotname)->get_name() << "'s position is "
               << rl.findrobot(robotname)->get_x() << ","
               << rl.findrobot(robotname)->get_y() << endl;
        break;
      }
    } // To print the distance of each robot
    else if (tolower(options) == 'd') {
      rl.sort();
      rl.printlist();
    }

    else if (tolower(options) == 'u') {
      char uc;
      cin >> uc;
      if (tolower(uc) == 'a') {
        cin >> robotname;
        rl.ins(robotname);
        cout << "Successfully added " << rl.findrobot(robotname)->get_name();
      }
      if (tolower(uc) == 'd') {
        cin >> robotname;
        rl.pop(robotname);
        cout << "Successfully deleted ";
      }
    }

    else if (tolower(options) == 'r') {
      cin >> robotname;

      for (int j = 0; j < size; j++) {
        if (rl.findrobot(robotname) == NULL) {
          cout << "\ninvalid name" << endl;
          break;
        } else {
          cin >> rn;
          rl.findrobot(robotname)->set_name(rn);
          cout<<"name change successful";
          
          break;
        }
      }
    }

    else if (tolower(options) != 'q') {
      cout << "\ninvalid command\n";
    }

    else if (tolower(options) != 'q') {
      cout << "\ninvalid command\n";
    }
  } while (tolower(options) != 'q');

  cout << "\nGoodbye <3" << endl;

  return 0;
}
