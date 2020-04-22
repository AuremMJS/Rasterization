///////////////////////////////////////////////////
//
//	Manigandan Rajan
//	November, 2019
//
//	------------------------
//	ppmgenerator.cpp
//	------------------------
//	
// class for generating a ppm file based on the choice
///////////////////////////////////////////////////

// include statements
#include <fstream>
#include <iostream>
#include "ppmgenerator.h"
#include "vector2.h"
// include statements

using namespace std;

// constructor
PPMGenerator::PPMGenerator()
{

}
// constructor

// Function to generate a ppm file based on the user's choice
// choice - the choice of operation decides which ppm file has to be generated
void PPMGenerator::GeneratePPMFile(int choice)
{
	if (choice == 1)
		ABG();
	else if (choice == 2)
		HalfPlane();
	else if (choice == 3)
		Triangle();
	else if (choice == 4)
		RGB();
	else if (choice == 5)
		Texture();
	else if (choice == 6)
		Earth();
}

// Function to generate a ppm file with an image by interpolating using a function
void PPMGenerator::ABG()
{
	// Set height and width values
	long height = 128;
	long width = 128;

	// Create a output file with the format ppm
	ofstream oFile = CreateOutputFile("abg.ppm", height, width);

	// Create vertices of the triangle
	Cartesian2 A(61, 10);
	Cartesian2 B(100, 100);
	Cartesian2 C(25, 90);

	// Create vectors
	Vector2 AB(A, B);
	Vector2 BC(B, C);
	Vector2 CA(C, A);

	// Calculate the distance between each vertex and the vectors opposite to it in the triangle
	double A_BC = BC.getDistance(A, B);
	double B_CA = CA.getDistance(B, C);
	double C_AB = AB.getDistance(C, A);

	// Loop through each point in cartesian coordinates
	for (int y = height - 1; y >= 0; y--)
	{
		for (int x = 0; x < width; x++)
		{
			// Current point
			Cartesian2 p(x, y);

			// Calculate the distance between current point and each vector in the triangle
			double p_BC = BC.getDistance(p, B);
			double p_CA = CA.getDistance(p, C);
			double p_AB = AB.getDistance(p, A);

			// Calculate the barycentric coordinates
			double alpha = p_BC / A_BC;
			double beta = p_CA / B_CA;
			double gamma = p_AB / C_AB;

			// Calculate the RGB values
			int r = 100 + 100 * alpha;
			int g = 100 + 100 * beta;
			int b = 100 + 100 * gamma;

			// Clamp the values to 0 if the value is less than 0
			r = r < 0 ? 0 : r;
			g = g < 0 ? 0 : g;
			b = b < 0 ? 0 : b;

			// Clamp the values to 255 if the value is greater than 255
			r = r > 255 ? 255 : r;
			g = g > 255 ? 255 : g;
			b = b > 255 ? 255 : b;

			// Write the RGB values to the file
			oFile << r << endl << g << endl << b << endl;
		}
	}
	cout << " Successfully generated the PPM file" << endl;
}

// Function to generate a ppm file to generate a triangle using halfplane test
void PPMGenerator::HalfPlane()
{
	// Set height and width values
	long height = 128;
	long width = 128;

	// Create the output file with ppm format
	ofstream oFile = CreateOutputFile("halfplane.ppm", height, width);

	// Create vertices of the triangle
	Cartesian2 A(61, 10);
	Cartesian2 B(100, 100);
	Cartesian2 C(25, 90);

	// Create the vectors of the triangle
	Vector2 AB(A, B);
	Vector2 BC(B, C);
	Vector2 CA(C, A);

	// Calculate the distance between each vertex in the triangle and the vector opposite to it
	double A_BC = BC.getDistance(A, B);
	double B_CA = CA.getDistance(B, C);
	double C_AB = AB.getDistance(C, A);

	// Loop through each point the cartesian coordinates
	for (int y = height - 1; y >= 0; y--)
	{
		for (int x = 0; x < width; x++)
		{
			// Current point
			Cartesian2 p(x, y);

			// Calculate the distance between the current point and each vector in the triangle
			double p_BC = BC.getDistance(p, B);
			double p_CA = CA.getDistance(p, C);
			double p_AB = AB.getDistance(p, A);

			// Calculate the barycentric coordinates
			double alpha = p_BC / A_BC;
			double beta = p_CA / B_CA;
			double gamma = p_AB / C_AB;

			// Calculate the RGB values based on the halfplane test condition
			int r = (alpha < 0) ? 0 : 255;
			int g = (beta < 0) ? 0 : 255;
			int b = (gamma < 0) ? 0 : 255;

			// Write the RGB values to the file
			oFile << r << endl << g << endl << b << endl;
		}
	}
	cout << " Successfully generated the PPM file" << endl;
}

