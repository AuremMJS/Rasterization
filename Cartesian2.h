///////////////////////////////////////////////////
//
//	Manigandan Rajan
//	November, 2019
//
//	------------------------
//	Cartesian2.h
//	------------------------
//	
// class for a point in Cartesian space
///////////////////////////////////////////////////

#ifndef CARTESIAN3_H
#define CARTESIAN3_H

// Include Statements
#include <iostream>
// Include Statements

// Cartesian2 Class
class Cartesian2
{ // Cartesian2
public:
	// the coordinates
	double x, y;

	// constructors
	Cartesian2();
	Cartesian2(double X, double Y);
	Cartesian2(const Cartesian2 &other);

}; // Cartesian2
#endif