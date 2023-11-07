#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);
bool SearchMinEven(int** a, const int n, int& minEven);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -8;
	int High = 42;
	int rowCount = 8;
	int colCount = 7;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	Sort(a, rowCount, colCount);
	Print(a, rowCount, colCount);
	int S = 0;
	int k = 0;
	Calc(a, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(a, rowCount, colCount);
	int minEven;
	if (SearchMinEven(a, , minEven))
		cout << "min even = " << minEven << endl;
	else
		cout << "there are no even elements" << endl;

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
void Sort(int** a, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < rowCount - 1; i0++)
		for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
			if ((a[i1][0] < a[i1 + 1][0])
				||
				(a[i1][0] == a[i1 + 1][0] &&
					a[i1][1] < a[i1 + 1][1])
				||
				(a[i1][0] == a[i1 + 1][0] &&
					a[i1][1] == a[i1 + 1][1] &&
					a[i1][3] > a[i1 + 1][3]))
				Change(a, i1, i1 + 1, colCount);
}
void Change(int** a, const int row1, const int row2, const int colCount)
{
	int tmp;
	for (int j = 0; j < colCount; j++)
	{
		tmp = a[row1][j];
		a[row1][j] = a[row2][j];
		a[row2][j] = tmp;
	}
}
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (a[i][j] > 0 && !(a[i][j] % 2 == 0))
			{
				S += a[i][j];
				k++;
				a[i][j] = 0;
			}
}int MaxMin(int** a, const int rowCount, const int colCount)
{
	int* min = new int[rowCount];
	for (int i = 0; i < rowCount; i++)
	{
		min[i] = a[i][0];
		for (int j = 1; j < colCount; j++)
			if (a[i][j] < min[i])
				min[i] = a[i][j];
	}
	int max = min[0];
	for (int i = 1; i < rowCount; i++)
		if (min[i] > max)
			max = min[i];
	delete[] min;
	return max;
}
bool SearchMinEven(int** a, const int n, int& minEven)
{
	int j, k = -1;
	for (int i = 0; i < n; i++)
	{
		j = n - 1 - i;
		if (a[i][j] % 2 == 0)
		{
			k = i;
			minEven = a[i][j];
			break;
		}
	}

	if (k == -1)
		return false;
	for (int i = k + 1; i < n; i++)
	{
		j = n - 1 - i;
		if (a[i][j] % 2 == 0 && a[i][j] < minEven)
		{
			minEven = a[i][j];
		}
	}
	return true;
}