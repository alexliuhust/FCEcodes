// Zehua Liu
// 001086969

#include <iostream>
#include<cmath>
#include<time.h>

using namespace std;

int Fibo(int n) {
	// F(0) = 0 and F(1) = 1 are the initial condictions for the Fibonacci sequence
	if (n == 0) return 0;
	if (n == 1) return 1;
	// Recursively calculate the F(n - 1) + F(n - 2) until n = 0 or n = 1;
	return Fibo(n - 1) + Fibo(n - 2);
}

int Dynamic(int n, int R[]) {
	// F(0) = 0 and F(1) = 1 are the initial condictions for the Fibonacci sequence
	if (n == 0) return 0;
	if (n == 1) return 1;
	// Look up the result storage
	// If there is already a calculated result, take it
	// Having the value -1 means there has been no result stored in this position yet
	if (R[n] != -1) return R[n]; 
	// If there is no calculated result, calculate it and store it into the storage
	else {
		R[n] = Dynamic(n - 1, R) + Dynamic(n - 2, R);
		return R[n];
	}
}

int main() {
	cout << "Please input the number n (0 <= n <= 40): \n";
	cout << "The sequence index start with 0, i.e. F(0) = 0 \n";
	int n;
	cin >> n;   // Get the index

	int* R = new int[n + 1]; // The global array storing the results
	for (int i = 0; i < n + 1; i++) {
		R[i] = -1;
	}  // Having the value -1 means there has been no result stored in this position yet
	int result;
	clock_t start, end;  

	start = clock();
	result = Fibo(n); // Call the pure recursion function
	end = clock();
	cout << "Time cost for pure recursion: ";
	cout << (double)(end - start) / CLOCKS_PER_SEC << " s" << endl; // calculate the time cost
	cout << "The result is: " << result << "\n";

	start = clock();
	result = Dynamic(n, R);  // Call the dynamic programming
	end = clock();
	cout << "Time cost for dynamic programming: "; 
	cout << (double)(end - start) / CLOCKS_PER_SEC << " s" << endl;  // calculate the time cost
	cout << "The result is: " << result << "\n";

	delete[] R;
}