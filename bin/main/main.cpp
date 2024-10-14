
#include <exception>
#include <iostream>

using namespace std;
int main()
{
  try {
    // code here
    std::cout << "Hello, world!\n";
    return 0;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
}
