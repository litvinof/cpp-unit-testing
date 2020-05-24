#pragma once
#include <cstdint>
#include <map>
#include <string>

#include "test_runner.hpp"


void TestMapsAreEqual() {
  std::map<std::string, uint16_t> m1 { {"first", 1}, {"second", 2} };
  std::map<std::string, uint16_t> m2 { {"first", 1}, {"second", 3} };

  AssertEqual(m1, m2, "Assert equality for maps");
}

void BooleanAssertion() {
  std::map<std::string, uint16_t> m1 { {"first", 1}, {"second", 2} };
  std::map<std::string, uint16_t> m2 { {"first", 1}, {"second", 3} };

  Assert(true, "Assert boolean");
}

void TestAll() {
  TestRunner tr;
  tr.RunTest(TestMapsAreEqual, "TestMapsAreEqual");
  tr.RunTest(BooleanAssertion, "BooleanAssertion");
}
