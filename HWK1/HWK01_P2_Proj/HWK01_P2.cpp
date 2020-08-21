// Name: Zehua Liu
// ID: 001086969

#include<iostream>
using namespace std;

int F1(int n)  // Define function F1, used to calculate 2^n
{
	if (n == 0) return 1;          // 2^0 = 1
	return F1(n-1) + F1(n - 1);  // Iteration: 2^n = 2^(n-1) + 2^(n-1)
}

int F2(int n)  // Define function F2, used to calculate 2^n
{
	if (n == 0) return 1;          // 2^0 = 1
	if (n % 2 == 0) {
		int result = F2(n / 2);    
		return result * result;    // If n is even, 2^n = [2^(n/2)]^2
	}
	else
		return 2 * F2(n - 1);     // If n is odd, 2^n = 2 * 2^(n-1)
}

int main()
{
		cout << "Please input n: ";           // Enter the index
		int n;
		cin >> n;
		// Call F1 and F2 respectively
		cout << "F1(n) = " << F1(n) << "\n"; 
		cout << "F2(n) = " << F2(n) << "\n";
}