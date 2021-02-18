#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

#define size 100

using namespace std;

int main()
{
	float x, A, D, Fmax, xl, yl;

	Fmax = 2 / 3;
	A = 1 / 324;
	
	// odwr dystr
	cout << "\nOdwr dystr:\n";

	ofstream file1("file1.txt");
	for (int i = 0; i < size; i++)
	{
		D = (float(rand()) / RAND_MAX);
		x = (-3) + (6 * pow(D, 0.25));
		cout  << x << endl;
		file1 << x << endl;
	}
	file1.close();
	
	// metod elim
	cout << "\nMetoda elim:\n";

	ofstream file2("file2.txt");
	for (int i = 0; i < size; i++)
	{
		D = (float(rand()) / RAND_MAX);
		xl = (6 * D - 3);
		yl = Fmax * D;

		if (yl <= (A * pow((x + 3), 3.0)))
		{
			cout  << xl << endl;
			file2 << xl << endl;
		}
	}
	file2.close();

	return 0;
}