#include <cstdint>
#include <exception>
#include <iostream>
#include <map>
#include <string>

#include "operators_overloading.cpp"

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

void Assert(bool b, const std::string& hint) {
  AssertEqual(b, true, hint);
}


int main() {

  std::map<std::string, uint16_t> m1 { {"first", 1}, {"second", 2} };
  std::map<std::string, uint16_t> m2 { {"first", 1}, {"second", 3} };

  AssertEqual(0, 0, "Assert equality");
  AssertEqual(m1, m2, "Assert equality for maps");

  Assert(true, "Assert boolean");

  

  return 0;

}
