#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(double* p, int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		p[i] = Low + rand() * (High - Low * 1.) / RAND_MAX;
}

void Print(double* p, int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(10) << p[i];
	cout << endl;
}

int Count(double* p, int size)
{
	int j = 0;
	double C = 0;
	for (int i = 0; i < size; i++)
		if (p[i] < C)
			j++;
	return j;
}

int Minus(double* p, int size)
 {
	int l = -1;
	for (int i = 0; i <= size - 1; i++)
	{
		if (p[i] < 0)
		{
			l = i;
		}	
	}
		return l;
}

int Sum(double* p, int size)
{
	int S = 0;
	int l = Minus(p, size);
	if (l >= 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (i > l)
				S += (p[i] / 1);
		}
		return S;
	}
	else
		return 0;
}

double Max(double* p, const int size)
{
	double max = p[0];
	for (int k = 1; k < size; k++)
		if (p[k] > max)
			max = p[k];
	return max;
}

void Sort(double* p, double* f, const int size)
{
	int l = 0;
	double max = Max(p, size);
	for (int i = 0; i < size; i++)
	{
		if (p[i] >= max * 0.8)
		{
			f[l] = p[i];
			l++;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (p[i] < max * 0.8)
		{
			f[l] = p[i];
			l++;
		}
	}
}
int main()
{
	cout << fixed << setprecision(3) << endl;

	srand((unsigned)time(NULL));

	int k;
	cout << "k = "; cin >> k;
	double* p = new double[k];
	double* f = new double[k];

	double C;

	int Low;
	cout << "Low = "; cin >> Low;
	int High;
	cout << "High = "; cin >> High;

	Create(p, k, Low, High);
	Print(p, k);
	cout << endl;

	cout << "Calculating count" << endl;
	cout << endl;
	cout << "C = "; cin >> C;
	cout << "j = " << Count(p, k) << endl;
	cout << endl;

	cout << "Calculatin Sum" << endl;
	cout << endl;
	int q = Minus(p, k);
	if (q >= 0)
		cout << "Last minus " << q << endl;
	else
		cout << "No minus " << endl;
	cout << "S = " << Sum(p, k) << endl;
	cout << endl;

	cout << "Relocated elements" << endl;
	cout << endl;
	cout << "Max =" << Max(p, k) << endl;
	Sort(p, f, k);
	Print(f, k);

	delete[] p;
	delete[] f;
	
	system("pause");
	return 0;
}