// Function to generate a ppm file to generate a black triangle using halfplane test
void PPMGenerator::Triangle()
{
	// Set height and width values
	long height = 128;
	long width = 128;

	// Create a output file with the ppm format
	ofstream oFile = CreateOutputFile("triangle.ppm", height, width);

	// Create vertices of the triangle
	Cartesian2 A(61, 10);
	Cartesian2 B(100, 100);
	Cartesian2 C(25, 90);

	// Create vectors in the triangle
	Vector2 AB(A, B);
	Vector2 BC(B, C);
	Vector2 CA(C, A);

	// Calculate the distance between each vertex and the vector opposite to that in triangle
	double A_BC = BC.getDistance(A, B);
	double B_CA = CA.getDistance(B, C);
	double C_AB = AB.getDistance(C, A);

	// Loop through each point in cartesian coordinates
	for (int y = height - 1; y >= 0; y--)
	{
		for (int x = 0; x < width; x++)
		{
			// Current point
			Cartesian2 p(x, y);

			// Calculate the distance between the current point and each  vector in the triangle
			double p_BC = BC.getDistance(p, B);
			double p_CA = CA.getDistance(p, C);
			double p_AB = AB.getDistance(p, A);

			// Calculate the barycentric coordinates
			double alpha = p_BC / A_BC;
			double beta = p_CA / B_CA;
			double gamma = p_AB / C_AB;

			// Calculate the RGB values based on the condition in the halfplane test
			int r = (alpha >= 0) ? 0 : 255;
			int g = (beta >= 0) ? 0 : 255;
			int b = (gamma >= 0) ? 0 : 255;

			// Write the RGB values into the output file
			oFile << r << endl << g << endl << b << endl;
		}
	}
	cout << " Successfully generated the PPM file" << endl;
}

// Function to generate a ppm file to generate a triangle with colors interpolated between red, green and blue
void PPMGenerator::RGB()
{
	// Set height and width values
	long height = 128;
	long width = 128;

	// Create a output file with the ppm format
	ofstream oFile = CreateOutputFile("RGB.ppm", height, width);

	// Create vertices of the triangle
	Cartesian2 A(61, 10);
	Cartesian2 B(100, 100);
	Cartesian2 C(25, 90);

	// Create vectors in the triangle
	Vector2 AB(A, B);
	Vector2 BC(B, C);
	Vector2 CA(C, A);

	// Calculate the distance between each vertex and the vector opposite to that in triangle
	double A_BC = BC.getDistance(A, B);
	double B_CA = CA.getDistance(B, C);
	double C_AB = AB.getDistance(C, A);

	// Loop through each point in cartesian coordinates
	for (int y = height - 1; y >= 0; y--)
	{
		for (int x = 0; x < width; x++)
		{
			// Current point
			Cartesian2 p(x, y);

			// Calculate the distance between the current point and each vector in the triangle
			double p_BC = BC.getDistance(p, B);
			double p_CA = CA.getDistance(p, C);
			double p_AB = AB.getDistance(p, A);

			// Calculate the barycentric coordinates
			double alpha = p_BC / A_BC;
			double beta = p_CA / B_CA;
			double gamma = p_AB / C_AB;

			// Calculate the RGB values
			int r = 255 * alpha;
			int g = 255 * beta;
			int b = 255 * gamma;
			int outerR = 255;
			int outerG = 255;
			int outerB = 192;

			// Write the RGB values to the file
			if ((alpha >= 0.0 && alpha <= 1.0) && (beta >= 0.0&& beta <= 1.0) && (gamma >= 0.0 && gamma <= 1.0))

				oFile << r << endl << g << endl << b << endl;
			else
				oFile << outerR << endl << outerG << endl << outerB << endl;
		}
	}
	cout << " Successfully generated the PPM file" << endl;
}

