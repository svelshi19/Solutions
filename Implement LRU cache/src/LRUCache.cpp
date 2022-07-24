#include "LRUCache.hpp"

void LRUCache::updateLru(int key) {
  // Remove from list and add to beginning(increase priority)
  m_lruList.erase(m_iterator[key]);
  // Add to the begining
  m_lruList.push_front(key);
}

LRUCache::LRUCache(int capacity) { m_capacity = capacity; }

int LRUCache::get(int key) {
  auto it = m_cache.find(key);
  if (it != m_cache.end()) {
    updateLru(key);
    m_iterator[key] = m_lruList.begin();
    return m_cache[key];
  }
  return -1;
}

void LRUCache::put(int key, int value) {
  auto it = m_cache.find(key);
  if (it != m_cache.end()) {
    updateLru(key);
  } else {
    if (m_cache.size() < m_capacity) {
      m_lruList.push_front(key);
    } else { // Greater than capacity
      m_cache.erase(m_lruList.back());
      m_iterator.erase(m_lruList.back());
      m_lruList.pop_back();
      m_lruList.push_front(key);
    }
  }
  m_cache[key] = value;
  m_iterator[key] = m_lruList.begin();
}
