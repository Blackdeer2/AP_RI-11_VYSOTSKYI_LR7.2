#include <iostream>
#include <iomanip>
using namespace std;

void Create(int** mas, const int rowCount, const const int  colCount, const int A, const int B, int i, int j) {
	mas[i][j] = A + rand() % (B - A + 1);

	if (j < colCount - 1) {
		Create(mas, rowCount, colCount, A, B, i, j + 1);
	}
	else {
		if (i < rowCount - 1) {
			Create(mas, rowCount, colCount, A, B, i + 1, 0);
		}
	}
}

void Print(int** mas, const int rowCount, const int  colCount, int i, int j) {
	cout << setw(4) << mas[i][j];

	if (j < colCount - 1) {
		Print(mas, rowCount, colCount, i, j + 1);
	}
	else {
		if (i < rowCount - 1) {
			cout << endl;
			Print(mas, rowCount, colCount, i + 1, 0);
		}
	}
}
void Trans(int** mas, const int rowCount, const int  colCount, int t, int i, int j, int& test) {

	t = mas[i][j];
	mas[i][j] = mas[j][i];
	mas[j][i] = t;
	test = mas[j][i];

	if (j < colCount - 1) {
		Trans(mas, rowCount, colCount, t, i, j + 1, test);
	}
	else {
		if (i < rowCount - 1) {
			Trans(mas, rowCount, colCount, t, i + 1, i+1, test);

		}
	}
}
int main()
{
	srand((unsigned)time(NULL));

	int n;
	cout << "n = "; cin >> n;
	int rowCount = n;
	int colCount = rowCount;

	int** T = new int* [rowCount];
	for (int i = 0; i < rowCount; i++) {
		T[i] = new int[colCount];
	}
	Create(T, rowCount, colCount, -17, 14, 0, 0);
	cout << "T =" << endl << "{ " << endl;
	Print(T, rowCount, colCount, 0, 0); cout << endl;
	cout << "             }" << endl;
	int test = 0;
	Trans(T, rowCount, colCount, 0, 0, 0, test);
	cout << "transponovane T = { " << endl;
	Print(T, rowCount, colCount, 0, 0); cout << endl;
	cout << "             }" << endl;
	cout << test;
	for (int i = 0; i < rowCount; i++)
		delete[]T[i];
	delete[]T;

	return 0;
}