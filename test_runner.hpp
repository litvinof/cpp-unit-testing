#pragma once
#include <exception>
#include <iostream>
#include <map>
#include <string>


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


class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const std::string& test_name) {
    try {
      func();
      std::cerr << test_name << " PASSED" << std::endl;
    } catch (std::runtime_error& e) {
      ++fail_count;
      std::cerr << test_name << " FAILED: " << e.what() << std::endl;
    }
  }
  ~TestRunner() {
    if ( fail_count > 0 ) {
      std::cerr << fail_count << " test failed. Terminate";
      exit(1);
    }
  }
private:
  int fail_count = 0;
};
