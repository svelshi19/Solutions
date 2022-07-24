#include <iterator>
#include <list>
#include <unordered_map>

class LRUCache {
private:
  std::unordered_map<int, int> m_cache; // store key_value
  std::list<int> m_lruList;             // store keys
  std::unordered_map<int, std::list<int>::iterator>
      m_iterator; // store iterator
  int m_capacity;

  void updateLru(int key);

public:
  LRUCache(int capacity);
  int get(int key);
  void put(int key, int value);
};
