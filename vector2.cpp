///////////////////////////////////////////////////
//
//	Manigandan Rajan
//	November, 2019
//
//	------------------------
//	vector2.cpp
//	------------------------
//	
// class for a Vector in Cartesian space
///////////////////////////////////////////////////

// Include Statements
#include "vector2.h"
// Include Statements

// Constructor
Vector2::Vector2()
{
	x = 0;
	y = 0;
}

// Constructor
Vector2::Vector2(double xval, double yval)
{
	x = xval;
	y = yval;
}

// Constructor
Vector2::Vector2(Cartesian2 x1, Cartesian2 x2)
{
	x = x2.x - x1.x;
	y = x2.y - x1.y;
}

// Constructor
Vector2::Vector2(Cartesian2 p)
{
	x = p.x;
	y = p.y;
}

// Function to find the normal of the vector
Vector2 Vector2::normal()
{
	// Return the normal to the vector
	return Vector2(-y, x);
}


// Function to find the magnitude of the vector
double Vector2::magnitude()
{
	// Calculate and return the magnitude
	return sqrt(x*x + y * y);
}

// Function to find the distance of a point from the vector
double Vector2::getDistance(Cartesian2 o, Cartesian2 p)
{
	// Create a vector for the point
	Vector2 point(o.x - p.x, o.y - p.y);

	// Get the normal of this vector
	Vector2 n = normal();

	// Calculate the distance
	double distance = (point*n) / n.magnitude();

	// Return the distance
	return distance;
}

// Operator *
double Vector2::operator*(Vector2 &other)
{
	return x * other.x + y * other.y;
}
