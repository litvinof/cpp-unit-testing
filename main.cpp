#include <iostream>
#include <string>
#include <sstream>
#include <exception>

template <class T, class U>
void AssertEqual(const T& t,
		 const U& u,
		 const std::string& hint) {
  if ( t != u ) {
    std::ostringstream os;
    os << "Assertion failed: " << t << " != " << u
       << "; Hint: " << hint;
    throw std::runtime_error(os.str());
  }
}


int main() {
  
  AssertEqual(1, 0, "Unique string 1");

  return 0;

}
