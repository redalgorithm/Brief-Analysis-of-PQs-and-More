// comparator.h
//
// CPTG 244 Fall 2017
//
// provides isLess comparators for Point2D elements

#ifndef COMPARATOR_H
#define COMPARATOR_H

#include "Point2D.h"
#include <cmath> // for CenterOutward comparator ... sqrt
using namespace std;

class LeftRight {
 public:
  bool operator() (const Point2D& p, const Point2D& q) const
  { 
    return p.getX() < q.getX();
  }
}; 

class BottomTop {
 public:
  bool operator() (const Point2D& p, const Point2D& q) const
  {
    return p.getY() < q.getY();
  }
};

class LeftRightTopBottom {
 public:
  bool operator() (const Point2D& p, const Point2D& q) const
  {
    if (p.getX() < q.getX()) {
      return true;
    } else if (q.getX() < p.getX()) {
      return false;
    } else { // p.getX() == q.getX()
      return q.getY() < p.getY();
    }

  }
};
class CenterOutward {
 public:
  bool operator() (const Point2D& p, const Point2D& q) const
  {
    double pDis = sqrt(p.getX()*p.getX() + p.getY()*p.getY());
    double qDis = sqrt(q.getX()*q.getX() + q.getY()*q.getY());

    return pDis < qDis;
  }
};

class intLess {
 public:
  bool operator() (const int& p, const int& q) const
  {
    return p < q;
  }
};

template <typename E, typename C>
void printSmaller(const E& p, const E& q, const C& isLess)
{
  cout << (isLess(p,q) ? p : q) << endl;

  // the above statement does the same as the following code:
  /*
    if (isLess(p,q) {
      cout << p;
    } else {
      cout << q;
    }
    cout << endl;
  */
}

#endif
