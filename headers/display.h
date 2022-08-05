/**
 * @file display.h
 *
 * @brief This is a static function class that displays text prompts for the banking system
 *
 * @author Richard Duong & Kenny Truong
 */
#ifndef DISPLAY_H
#define DISPLAY_H

// standard libraries
#include <iostream>
#include <string>



class Display {
public:
  static void customerMenu(const std::string& name);
  static void managerMenu(const std::string& name);
  static void main();
  static void accountMenu();
};



#endif