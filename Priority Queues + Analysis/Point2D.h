// Point2D.h
//
// Used in ch8 of CPTG 244 text in Fall 2017
//

#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>   // for << overload
using namespace std;

class Point2D;   // class prototype
ostream& operator << (ostream& os, const Point2D& p);  // << overload prototype

class Point2D {
 public:
  Point2D() {  // default constructor
    x = 0.0;
    y = 0.0;
  }
  Point2D(double px, double py) {
    x = px;
    y = py;
  }
  Point2D(const Point2D& other) {  // copy constructor
    x = other.x;
    y = other.y;
  }

  Point2D& operator =(const Point2D& other) { // assignment operator
    x = other.x;
    y = other.y;
    return *this;
  }

  double getX() const {return x;}
  double getY() const {return y;}

  void setX(double px) {x = px;}
  void setY(double py) {y = py;}

 private:
  double x;
  double y;

};  // end of class Point2D


// overloading the stream insertion operator for Point2D output
ostream& operator << (ostream& os, const Point2D& p)
{
  os << "(" << p.getX() << "," << p.getY() << ")";
  return os;
}



#endif
