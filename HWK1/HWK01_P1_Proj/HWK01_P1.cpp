// Name: Zehua Liu
// ID: 001086969

#include<iostream>
using namespace std;

void SwapP(int* x, int* y) { // Define the SwapP function
	int temp;                // Swap the pointers 
	temp = *x;
	*x = *y;
	*y = temp;
}

void SwapR(int& x, int& y) { // Define the SwapR function
	int temp;                // Swap the references
	temp = x;
	x = y;
	y = temp;
}

int main() {
	int a;                  // Define the two integers need to be swapped, a and b
	int b;
	// Get the input of a and b
	cout << "Please input a and b\na = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	SwapP(&a, &b);        // Call the SwapP function
	cout << "SwapP results: a = " << a << "," << "b = " << b << "\n\n";
	// Get the input of a and b 
	cout << "Please input a and b\na = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	SwapR(a, b);          // Call the SwapR function
	cout << "SwapR results: a = " << a << "," << "b = " << b << "\n";
	return 0;
}