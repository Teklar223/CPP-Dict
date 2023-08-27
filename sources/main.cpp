#include <iostream>
#include <fstream>
#include "my_dict.hpp"

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

}