// Function to generate a ppm file to render the texture in earth.ppm into a triangle using barycentric coordinates
void PPMGenerator::Texture()
{
	// Load the texture file
	ifstream inFile("earth.ppm");

	if (inFile.bad() || inFile.fail())
	{
		cout << "Texture is not found";
		return;
	}

	//Read the header
	string s;
	while (s != "#")
	{
		inFile >> s;

	}

	// Read the comments
	getline(inFile, s);

	// Read the height and width of the texture
	int texWidth, texHeight;
	inFile >> texWidth >> texHeight;

	// Read max colours
	inFile >> s;

	// Array of texels
	int texels[texWidth][texHeight][3];

	// Fetch the texels from texture and store it in array of texels
	for (int y = texHeight - 1; y >= 0; y--)
	{
		for (int x = 0; x < texWidth; x++)
		{
			inFile >> texels[x][y][0] >> texels[x][y][1] >> texels[x][y][2];
		}
	}

	// Set height and width values
	long height = 128;
	long width = 128;

	// Create a output file with the ppm format
	ofstream oFile = CreateOutputFile("texture.ppm", height, width);

	// Create vertices of the triangle
	Cartesian2 A(61, 10);
	Cartesian2 B(100, 100);
	Cartesian2 C(25, 90);

	// Create vectors in the triangle
	Vector2 AB(A, B);
	Vector2 BC(B, C);
	Vector2 CA(C, A);

	// Calculate the distance between each vertex and the vector opposite to that in triangle
	double A_BC = BC.getDistance(A, B);
	double B_CA = CA.getDistance(B, C);
	double C_AB = AB.getDistance(C, A);

	// U coordinates at each vertex
	double u_A = 0.160268;
	double u_B = 0.083611;
	double u_C = 0.230169;

	// V coordinates at each vertex
	double v_A = 0.290086;
	double v_B = 0.159907;
	double v_C = 0.222781;

	// Loop through each point in cartesian coordinates
	for (int y = height - 1; y >= 0; y--)
	{
		for (int x = 0; x < width; x++)
		{
			// Current point
			Cartesian2 p(x, y);

			// Calculate the distance between the current point and each  vector in the triangle
			double p_BC = BC.getDistance(p, B);
			double p_CA = CA.getDistance(p, C);
			double p_AB = AB.getDistance(p, A);

			// Calculate the barycentric coordinates
			double alpha = p_BC / A_BC;
			double beta = p_CA / B_CA;
			double gamma = p_AB / C_AB;

			// Calculate the RGB values
			int outerR = 255;
			int outerG = 255;
			int outerB = 192;

			if ((alpha >= 0.0 && alpha <= 1.0) && (beta >= 0.0&& beta <= 1.0) && (gamma >= 0.0 && gamma <= 1.0))
			{
				// Calculate the texel to be copied for the current point
				double u = alpha * u_A + beta * u_B + gamma * u_C;
				double v = alpha * (1 - v_A) + beta * (1 - v_B) + gamma * (1 - v_C);
				int i = u * texWidth;
				int j = v * texHeight;

				// Calculate the RGB values from the texels
				int r = texels[i][j][0];
				int g = texels[i][j][1];
				int b = texels[i][j][2];

				// Write the RGB values to the file
				oFile << r << endl << g << endl << b << endl;
			}
			else
			{
				// Write the RGB values to the file
				oFile << outerR << endl << outerG << endl << outerB << endl;
			}
		}
	}
	cout << " Successfully generated the PPM file" << endl;
}

