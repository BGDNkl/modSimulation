#include <iostream>
#include <fstream>
#include <iomanip>
#define size 5000

using namespace std;

int main()
{
	unsigned long a = 13,
		c = 130,
		m = 9979;

	long X[size];
	double Y[size];

	double y_suma = 0,
		y2_suma = 0,
		y3_suma = 0;

	// Rozklad rownomierny: //////////////////////////////////
	X[0] = 3;
	
	for (int i = 1; i < size; i++)
		X[i] = (a * X[i - 1] + c) % m;

	for (int i = 0; i < size; i++)
	{
		Y[i] = (static_cast<double>(X[i]) / m);

		y_suma += Y[i];
		y2_suma += Y[i] * Y[i];
		y3_suma += Y[i] * Y[i] * Y[i];
	}

	// y, y^2 itd: ///////////////////////////////////////////

	cout << "y  : " << y_suma / size << endl;
	cout << "y^2: " << y2_suma / size << endl;
	cout << "y^3: " << y3_suma / size << endl;


	// Test CHI^2 ////////////////////////////////////////////
	cout << "\n Chi kwadrat (1): \n";

	short k = 10;
	double X_2 = 0;
	double d = 1.0 / k;
	int N_teor = size / k;
	int L[10] = { 0 };

	// wypelniamy:
	for (int i = 0; i < size; i++)
	{
		int j = int(Y[i] / d);
		L[j]++;
	}

	// wyswietlamy:
	for (int i = 0; i < 10; i++)
	{
		cout << "[" << i + 1 << "] - " << L[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < k; i++)
	{
		X_2 += pow(L[i] - N_teor, 2.0) / N_teor;
	}

	cout << "X^2" << " = " << X_2 / k << endl;

	// Test CHI^2 dwuwymiarowy ///////////////////////////////

	cout << "\n Chi kwadrat (2): \n";

	long double X_22 = 0;
	double N_teor2 = N_teor / 2;
	int LL[10][10] = { 0 };

	// wypelniamy:
	for (int i = 0; i < size - 1; i += 2)
	{
		int j1 = int(Y[i] / 0.1);
		int j2 = int(Y[i + 1] / 0.1);
		LL[j1][j2]++;
	}

	// wyswetlamy:

	std::ofstream file("CHI2_out.txt");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << LL[i][j] << " ";
			file << LL[i][j] << " ";
		}
		cout << endl;
		file << endl;
	}
	file.close();

	// x^2
	cout << endl;
	for (int j = 0; j < 10; j++)
	{
		for (int k = 0; k < 10; k++)
		{
			X_22 += pow(LL[j][k] - N_teor2, 2.0) / N_teor2;
		}
	}

	cout << "X^2" << " = " << X_22 << endl;

	return 0;
}