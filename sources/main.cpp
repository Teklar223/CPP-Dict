#include <iostream>
#include <fstream>

#include "my_dict.hpp"
 
int main() {
   // Create and open a text file
  std::ofstream MyFile("log.txt");

  // Write to the file
  MyFile << "************ Start of log ************" << std::endl;;

  // Close the file
  MyFile.close();
}