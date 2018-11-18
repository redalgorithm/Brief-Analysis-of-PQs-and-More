//
//  UnsortedPQ.h
//  5
//
//  Created by DOS on 5/28/18.
//  Copyright © 2018 cult. All rights reserved.
//

#ifndef UnsortedPQ_h
#define UnsortedPQ_h

#include <list>
#include <cstdlib>   // exit()
#include <iostream>  // cout
using namespace std;


template <typename E, typename C>
class UnsortedPQ
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
    void insert(const E& e);
    void removeMin();
    

};
/////////////////////////////////////////////
template <typename E, typename C>
int UnsortedPQ<E,C>::size() const
{
    return L.size();
}

template <typename E, typename C>
bool UnsortedPQ<E,C>::empty() const
{
    return L.empty();
}

template <typename E, typename C>
void UnsortedPQ<E,C>::insert(const E& e)
{
    L.push_back(e);
}

template <typename E, typename C>
const E& UnsortedPQ<E,C>::min() const
{
    typename list<E>:: const_iterator p;
    typename list<E>:: const_iterator e;
    
    // if we are not assuming intelligent users
    if (L.empty())
    {
        cout << "Attempting to min() when Priority Queue is empty.";
        cout << " ... Exiting\n";
        exit(1);
    }
    
    p = L.cbegin();
    e = L.cbegin();
    
    while (p != L.cend())
    {
        if(!isLess(*e,*p))
            e = p;
        
        ++p;
    }
    
    return *e;
}

template <typename E, typename C>
void UnsortedPQ<E,C>::removeMin() 
{
    
    if (L.empty())
    {
        cout << "Attempting to removeMin() when Priority Queue is empty.";
        cout << " ... Exiting\n";
        exit(2);
    }
    
    typename list<E>::iterator p;
    typename list<E>::iterator x;
    p = L.begin();
    x = L.begin();
    while (p != L.end())
    {
        if(!isLess(*x,*p))
        {
            x = p;
        }
        ++p;
    }
    
    L.erase(x);
    
}

#endif /* UnsortedPQ_h */
