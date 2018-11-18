// ListPriorityQueue.h
//
// CPTG 244 Fall 2017
//
// from 8.2
//    uses an stl list in a sorted manner
//

#ifndef LISTPQUEUE_H
#define LISTPQUEUE_H

#include <list>
#include <cstdlib>   // exit()
#include <iostream>  // cout
using namespace std;


template <typename E, typename C>
class ListPQueue
{
private:
    list<E> L;
    C isLess;
    
 public:
  // accessor functions
  int size() const;
  bool empty() const;
  const E& min() const;

  // mutator functions
  void insert (const E& e);
  void removeMin();
};
/////////////////////////////////////////////////////////////////////
template <typename E, typename C>
  int ListPQueue<E,C>::size() const
{
  return L.size();
}

template <typename E, typename C>
  bool ListPQueue<E,C>::empty() const
{
  return L.empty();
}

template <typename E, typename C>
  void ListPQueue<E,C>::insert(const E& e)  // O(n) ... walk the list
{
  typename std::list<E>::iterator p;

  // L is a sorted list (low to high)
  
  // empty list
  if (L.empty())
  {
  	L.push_back(e);
  	return;
  }
  
  // non-empty list, list is already in sorted order
  p = L.begin();
  while (p != L.end() && !isLess(e, *p))
  {
  	++p;
  }
  
  // place e after p position
  L.insert(p, e);
}

template <typename E, typename C>
  const E& ListPQueue<E,C>::min() const  // O(1) ... just at begin() of list
{
  if (L.empty())
  {
  	cout << "Attempting to min() when priority Queue is empty.";
  	cout << " ... Exiting\n";
  	exit(1);
  }
  
  // method 1
  return L.front();
}
  
template <typename E, typename C>
  void ListPQueue<E,C>::removeMin()  // O(1)
{

  // L is a sorted list (low to high)
  // always assuming unintelligent users

  if (L.empty())
  {
  	cout << "Attempting to removeMin() when priority Queue is empty.";
  	cout << " ... Exiting\n";
  	exit(2);
  }
  
  L.pop_front();
}

#endif
