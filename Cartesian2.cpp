///////////////////////////////////////////////////
//
//	Manigandan Rajan
//	November, 2019
//
//	------------------------
//	Cartesian2.cpp
//	------------------------
//	
// class for a point in Cartesian space
///////////////////////////////////////////////////

// Include statements
#include "Cartesian2.h"
#include "math.h"
// Include statements

// constructors
Cartesian2::Cartesian2()
	: x(0.0), y(0.0)
{}

// constructor
Cartesian2::Cartesian2(double X, double Y)
	: x(X), y(Y)
{}

// constructor
Cartesian2::Cartesian2(const Cartesian2 &other)
	: x(other.x), y(other.y)
{}

