/*	Test driver for sorting.      Used:  Fall 2017
	
	Written by: G & F
        Adapted by: B. Kreaseck 5/2011

	Date:       2/98
	
	Revised     5/99 Converted to C++
	
	Brooks/Cole
	A division of Thomson Learning
	Copyright(c) 2001. All Rights Reserved
*/
/*
 FURTHER INSTRUCTIONS:
 _____________________________________________________________________________________________________________________
 You will only choose one of the sorts from the allSorts.cpp file.... so you will only have one sort that uses an array.
 
 You will have versions of sorts that use a ListPQueue, and you will have versions of sorts that use your UnsortedPQ.
 
 For testing your sorts, a size of 5 is sufficient to demonstrate that the sort actually works.
 
 For performing the timings across all sorts, uou will use the sizes that we used back in Lab 2 ...
 
 a.  Use the following data sizes:
 10000, 20000, 40000, 80000, 160000, 320000
 _____________________________________________________________________________________________________________________
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>      // for use with random number generator
#include <ctime>        // for timing our functions
#include <list>
#include "comparator.h"
#include "Point2D.h"
#include "ListPQueue.h"
#include "UnsortedPQ.h"
using namespace std;

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
//	Prototype Declarations
	//void insertionSort (int list[ ], int last);
//	Prototype Declarations
	void bubbleSort	(int list[ ], int last);
//	Prototype Declarations
	//void selectionSort	(int list[ ], int last) ;
	
int main (void)
{
//	Local Declarations 
	int i;
    int size;
	int* ary1;
    ListPQueue<int, intLess> intPQ;
    UnsortedPQ<int, intLess> intPQ2;
	//int* ary2;
	//int* ary3;

        // variables for timing
        clock_t start_time;
        clock_t end_time;
        double seconds, millisecs, microsecs;
        //10000, 20000, 40000, 80000, 160000, 320000
        size = 320000;            // or could prompt user for size
        
        ary1 = new int [size];
        //ary2 = new int [size];
        //ary3 = new int [size];
        if (!ary1 /*|| !ary2 || !ary3*/)
        {
          cout << "error allocating array\n";
          exit(23);
        }

        // initalize the pseudo-random number generator
        srand(time(NULL));
    
        list<int> list1, list2;
        for (i = 0; i<size; i++)
        {
          int val = rand() % 1000000;
          ary1[i] = /*ary2[i] = ary3[i] =*/ val;    // six digits
          list1.push_back(val);
          list2.push_back(val);
        }

/*
//	Statements 
	cout << "Unsorted array1: ";
	for ( i = 0; i < size; i++ )
		cout <<setw(7) << ary1[ i ];
        cout << endl;
	cout << "Unsorted list1: ";
    list<int>:: iterator it;
	for ( it = list1.begin(); it != list1.end(); it++ )
		cout <<setw(7) << *it;
        cout << endl;
	cout << "Unsorted list2: ";
	for ( it = list2.begin(); it != list2.end(); it++ )
		cout <<setw(7) << *it;
        cout << endl;
*/
        // Sorting

        // start timer
        start_time = clock();
        // start procedure to be timed
        InsertionSort(list1, intPQ);
        //insertionSort (ary1, size - 1);
        // stop timer
        end_time = clock();

        seconds = (end_time - start_time) / (double)CLOCKS_PER_SEC;
        millisecs = seconds * 1000;
        microsecs = seconds * 1000000;
        cout << "Insertion Sort on " << size << " took " << millisecs
             << " mSec\n";

        // start timer
        start_time = clock();
        // start procedure to be timed
        SelectionSort(list2, intPQ2);
        //selectionSort (ary2, size - 1);
        // stop timer
        end_time = clock();

        seconds = (end_time - start_time) / (double)CLOCKS_PER_SEC;
        millisecs = seconds * 1000;
        microsecs = seconds * 1000000;
        cout << "Selection Sort on " << size << " took " << millisecs
             << " mSec\n";

        // start timer
        start_time = clock();
        // start procedure to be timed
        bubbleSort (ary1, size - 1);
        // stop timer
        end_time = clock();

        seconds = (end_time - start_time) / (double)CLOCKS_PER_SEC;
        millisecs = seconds * 1000;
        microsecs = seconds * 1000000;
        cout << "Bubble Sort on " << size << " took " << millisecs
             << " mSec\n";
