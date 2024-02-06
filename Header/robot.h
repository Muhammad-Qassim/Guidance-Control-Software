#ifndef robot_h
#define robot_h

#include <cstring>
#include <string>
class robot {

private:
  int x;
  int y;
  char lastcommand;
  int currentSpeed;
  int distance;
  std::string name;

public:
  int get_x();
  int get_y();
  int get_distance();
  void set_name(std::string n);
  std::string get_name();
  char get_lastcommand();
    // Name: Move Robot
    // Parameters:
    //  d: the direction to move a robot
    // Return: none
    // Side Efects: the members of robot class will be updated
  void moverobot(char d);
  robot();
  robot(std::string n);
};
#endif
