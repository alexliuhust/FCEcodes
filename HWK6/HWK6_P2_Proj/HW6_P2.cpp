// Zehua Liu
// 001086969

#include <iostream>
#include<cmath>
#include<time.h>

using namespace std;

int cut(int p[], int n) {
	if (n == 0) return 0;
	int q = -1;  // Make sure the initial value is the smallest one
	// Compare the current value with any other subdivided cuts
	for (int i = 1; i <= n; i++) {
		int x = p[i] + cut(p, n - i);
		if (q < x) q = x;
	}
	return q;
}
int dyn(int p[], int n, int R[]) {
	if (n == 0) return 0;
	// If there is already a max value for a certain cut, take it as the curren result
	// element with value -1 is not been stored yet
	if (R[n] != -1) return R[n];
	int q = -1; // Make sure the initial value is the smallest one
	// Compare the current value with any other subdivided cuts
	for (int i = 1; i <= n; i++) {
		int x = p[i] + dyn(p, n - i,R);
		if (q < x) q = x;
	}
	// Update the result storage
	R[n] = q;
	return q;
}

int main() {
	cout << "Please input the length n (5 <= n <= 50): \n";
	int n; // Get the length
	cin >> n;
	int* p = new int[n + 1];
	// Generate the price array for certain length
	p[0] = 0;
	p[1] = 2;
	p[n] = (int)(n * 2.5 - 1);  // The whole rod's price is (n * 2.5 - 1)
	for (int i = 2; i <= n - 1; i++) {
		p[i] = floor(i * 2.5);
	}
	// The storage of the dynamic result
	int* R = new int[n + 1];
	// Initialize the storage
	for (int i = 0; i <= n; i++) {
		R[i] = -1;
	}

	int result;
	clock_t start, end;

	start = clock();
	result = dyn(p, n, R);  // Call the dynamic programming
	end = clock();
	cout << "Time cost for dynamic programming: ";
	cout << (double)(end - start) / CLOCKS_PER_SEC * 1000000 << " us" << endl;  // calculate the time cost
	cout << "The max revenue is: " << result << "\n";

	start = clock();
	result = cut(p, n); // Call the pure recursion function
	end = clock();
	cout << "Time cost for pure recursion: ";
	cout << (double)(end - start) / CLOCKS_PER_SEC * 1000000 << " us" << endl; // calculate the time cost
	cout << "The max revenue is: " << result << "\n";

	delete[] R;
	delete[] p;
}