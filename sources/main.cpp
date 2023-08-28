#include <iostream>
#include <fstream>
#include "my_dict.hpp"

using mydict::Dictionary;

class Logger
{
  private:
    std::ofstream file;
  public:
    Logger(string filename = "log.txt")
    {
        this->file = std::ofstream(filename);
    }

    ~Logger()
    {
      this->file.close();
    }

    void operator()(const string msg)
    {
      this->file << msg << std::endl;
    }
};

 
int main() {
  Logger log = Logger();
  log("************ Start of log ************");

  Dictionary dict;
  dict["first"] = "5";
  dict["second"] = "second";
  dict["three"] = "2.74";

}