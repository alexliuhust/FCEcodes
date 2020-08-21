#include<iostream>
#include<random>

using namespace std;

int partition(int A[], int p, int r)
{
	int x = A[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++)
	{
		if (A[j] <= x)
		{
			i++;
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	int temp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = temp;
	return i + 1;
}

void quicksort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = partition(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);
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
		cout << A[i] << "\t";
		if ((i + 1) % 10 == 0)
			cout << "\n";
	}
	cout << "\n";

	int p = 0;
	int r = n - 1;
	quicksort(A, p, r);
	cout << "The sorted array A is:\n";
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << "\t";   // Output the sorted array A
		if ((i + 1) % 10 == 0)
			cout << "\n";        // After outputting every 10 elements, get a new line
	}
	cout << "\n";
	delete[] A;
}