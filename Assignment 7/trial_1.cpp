// istringstream::str
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <typeinfo>

using namespace std;

int main () {
  std::istringstream iss;
  std::string strvalues = "32 240 2 1450";

  iss.str (strvalues);

  for (int n=0; n<4; n++)
  {
    int val;
    iss >> val;
    std::cout << val << '\n';
    std::cout << typeid(val).name() << endl;
  }
  std::cout << "Finished writing the numbers in: ";
  std::cout << iss.str() << '\n';
  std::cout << typeid(iss.str()).name() << endl;
  return 0;
}

