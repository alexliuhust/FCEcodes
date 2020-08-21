// Name: Zehua Liu
// ID: 001086969

#include<iostream>
#include <random>
using namespace std;

void PrX(int A[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j >= i; j--)
		{
			if (A[j] < A[j - 1])
			{
				int k = 0;
				k = A[j];
				A[j] = A[j - 1];
				A[j - 1] = k;
			}
		}
	}
}

int main()
{
	cout << "Please input the size n: \n";
	int n;
	cin >> n;

	int* A = new int[n];
	random_device rd;                    // Will be used to obtain a seed for the random number engine
	mt19937 gen(rd());                   // Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(1, 100);     // Get random number from 1 to 100
	for (int i = 0; i < n; i++)
	{
		A[i] = dis(gen);         // Assign each element of A with a random number
	}
	cout << "A is: \n";
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << "\t";   // Output the sorted array A
		if ((i + 1) % 10 == 0)
			cout << "\n";        // After outputting every 10 elements, get a new line
	}
	cout << "\n";

	PrX(A, n);
	cout << "The sorted array A is:\n";
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << "\t";   // Output the sorted array A
		if ((i + 1) % 10 == 0)
			cout << "\n";        // After outputting every 10 elements, get a new line
	}
	cout << "\n";
	delete A;

	return 0;
}