// Function to generate a ppm file to render the texture in earth.ppm into a triangle using barycentric coordinates and to find the location at (62,65)
void PPMGenerator::Earth()
{
	// Load the texture file
	ifstream inFile("earth.ppm");

	if (inFile.bad() || inFile.fail())
	{
		cout << "Texture is not found";
		return;
	}
	//Read the header
	string s;
	while (s != "#")
	{
		inFile >> s;

	}

	// Read the comments
	getline(inFile, s);

	// Read the height and width of the texture
	int texWidth, texHeight;
	inFile >> texWidth >> texHeight;

	// Read max colours
	inFile >> s;

	// Array of texels
	int texels[texWidth][texHeight][3];

	// Fetch the texels from texture and store it in array of texels
	for (int y = texHeight; y > 0; y--)
	{
		for (int x = 0; x < texWidth; x++)
		{
			inFile >> texels[x][y][0] >> texels[x][y][1] >> texels[x][y][2];
		}
	}

	// Create a output file with the ppm format
	ofstream oFile = CreateOutputFile("earthlocation.ppm", texHeight, texWidth);

	// Create vertices of the triangle
	Cartesian2 A(61, 10);
	Cartesian2 B(100, 100);
	Cartesian2 C(25, 90);

	// Create vectors in the triangle
	Vector2 AB(A, B);
	Vector2 BC(B, C);
	Vector2 CA(C, A);

	// Calculate the distance between each vertex and the vector opposite to that in triangle
	double A_BC = BC.getDistance(A, B);
	double B_CA = CA.getDistance(B, C);
	double C_AB = AB.getDistance(C, A);

	// U coordinates at each vertex
	double u_A = 0.160268;
	double u_B = 0.083611;
	double u_C = 0.230169;

	// V coordinates at each vertex
	double v_A = 0.290086;
	double v_B = 0.159907;
	double v_C = 0.222781;

	// Point D
	Cartesian2 D(62, 65);

	// Calculate the distance between D and each vector in triangle
	double D_BC = BC.getDistance(D, B);
	double D_CA = CA.getDistance(D, C);
	double D_AB = AB.getDistance(D, A);

	// Calculate barycentric coordinates at D
	double dAlpha = D_BC / A_BC;
	double dBeta = D_CA / B_CA;
	double dGamma = D_AB / C_AB;

	// Calculate texels at D
	double dU = dAlpha * u_A + dBeta * u_B + dGamma * u_C;
	double dV = dAlpha * (1 - v_A) + dBeta * (1 - v_B) + dGamma * (1 - v_C);
	int dI = dU * texWidth;
	int dJ = dV * texHeight;

	// Calculate latitude and longitude
	double latitude = (2 * (dU - 0.5)) * 180;
	double longitude = (dV - 0.5) * 180;

	// Print the latitude and longitude
	cout.precision(6);
	cout << "lat: " << fixed << latitude << " long: " << fixed << longitude << endl;
	cout << " Based on the latitude and longitude the location is found to be Canada Place, Vancour, Cananda" << endl;

	// Loop through each point in cartesian coordinates
	for (int y = texHeight; y > 0; y--)
	{
		for (int x = 0; x < texWidth; x++)
		{
			// Current point
			Cartesian2 p(x, y);

			// Calculate the distance between current point and each vector in the triangle
			double p_BC = BC.getDistance(p, B);
			double p_CA = CA.getDistance(p, C);
			double p_AB = AB.getDistance(p, A);

			// Calculate the barycentric coordinates
			double alpha = p_BC / A_BC;
			double beta = p_CA / B_CA;
			double gamma = p_AB / C_AB;

			// Calculate the RGB values
			int outerR = texels[x][y][0];
			int outerG = texels[x][y][1];
			int outerB = texels[x][y][2];

			if ((x == dI + 2 || x == dI - 2 || y == dJ + 2 || y == dJ - 2) && (x > dI - 3 && x<dI + 3 && y>dJ - 3 && y < dJ + 3))
			{
				// Write the RGB values to the file
				oFile << "255" << endl << "0" << endl << "0" << endl;
				continue;
			}
			if ((alpha >= 0.0 && alpha <= 1.0) && (beta >= 0.0&& beta <= 1.0) && (gamma >= 0.0 && gamma <= 1.0))
			{
				// Calculate the texel to be copied for the current point
				double u = alpha * u_A + beta * u_B + gamma * u_C;
				double v = alpha * (1 - v_A) + beta * (1 - v_B) + gamma * (1 - v_C);
				int i = u * texWidth;
				int j = v * texHeight;

				// Calculate the RGB values from the texels;
				int r = texels[i][j][0];
				int g = texels[i][j][1];
				int b = texels[i][j][2];
				int tx = 62;
				int ty = 65;

				// Write the RGB values to the file
				if ((x == tx + 2 || x == tx - 2 || y == ty + 2 || y == ty - 2) && (x > tx - 3 && x<tx + 3 && y>ty - 3 && y < ty + 3))
					oFile << "255" << endl << "0" << endl << "0" << endl;
				else
					oFile << r << endl << g << endl << b << endl;
			}
			else
			{
				// Write the RGB values to the file
				oFile << outerR << endl << outerG << endl << outerB << endl;
			}
		}
	}
	cout << " Successfully generated the PPM file" << endl;
}

// Function to generate the output file with ppm format
ofstream PPMGenerator::CreateOutputFile(string filename, long height, long width)
{
	// Create a output file with the ppm format
	ofstream oFile(filename);

	// Write the header into the output file
	oFile << "P3" << endl;
	oFile << "# Creator " << endl;
	oFile << width << " " << height << endl;
	oFile << "255" << endl;

	// Return the file
	return oFile;
}
