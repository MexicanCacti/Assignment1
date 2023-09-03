/***************************************************************************************
*    Title: C++ Plus Data Structures SIXTH EDITION
*    Author: Nell Dale, Chip Weems
*    Date: 08/30/2023
*    Code version: C++11
*    Availability: Pages 138-139
*
***************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // for srand and rand
#include "Number_bucket.h"

int main()
{
  using namespace std;
  ifstream inFile;     // file containing operations
  ofstream outFile;    // file containing output
  string inFileName;   // input file external name
  string outFileName;  // output file external name
  string outputLabel;
  string command;    // operation to be executed
  int numCommands;

  int temp;
  Number_bucket Object1;

  srand(time(0));

  // input file
  inFile.open("Test.txt");

  // output file
  outFile.open("Results.txt");

  cout << "Enter name of test run; press return." << endl;
  cin >> outputLabel;
  outFile << outputLabel << endl;

  inFile >> command;
  numCommands = 0;
  while (command != "Quit")
  {
    if (strcmp(command.c_str(), "isEmpty()") == 0) {
      if (Object1.isEmpty()) {
        outFile << "TRUE " << " \t\t";
      }
      else {
        outFile << "FALSE " << " \t\t";
      }
      Object1.print(outFile);
    }
    else if (strcmp(command.c_str(), "Push()") == 0) {
      temp = 1 + (rand() % 100);
      Object1.push(temp);
      outFile << "Pushed " << temp << " \t";
      Object1.print(outFile);
    }
    else if (strcmp(command.c_str(), "Pop()") == 0) {
      Object1.pop();
      outFile << "Popped " << " \t";
      Object1.print(outFile);
    }
    else if (strcmp(command.c_str(), "get_size()") == 0) {
      outFile << "Size: " << Object1.get_size() << " \t";
      Object1.print(outFile);
    }
    else {
      outFile << "INVALID COMMAND" << endl;
    }

    numCommands++;
    cout << "Command number " << numCommands << " completed."
      << endl;
    inFile >> command;
  }

  cout << "Testing completed." << endl;
  inFile.close();
  outFile.close();
  return 0;
}