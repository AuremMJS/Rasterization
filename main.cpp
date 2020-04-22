///////////////////////////////////////////////////
//
//	Manigandan Rajan
//	November, 2019
//
//	------------------------
//	main.cpp
//	------------------------
//	
///////////////////////////////////////////////////

// Include statements
#include <iostream>
#include<fstream>
#include "ppmgenerator.h"
// Include Statements

using namespace std;

// main()
int main(int argc, char **argv)
{

	// Get the choice from the user
	cout << "Enter a choice:" << endl
		<< "1. Image using barycentric coordinates using equations given - ABG.ppm" << endl
		<< "2. Halfplane Test - halfplance.ppm" << endl
		<< "3. Halfplane Test Black Triangle - triangle.ppm" << endl
		<< "4. Color Triangle using barycentric coordinates from RGB values - rgb.ppm" << endl
		<< "5. Render Texture in triangle - texture.ppm" << endl
		<< "6. Finding the building at (62,65) - earthlocation.ppm";
	int choice = 0;
	cin >> choice;

	// Generate PPM file based on the choice
	PPMGenerator gen;
	gen.GeneratePPMFile(choice);

	// Exit the program
	exit(0);
}
// main()
