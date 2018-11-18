// testListPQueue.cpp
//
// CPTG 244 Fall 2017
//
// testing PQueue based upon a sorted list
//
/*
#include <iostream>
#include <list>      // using STL list for orig values for PQSort
#include "Point2D.h"
#include "comparator.h"
#include "ListPQueue.h"
#include "UnsortedPQ.h"
using namespace std;

template<typename E, typename C>
void InsertionSort(list<E>& L, ListPQueue<E,C>& pQ);

template<typename E, typename C>
void SelectionSort(list<E>& L, UnsortedPQ<E,C>& pQ);

int main()
{
  // demonstrating the int ListPQueue
  //-----------------------------------------
  cout << "Demonstrating the int ListPQueue\n\n";
    
  ListPQueue<int, intLess> p1;

  p1.insert(5);   // <5>
  p1.insert(7);   // <5,7>
  p1.insert(2);   // <2, 5, 7>
  p1.insert(8);   // <2, 5, 7, 8>
  p1.insert(1);   // <1, 2, 5, 7, 8>
  p1.insert(4);   // <1, 2, 4, 5, 7, 8>

  cout << "The values popped off of the int priority_queue are: ";
  while (!p1.empty())
  {
    cout << " " << p1.min();
    p1.removeMin();
  }
  cout << endl;


  ListPQueue<Point2D, LeftRight> lpQ;
  //ListPQueue<Point2D, BottomTop> lpQ;
  //ListPQueue<Point2D, LeftRightTopBottom> lpQ;
  //ListPQueue<Point2D, CenterOutward> lpQ;

  // demonstrating the Point2D priority_queue
  //-----------------------------------------

  lpQ.insert(Point2D(8.5, 4.6)); cout << "Inserting (8.5, 4.6)\n";
  lpQ.insert(Point2D(1.3, 5.7)); cout << "Inserting (1.3, 5.7)\n"; 
  lpQ.insert(Point2D(2.5, 0.6)); cout << "Inserting (2.5, 0.6)\n";
  lpQ.insert(Point2D(2.5, 0.6)); cout << "Inserting (2.5, 0.6)\n"; // same X and Y
  lpQ.insert(Point2D(2.5, 0.0)); cout << "Inserting (2.5, 0.0)\n"; // same X smaller Y
  lpQ.insert(Point2D(2.5, 1.6)); cout << "Inserting (2.5, 1.6)\n"; // same X bigger Y
  lpQ.insert(Point2D(8.5, 2.2)); cout << "Inserting (8.5, 2.2)\n";
  lpQ.insert(Point2D(1.3, 9.9)); cout << "Inserting (1.3, 9.9)\n";

  cout << "The values popped off of the Point2D priority_queue are: \n";
  while (!lpQ.empty())
  {
    cout << "\t" << lpQ.min() << endl;
    lpQ.removeMin();
  }
  cout << endl;

  // Testing InsertionSort

  list<int> intList;

  intList.push_back(5);
  intList.push_back(7);
  intList.push_back(3);
  intList.push_back(8);
  intList.push_back(1);
  intList.push_back(4);
  intList.push_back(6);
  intList.push_back(9);
  intList.push_back(2);

  cout << "The intList contents (before sort) are:\n";
  list<int>::iterator iter;
  for (iter = intList.begin(); iter != intList.end(); ++iter)
  {
    cout << *iter << endl;
  }


  // for testing in lab
  
  ListPQueue<int, intLess> intPQ;

  InsertionSort(intList, intPQ);

  cout << "The intList contents (after  sort) are:\n";

 
  for (iter = intList.begin(); iter != intList.end(); ++iter)
  {
    cout << *iter << endl;
  }
    
    cout << endl << endl << endl;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
    
    // demonstrating the int UnsortedPQ
    //-----------------------------------------
    cout << "Demonstrating the int UnsortedPQ\n\n";
    
    UnsortedPQ<int, intLess> p2;
    
    p2.insert(5);   // <5>
    p2.insert(7);   // <5,7>
    p2.insert(2);   // <5, 7, 2>
    p2.insert(8);   // <5, 7, 2, 8>
    p2.insert(1);   // <5, 7, 2, 8, 1>
    p2.insert(4);   // <5, 7, 2, 8, 1, 4>
    
    cout << "The values popped off of the int priority_queue are: ";
    while (!p2.empty())
    {
        cout << " " << p2.min();
        p2.removeMin();
    }
    cout << endl;
    
    
    UnsortedPQ<Point2D, LeftRight> upQ;
    //ListPQueue<Point2D, BottomTop> lpQ;
    //ListPQueue<Point2D, LeftRightTopBottom> lpQ;
    //ListPQueue<Point2D, CenterOutward> lpQ;
    
    // demonstrating the Point2D priority_queue
    //-----------------------------------------
    
    upQ.insert(Point2D(8.5, 4.6)); cout << "Inserting (8.5, 4.6)\n";
    upQ.insert(Point2D(1.3, 5.7)); cout << "Inserting (1.3, 5.7)\n";
    upQ.insert(Point2D(2.5, 0.6)); cout << "Inserting (2.5, 0.6)\n";
    upQ.insert(Point2D(2.5, 0.6)); cout << "Inserting (2.5, 0.6)\n"; // same X and Y
    upQ.insert(Point2D(2.5, 0.0)); cout << "Inserting (2.5, 0.0)\n"; // same X smaller Y
    upQ.insert(Point2D(2.5, 1.6)); cout << "Inserting (2.5, 1.6)\n"; // same X bigger Y
    upQ.insert(Point2D(8.5, 2.2)); cout << "Inserting (8.5, 2.2)\n";
    upQ.insert(Point2D(1.3, 9.9)); cout << "Inserting (1.3, 9.9)\n";
    
    cout << "The values popped off of the Point2D priority_queue are: \n";
    while (!upQ.empty())
    {
        cout << "\t" << upQ.min() << endl;
        upQ.removeMin();
    }
    cout << endl;
    
    // Testing InsertionSort
    
    list<int> intList2;
    
    intList2.push_back(5);
    intList2.push_back(7);
    intList2.push_back(3);
    intList2.push_back(8);
    intList2.push_back(1);
    intList2.push_back(4);
    intList2.push_back(6);
    intList2.push_back(9);
    intList2.push_back(2);
    
    cout << "The intList contents (before sort) are:\n";
    list<int>::iterator it;
    for (it = intList2.begin(); it != intList2.end(); ++it)
    {
        cout << *it << endl;
    }
    
    
    // for testing in lab
    UnsortedPQ<int, intLess> intPQ2;
    
    SelectionSort(intList2, intPQ2);
    
    cout << "The intList contents (after  sort) are:\n";
    
    
    for (it = intList2.begin(); it != intList2.end(); ++it)
    {
        cout << *it << endl;
    }
    
  return 0;
}

template<typename E, typename C>
void InsertionSort(list<E>& L, ListPQueue<E,C>& pQ)
{
  E temp;
 
  while (!L.empty())
  {
    temp = L.front();
    L.pop_front();
    pQ.insert(temp);
  }	

  while (!pQ.empty())
  {
  	temp = pQ.min();
  	L.push_back(temp);
  	pQ.removeMin();
  }
}

template<typename E, typename C>
void SelectionSort(list<E>& L, UnsortedPQ<E,C>& pQ)
{
    E temp;
   
    while (!L.empty())
    {
        temp = L.front();
        L.pop_front();
        pQ.insert(temp);
    }
    
    while (!pQ.empty())
    {
        temp = pQ.min();
        L.push_back(temp);
        pQ.removeMin();
    }
}
*/
