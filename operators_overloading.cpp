#include <sstream>
#include <iostream>
#include <map>


template <class K, class V>
std::ostream& operator<< (std::ostream& os, const std::map<K,V>& m) {
  os << "{";
  bool first = true;
  for ( const auto& kv : m ) {
    if ( !first ) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}
