#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#define size 500

using namespace std;

int main()
{
	unsigned long a = 13,
		c = 130,
		m = 9979;

	long X[size];
	double Y[size];

	// Rozklad: //////////////////////////////////////////////
	X[0] = 3;

	for (int i = 1; i < size; i++)
		X[i] = (a * X[i - 1] + c) % m;

	for (int i = 0; i < size; i++)
		Y[i] = (static_cast<double>(X[i]) / m);

	// Klasy: ////////////////////////////////////////////////
	short K = 10;
	double X_2 = 0;
	double d = 1.0 / K;
	int N_teor = size / K;
	int lf[size] = { 0 };

	// wypelniamy:
	for (int i = 0; i < size; i++)
	{
		lf[i] = int(Y[i] / d);
	}

	cout << endl << "Liczba graczy: " << size / 5 << endl;

	//int tab[1000][1];
	//int a, b, c, d, e;
	int P_teor, k;
	int sprawdzone[5] = { 0 };

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << lf[j+i] << "   ";
			
			/////
			
			set<int> mySet;
			mySet.insert(lf[j + i]);
			int dist = std::distance(mySet.begin(), mySet.end());
			//int local_size = mySet.size();
			
			//switch (dist)
			//{
			//	case 1:	
			//	{
			//		k = 5;
			//		P_teor = (k - 1.0)(k - 2)(k - 3)(k - 4) / pow(k,4);		
			//	}
			//	case 2:	
			//	{ 
			//		k = 4;
			//		P_teor = 10 * ((k - 1)(k - 2)(k - 3)) / pow(k, 4);
			//	}
			//	case 3:	
			//	{
			//		k = 3;
			//		P_teor = 10 * ((k-1)(k-2)) / pow(k, 4);
			//	}
			//	case 4:					
			//	{
			//		k = 2;
			//		P_teor = 10 * ((k-1)) / pow(k, 4);
			//		
			//	/*	for (int ii = 0; ii < 5; ii++)
			//		{
			//			for (int jj = 0; jj < 5; jj++)
			//			{
			//				if (ii != jj)
			//					lf[ii] == lf[jj]; sprawdzone[ii]++;
			//			}
			//		}*/
			//	}
			//	case 5:					
			//	{ 
			//		k = 2;
			//		P_teor = 5 * (k - 1) / pow(k, 4);

			//		//for (int ii = 0; ii < 5; ii++)
			//		//{
			//		//	for (int jj = 0; jj < 5; jj++)
			//		//	{
			//		//		if (ii != jj)
			//		//			lf[ii] == lf[jj]; sprawdzone[ii]++;
			//		//	}
			//		//}
			//	}
			//	case 6: 
			//	{
			//		k = 1;
			//		P_teor = 1 / pow(k, 4);
			//	}
			//	default:
			//		cout << "blad\n";
			//}

			/////
		}
		i += 4;
		cout << endl;
	}

	// next step: //////////////////////////////////////////////


	return 0;
}