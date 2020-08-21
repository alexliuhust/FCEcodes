#include<iostream>
using namespace std;

int h1(int key)
{
	int x = (key + 5) * (key + 5);
	x /= 16;
	x += key;
	x %= 11;
	return x;
}

void main()
{
	int A[12] = {43, 23, 1, 0, 15, 31, 4, 7, 11, 3, 5, 9};
	int X[12] = {};
	for (int i = 0; i < 12; i++)
	{
		X[i] = h1(A[i]);
	}
	for (int i = 0; i < 12; i++)
	{
		cout << X[i] << "\t";
	}
	cout << "\n";
}