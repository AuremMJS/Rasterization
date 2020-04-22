///////////////////////////////////////////////////
//
//	Manigandan Rajan
//	November, 2019
//
//	------------------------
//	vector2.h
//	------------------------
//	
// class for a vector in Cartesian space
///////////////////////////////////////////////////

#ifndef VECTOR2_H
#define VECTOR2_H
#include <math.h>
#include "Cartesian2.h"

// Vector2 Class
class Vector2
{
private:
	// x, y values of vector
	double x;
	double y;
public:

	// Constructors
	Vector2();
	Vector2(double xval, double yval);
	Vector2(Cartesian2 x1, Cartesian2 x2);
	Vector2(Cartesian2 p);

	// Operator *
	double operator *(Vector2& other);

	// Function to find the normal of the vector
	Vector2 normal();

	// Function to find the magnitude of the vector
	double magnitude();

	// Function to find the distance of a point from the vector
	double getDistance(Cartesian2 o, Cartesian2 p);
};

#endif // VECTOR2_H
