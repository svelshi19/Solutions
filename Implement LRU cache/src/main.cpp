#include "LRUCache.hpp"
#include <cassert>
#include <iostream>

int main() {
  int capacity = 2;
  LRUCache *obj = new LRUCache(capacity);
  int value = obj->get(2);
  // Verify value = -1
  assert(value == -1);
  // Add
  obj->put(1, 3);
  obj->put(2, 4);
  value = obj->get(2);
  // Verify value = 4
  assert(value == 4);
  // Add 3rd key, 1 should be erased
  obj->put(3, 5);
  value = obj->get(1);
  // Verify value = -1
  assert(value == -1);
  value = obj->get(3);
  // Verify value = 5
  assert(value == 5);

  std::cout << "Code Executed. Test Passed." << std::endl;
}
