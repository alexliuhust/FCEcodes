#include<iostream>
#include <random>

using namespace std;

int left(int i)
{
	return (i + 1) * 2 - 1;
}

int right(int i)
{
	return (i + 1) * 2;
}

void maxheapify(int A[], int i, int size)
{
	int l = left(i);
	int r = right(i);
	int largest = 0;
	if (l<=size && A[l]>A[i])
		largest = l;
	else
		largest = i;
	if (r<=size && A[r]>A[largest])
		largest = r;
	if (largest != i)
	{
		int temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		maxheapify(A, largest, size);
	}
}

void build(int A[], int n)
{
	for (int i = (n / 2 - 1); i >= 0; i--)
	{
		maxheapify(A, i, (n - 1));
	}
}

void heapsort(int A[], int n)
{
	build(A, n);
	int size = n - 1;
	for (int i = n - 1; i >= 1; i--)
	{
		int temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		size = size - 1;
		maxheapify(A, 0, size);
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
	

	heapsort(A, n);
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