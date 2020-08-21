// Name: Zehua Liu
// ID: 001086969
/* When testing the wrong input detection, 
   re-enter the current name and score and DON'T re-enter the WHOLE form */

#include<iostream>
using namespace std;

void insert(int A[], string B[], int n) // Define the insertion sort function
{
	for (int j = 1; j < n; j++)
	{
		/* Name and score binding operations:
		   Every time when there's an integer assignment, 
		   a corresponding string assignment follows */
		int key = A[j];       // Store the number to be compared from the second one
		string namekey = B[j];
		int i = j - 1;
		while ((i >= 0) && (A[i] <= key))
		{
			// Compare the number with every other number before it
			// and put it right after the largest one of them
			A[i + 1] = A[i];
			B[i + 1] = B[i];
			i--;
		}
		A[i + 1] = key; // Fill the blank with the pre-stored number
		B[i + 1] = namekey;
	}
}

int main()
{
	cout << "Please input the size of your class: ";
	int n;
	cin >> n;         // Get the size of the class
	cout << "\n";
	string* name = new string[n];     // Create the arry for the names
	int* score = new int[n];          // Create the arry for the scores
	
	cout << "Please input the names and the scores: \n";
	cout << "(Only enter students' last names as one word \n";
	cout << "All grades are integers that have to be in the range from 0 to 100(inclusive)\n";
	cout << "Enter one name first, then one score)\n\n";
	for (int i = 0; i < n; i++)
	{
		cin >> name[i];            // Get the names and the  scores and store them
		cin >> score[i];
		if (score[i] > 100 || score[i] < 0)     // Detect the wrong score input
		{
             cout << "Wrong input! Please re-enter the name and the score\n\n";
			 i--;
			 continue;  // If there's wrong input, re-run THIS loop
		}
	}                                   
	
	insert(score, name, n);             // Call the insertion sort function
	
	cout << "\nThe form of students' info: \n";
	for (int i = 0; i < n; i++)
	{
		cout << name[i] << "\t";
		cout << score[i] << "\n";
	}                                   // Output the sorted form
	delete[] name;
	delete[] score;
	return 0;
}