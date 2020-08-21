// Name: Zehua Liu
// ID: 001086969

// Homework 02 Problem 1
#include<iostream>
#include<random>
using namespace std;

void merge(int A[], int p, int q, int r)
{
	// Get the length of the two halves
	int n1 = q - p + 1;
	int n2 = r - q;
	// Define 2 arrays for the 2 halves and reserve a place at the end for both
	int* L = new int[n1 + 1];
	int* R = new int[n2 + 1];
	for (int i = 0; i < n1; i++)
	{
		L[i] = A[p + i];
	}                // Store the elements into array L
	for (int j = 0; j < n2; j++)
	{
		R[j] = A[q + j + 1];
	}                // Store the elements into array R
	// Make sure when L or R is empty, the rest of the elements will be well assigned
	// Since the largest element is 100, 200 is larger than anyone
	L[n1] = 200;
	R[n2] = 200;
	// Initiate 2 different variables for L and R, respectively, because the operations on L and R are not fully sync
	int i = 0;
	int j = 0;
	for (int k = p; k <= r; k++)   // Define the sorting area: from p to r
	{
		if (L[i] < R[j])
		{
			A[k] = L[i];
			i++;
		}                     // If L[i] is smaller, A[k] = L[i]
		else
		{
			A[k] = R[j];
			j++;
		}                     // If R[j] is smaller, A[k] = R[j]
	}
}

void merge_sort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;       // Equally devide the array into 2 parts
		merge_sort(A, p, q);       // Sort the first half
		merge_sort(A, q + 1, r);   // Sort the second half
		merge(A, p, q, r);         // Merge the two parts
	}
}

int main()
{
	int n, p, r;
	while (1)
	{
		// Get the size of the array A
		cout << "Please input the size n (1 < n <= 50): \n";
		cin >> n;
		// Make sure that the size is larger than 1 and less than 51
		// Execute the loop until the input meets the requirements
		if (n > 1 && n <= 50)
			break;
		cout << "Error! n is too large or too small!\n";
	}
	p = 0;
	r = n - 1; 	// Make sure the sorting will be applied to the entire array
	int* A = new int[n];
	random_device rd;                    // Will be used to obtain a seed for the random number engine
	mt19937 gen(rd());                   // Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(1, 100);     // Get random number from 1 to 100
	for (int i = 0; i < n; i++)
	{
		A[i] = dis(gen);         // Assign each element of A with a random number
	}
	merge_sort(A, p, r);          // Call the merge sort function
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