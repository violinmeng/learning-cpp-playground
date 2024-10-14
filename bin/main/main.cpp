
#include <exception>
#include <iostream>

#include "metaprogramming.hpp"

using namespace std;
int main()
{
  try {
    // code here
    MetaProgramming::metaProgrammingClientCode();
    MetaProgramming::computationOnTypes();
    return 0;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
}
