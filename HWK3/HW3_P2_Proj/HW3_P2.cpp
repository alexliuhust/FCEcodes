#include<iostream>
#include<random>
using namespace std;

void generate(int B[])        // Generate the array B to store the random birthdays
{
	random_device rd;                    // Will be used to obtain a seed for the random number engine
	mt19937 gen(rd());                   // Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dismm(1, 12);     // Get random numbers from 1 to 12
	uniform_int_distribution<> disdd(1, 28);     // Get random numbers from 1 to 28
	uniform_int_distribution<> disyy(0, 4);     // Get random numbers from 0 to 4

	int* mm = new int[1000];
	int* dd = new int[1000];
	int* yy = new int[1000];
	for (int i = 0; i < 1000; i++)
	{
		mm[i] = dismm(gen);   // Random numbers from 1 to 12 for the months
		dd[i] = disdd(gen);       // Random numbers from 1 to 28 for the days
		yy[i] = disyy(gen);        // Random numbers from 0 to 4 for the years
	}
	for (int i = 0; i < 1000; i++)    
	{
		B[i] = mm[i] * 10000 + dd[i] * 100 + yy[i];     // This step is used for combining the 3 series of numbers into the format of mmddyy
	}
	delete[] mm;
	delete[] dd;
	delete[] yy;
}

void init(int A[], int m)         // Initialize the collision counter
{
	for (int i = 0; i < m; i++)    
	{
		A[i] = -1;   // Initialize the array with -1, because the collision numbers is the number of values - 1
	}
}

void count(int A[], int B[], int m)   // The collision counter
{
	init(A, m);
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// If a value from B[] is going to be inserted into count,
			// the counter for the corresponding place plus 1.
			if (((B[i] % m)) == j) 
			{
				A[j]++;
			}
		}
	}
}

int mini(int A[], int m)      // Calculate the minimum
{
	int min = A[0];
	for (int i = 1; i < m; i++)
	{
		if (min > A[i])     // If there is a number smaller than min, exchange them
			min = A[i];
	}
	if (min == -1)    // If the minimum is  -1, it means there are no values inserted in the place, so the collision number is also 0
		return 0;
	return min;
}

int maxi(int A[], int m)     // Calculate the maximum
{
	int max = A[0];
	for (int i = 1; i < m; i++)
	{
		if (max < A[i])     // If there is a number larger than max, exchange them
			max = A[i];
	}
	return max;
}

int mean(int A[], int m)   // Calculate the mean value
{
	int mean = 0;
	for (int i = 0; i < m; i++)    // First calculate the sum of the array
	{
		mean += A[i];
	}
	mean /= m;                      // Divide the sum by the length of the array to get the mean value
	return mean;
}

int var(int A[], int m)    // Calculate the variance
{
	int mean = 0;
	for (int i = 0; i < m; i++)   // First calculate the sum of the array
	{
		mean += A[i];
	}
	mean /= m;                       // Divide the sum by the length of the array to get the mean value
	int var = 0;
	for (int i = 0; i < m; i++)
	{
		var += (A[i] - mean) * (A[i] - mean);    // Calculate the sum of the squares
	}
	var /= (m - 1);               // Divide the sum of the squares by the (length - 1) to get the variance.
	return var;
}

void output(int A[], int m)
{	// Using a fixed format to output the analysis of the four hashtable
	cout << "For hashtable with size of " << m << ":\n";
	cout << "minimum: " << mini(A, m) << "\tmaximum: " << maxi(A, m) << "\n";
	cout << "mean: " << mean(A, m) << "\t\tvariance: " << var(A, m) << "\n\n";
}


int main()
{
	int* B = new int[1000];
	generate(B);                          // Generate the array B to store the random birthdays

	// counti is the counter array for the hashtable with the size of mi (i = 1, 2, 3, 4)
	int m1 = 97;
	int m2 = 98;
	int m3 = 100;
	int m4 = 101;
	int* count1 = new int[m1];
	int* count2 = new int[m2];
	int* count3 = new int[m3];
	int* count4 = new int[m4];

	// Call the count function to initialize the four counters and count the collision numbers, respectively
	count(count1, B, m1);
	count(count2, B, m2);
	count(count3, B, m3);
	count(count4, B, m4);

	// Call the output function to output the analysis of the four hashtable
	output(count1, m1);
	output(count2, m2);
	output(count3, m3);
	output(count4, m4);

	delete[] B;
	delete[] count1;
	delete[] count2;
	delete[] count3;
	delete[] count4;
}