/*
        // verifying
	cout <<  "\nSorted array1:   ";
	for ( i = 0; i < size; i++ )
		cout <<setw(7) <<  ary1[ i ];
	cout << endl ; 
	cout <<  "\nSorted list1:   ";
	for ( it = list1.begin(); it != list1.end(); it++ )
		cout <<setw(7) <<  *it;
	cout << endl ; 
	cout <<  "\nSorted list2:   ";
	for ( it = list2.begin(); it != list2.end(); it++ )
		cout <<setw(7) <<  *it;
	cout << endl ;
 */
    cout << endl;
	return 0;
}	// main 

/*	==================== insertionSort =====================
	Sort list using insertion sort. The list is divided into 
	sorted and unsorted lists. With each pass, first element 
	in unsorted list is inserted into sorted list.
	   Pre   list must contain at least one element
	         last contains index to last element in the list
	   Post  list has been rearranged
*//*
void insertionSort (int list[], 
                    int last) 
{
//	Local Definitions 
	int current;
	int hold;
	int walker;
	bool done;

//	Statements 
	for (current = 1; current <= last; current++)
	   {
	    hold = list[current];
	    done = false;
	    walker = current - 1;
	    while (walker >= 0 && !done) {
//	    for (walker = current - 1; walker >= 0 && !done; walker--) { 
//	         walker >= 0 && hold < list[walker]; 
//	         walker--) {
			if (hold < list[walker]) {
			    list[walker + 1] = list[walker];
			    walker --;
			} else {
			     done = true;
			}
	    }
	    list [walker + 1] = hold;
	   } // for current 

	return;
}	// insertionSort 

*//*	Results
	Unsorted array:  89 72  3 15 21 57 61 44 19 98  5 77 39 59 61
	Sorted array:     3  5 15 19 21 39 44 57 59 61 61 72 77 89 98


	=================== selectionSort ====================
	Sorts list[0...last] by selecting smallest element in 
	unsorted portion of array and exchanging it with element
	at the beginning of the unsorted list.
	   Pre  list must contain at least one item
	        last contains index to last element in the list
	   Post list has been rearranged smallest to largest
*//*
void selectionSort  (int list[], 
                     int last)
{
//	Local Definitions 
	int current;
	int smallest;
	int holdData;
	int walker;

//	Statements 
	for (current = 0; current < last; current++)
	   {
	    smallest = current;
	    for (walker = current + 1;
	         walker <= last;
	         walker++)
	       if (list[walker] < list[smallest])
	           smallest = walker;

	    // Smallest selected: exchange with current 
	    holdData        = list[current];
	    list[current]   = list[smallest];
	    list[smallest]  = holdData;
	   } //  for current 
	return;
}	// selectionSort 


*//*	=================== bubbleSort ====================
	Sort list using bubble sort. Adjacent elements are 
	compared and exchanged until list completely ordered.
	   Pre   list must contain at least one item
	         last contains index to last element in list
	   Post  list rearranged in sequence low to high
*/
void bubbleSort  (int list [],
                  int last)
{
//	Local Definitions 
	int   current;
	int   walker;
	int   temp;
	bool  sorted;

//	Statements 
	// Each iteration is one sort pass 
	for (current = 0, sorted = false; current <= last && !sorted; current++)
	   for (walker = last, sorted = true; walker > current; walker--)
	      if (list[walker] < list[walker - 1])
	         // Any exchange means list is not sorted
	         {
	          sorted           = false;
	          temp             = list[walker];
	          list[walker]     = list[walker - 1];
	          list[walker - 1] = temp;
	         } // if
	return;
}	// bubbleSort 

/*	Results
	Unsorted array:  89 72  3 15 21 57 61 44 19 98  5 77 39 59 61
	Sorted array:     3  5 15 19 21 39 44 57 59 61 61 72 77 89 98
*/
