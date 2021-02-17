#include <iostream>

using namespace std;

int main()
{
	unsigned long a = 4, c = 7, m = 1234, size = 100;

	unsigned long *X = new unsigned long[size];
	double *Y = new double[size];
	
	double y_suma = 0, y_suma2 = 0, y_suma3 = 0, y, y2, y3;

	// Rozklad rownomierny:
	cout << "Rozklad rownomierny:\n";
	
	X[0] = 0;
	Y[0] = 0;

	for (unsigned int i = 1; i < 100; i++)
	{ 
			X[i] = (a * X[i - 1] + c) % m;
			Y[i] = (static_cast<double>(X[i]) / m);
			cout << " X[" << i << "] = " << X[i] << " \t " << " Y[" << i << "] = " << Y[i] << endl;

			y_suma += Y[i];
			y_suma2 += Y[i] * Y[i];
			y_suma3 += Y[i] * Y[i] * Y[i];
	}

	// y, y^2 itd:
	cout << "\n y, y^2, y^3: \n\n";

	y = y_suma / size;
	cout << "y: " << y << endl;

	y2 = y_suma2 / size;
	cout << "y: " << y2 << endl;

	y3 = y_suma3 / size;
	cout << "y: " << y3 << endl;


	// Test Xa^2

	double d = 1.0 / 10;
	double *L = new double[size];


	delete[] X;
	delete[] Y;
	delete[] L;
	
	return 0;
}