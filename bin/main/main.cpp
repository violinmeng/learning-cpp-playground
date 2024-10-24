
#include <exception>
#include <iostream>

#include "const.hpp"
#include "copyinitializer.hpp"
#include "metaprogramming.hpp"

using namespace std;
int main()
{
  try {
    // code here
    MetaProgramming::metaProgrammingClientCode();
    MetaProgramming::computationOnTypes();
    LearnConst::testConst();
    CopyInitializer::testCopyConstructor();
    return 0;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
}
