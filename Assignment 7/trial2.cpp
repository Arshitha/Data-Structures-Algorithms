#include <iostream>     // std::cout
#include <algorithm>    // std::min_element, std::max_element
#include <limits>
#include <vector>

using namespace std;

/*bool myfn(int i, int j) { return i<j; }

struct myclass {
  bool operator() (int i,int j) { return i<j; }
} myobj;*/

int main () {
  vector<int> dist;
  int INF = numeric_limits<int>::max();

  dist.assign(6, INF);

    dist[0] = 0;
    dist[5] = -9;

  // using default comparison:
  std::cout << "The smallest element is " << *std::min_element(begin(dist), end(dist)) << '\n';
  //std::cout << "The largest element is "  << *std::max_element(myints,myints+7) << '\n';

  // using function myfn as comp:
  /*std::cout << "The smallest element is " << *std::min_element(myints,myints+7,myfn) << '\n';
  std::cout << "The largest element is "  << *std::max_element(myints,myints+7,myfn) << '\n';

  // using object myobj as comp:
  std::cout << "The smallest element is " << *std::min_element(myints,myints+7,myobj) << '\n';
  std::cout << "The largest element is "  << *std::max_element(myints,myints+7,myobj) << '\n';*/

  return 0;
}
