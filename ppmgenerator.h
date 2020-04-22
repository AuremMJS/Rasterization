///////////////////////////////////////////////////
//
//	Manigandan Rajan
//	November, 2019
//
//	------------------------
//	ppmgenerator.h
//	------------------------
//	
// class for generating a ppm file based on the choice
///////////////////////////////////////////////////

#ifndef PPMGENERATOR_H
#define PPMGENERATOR_H

// Include statements
#include <fstream>
// Include statements

using namespace std;

// Class PPMGenerator
class PPMGenerator
{
public:
	// Constructor
	PPMGenerator();

	// Function to generate a ppm file based on the user's choice
	void GeneratePPMFile(int choice);

	// Function to generate a ppm file with an image by interpolating using a function
	void ABG();

	// Function to generate a ppm file to generate a triangle using halfplane test
	void HalfPlane();

	// Function to generate a ppm file to generate a black triangle using halfplane test
	void Triangle();

	// Function to generate a ppm file to generate a triangle with colors interpolated between red, green and blue
	void RGB();

	// Function to generate a ppm file to render the texture in earth.ppm into a triangle using barycentric coordinates
	void Texture();

	// Function to generate a ppm file to render the texture in earth.ppm into a triangle using barycentric coordinates and to find the location at (62,65)
	void Earth();

	// Function to generate the output file with ppm format
	ofstream CreateOutputFile(string filename, long height, long width);
};

#endif // PPMGENERATOR_H
