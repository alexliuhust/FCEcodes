#include<iostream>
#include<fstream>
#include<stdexcept>
#include<chrono>

using namespace std;
// Set two global variables, moves and comps
int moves = 0;
int comps = 0;

// Insertionsort function
void insertion(int A[], int n) {
	for (int j = 1; j < n; j++)
	{
		int key = A[j];       // Store the number to be compared from the second one
		int i = j - 1;
		while ((i >= 0) && (A[i] >= key))
		{
			comps++;
			A[i + 1] = A[i];  // Move each element larger than key rightwards by one step
			moves++;
			i--;
		}
		comps++;
		A[i + 1] = key; // Fill the blank with the pre-stored number
		if (i + 1 != j) moves++; // One needs to check if the movement yields no actual position change
	}
}

int left(int i)    // Calculate the node of the left leaf of node i
{
	return (i + 1) * 2 - 1;
}
int right(int i)   // Calculate the node of the right leaf of node i
{
	return (i + 1) * 2;
}
void maxheapify(int A[], int i, int size)   // Maxheapify function
{
	int l = left(i);
	int r = right(i);
	int largest = 0;
	comps++;
	if (l <= size && A[l] > A[i])  // Check if the left leaf is larger than the parent. 
		largest = l;
	else
		largest = i;
	comps++;
	if (r <= size && A[r] > A[largest])  // Check if the right leaf is larger than the parent. 
		largest = r;
	if (largest != i)    //If the left or the right leaf is larger than their parent, exchange the larger leaf and the parent
	{
		int temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		moves += 3;          // When it comes to swap two elements, there are 3 movements
		maxheapify(A, largest, size);   // In case the maxheapify corrupts the rest, 
										// make sure every maxheapify execute all the way till the end
	}
}
void build(int A[], int n)    // Build the MAX-HEAP
{
	for (int i = (n / 2 - 1); i >= 0; i--)    // Do the maxheapify from the last non-leaf node all the way till the root
	{
		maxheapify(A, i, (n - 1));
	}
}
void heapsort(int A[], int n)    // Heapsort function
{
	build(A, n);
	int size = n - 1;        // At the beginning, the heap size is the size of the whole array
	for (int i = n - 1; i >= 1; i--)
	{
		int temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		moves += 3;               // There are no needs to check if the movement yields no actual position change, for i won't equal to 0 
		size = size - 1;          // Once the largest element is removed from the root, the heap size decrease by one
		maxheapify(A, 0, size);   // In case the removement corrupts the rest, make sure every maxheapify execute all the way till the end
	}
}

int partition(int A[], int p, int r)  // Partiton fuction, in order to find the pivot
{
	int x = A[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++)
	{
		comps++;
		if (A[j] <= x)                    // If there is a element smaller than the pivot, throw it leftwards
		{
			i++;
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			if (i != j) moves += 3;    // One needs to check if the movement yields no actual position change
		}
	}
	int temp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = temp;
	if ((i+1) != r) moves += 3;  // One needs to check if the movement yields no actual position change
	return i + 1;
}
void quicksorttemp(int A[], int p, int r)   // The REAL quick sort
{
	if (p < r)
	{
		int q = partition(A, p, r);          // Find the pivot
		quicksorttemp(A, p, q - 1);      // Sort the left half of the pivot
		quicksorttemp(A, q + 1, r);      // Sort the right halfof the pivot
	}
}
void quicksort(int A[], int n) {          // Make the operations for sorting the whole array easier
	quicksorttemp(A, 0, n - 1);
}

void test(int A[]) {                      // Verify that one array is sorted
	for (int i = 2; i < 1000; i++) {
        // Confirm that every element i in the array has a value less than or equal to the value  in element i+1 
		if (A[i] < A[i - 1]) {
			cout << "Problem\n";
			break;
		}
	}
	cout << "Successfully Sorted\n";
}

void AnalysisOfInsertion(int b[], int a[], int w[], int txt[]) {// Analyze insertion sort to get the moves and comps of this algorithm
	// Everytime when an array os to be sorted, reset the moves and the comps
	moves = 0;
	comps = 0;
	insertion(b, 1000);
	test(b);        // Verify that the array is sorted
	cout << "Insertion sort, best case:";
	cout << "\t" << moves << "\t" << comps << "\n";
	// Store the results into the txt array, which will be used in the sort.txt file
	txt[0] = moves;
	txt[9] = comps;
	moves = 0;
	comps = 0;
	insertion(a, 1000);
	test(a);
	cout << "Insertion sort, average case:";
	cout << "\t" << moves << "\t" << comps << "\n";
	txt[1] = moves;
	txt[10] = comps;
	moves = 0;
	comps = 0;
	insertion(w, 1000);
	test(w);
	cout << "Insertion sort, worst case:";
	cout << "\t" << moves << "\t" << comps << "\n";
	cout << "---------------------------------------\n";
	txt[2] = moves;
	txt[11] = comps;
}

void AnalysisOfHeap(int b[], int a[], int w[], int txt[]) {// Analyze heap sort to get the moves and comps of this algorithm
	moves = 0;
	comps = 0;
	heapsort(b, 1000);
	test(b);
	cout << "Heap sort, best case:";
	cout << "\t\t" << moves << "\t" << comps << "\n";
	txt[3] = moves;
	txt[12] = comps;
	moves = 0;
	comps = 0;
	heapsort(a, 1000);
	test(a);
	cout << "Heap sort, average case:";
	cout << "\t" << moves << "\t" << comps << "\n";
	txt[4] = moves;
	txt[13] = comps;
	moves = 0;
	comps = 0;
	heapsort(w, 1000);
	test(w);
	cout << "Heap sort, worst case:";
	cout << "\t\t" << moves << "\t" << comps << "\n";
	cout << "---------------------------------------\n";
	txt[5] = moves;
	txt[14] = comps;
}

void AnalysisOfQuick(int b[], int a[], int w[], int txt[]) {// Analyze quick sort to get the moves and comps of this algorithm
	moves = 0;
	comps = 0;
	quicksort(b, 1000);
	test(b);
	cout << "Quick sort, best case:";
	cout << "\t\t" << moves << "\t" << comps << "\n";
	txt[6] = moves;
	txt[15] = comps;
	moves = 0;
	comps = 0;
	quicksort(a, 1000);
	test(a);
	cout << "Quick sort, average case:";
	cout << "\t" << moves << "\t" << comps << "\n";
	txt[7] = moves;
	txt[16] = comps;
	moves = 0;
	comps = 0;
	quicksort(w, 1000);
	test(w);
	cout << "Quick sort, worst case:";
	cout << "\t\t" << moves << "\t" << comps << "\n";
	cout << "---------------------------------------\n";
	txt[8] = moves;
	txt[17] = comps;
}

int main() {   
	// The arrays, bst, avg, and wst, represent three cases,the best, average, and the worst case
    // These three arrays are the array source (still arrays) that will not be changed through the program
	int* bst = new int[1000];
	int* avg = new int[1000];
	int* wst = new int[1000];
	// Generate a sorted array for bst and a reverse array for the wst
	for (int i = 0; i < 1000; i++) {
		bst[i] = i;
		wst[i] = 1000 - i;
	}
	// Generate 1000 random numbers for the avg
	srand(time(NULL));
	for (int i = 0; i < 1000; i++) {
		avg[i] = rand() % 100000;
	}
	// The temporary arrays corresponding to the three still arrays
	int* b = new int[1000];
	int* a = new int[1000];
	int* w = new int[1000];
	// The txt array used to store the analysis results of the sorting algorithms
	int* txt = new int[18];
	
	// When one of the still arrays needs to be sorted, copy the elements from it to the corresponding temporary array
	for (int i = 0; i < 1000; i++) {
		b[i] = bst[i];
		a[i] = avg[i];
		w[i] = wst[i];
	}
	AnalysisOfInsertion(b, a, w, txt);

	for (int i = 0; i < 1000; i++) {
		b[i] = bst[i];
		a[i] = avg[i];
		w[i] = wst[i];
	}
	AnalysisOfHeap(b, a, w,txt);

	for (int i = 0; i < 1000; i++) {
		b[i] = bst[i];
		a[i] = avg[i];
		w[i] = wst[i];
	}
	AnalysisOfQuick(b, a, w,txt);

	ofstream outf;
    outf.open("sort.txt");
	if (outf.fail()) {
		cerr << "Error: Could not open output file\n";
		exit(1);
	}
	for (int i = 0; i < 18; i++) {                // Output the results in the sort.txt
		outf << txt[i] << "\t";
		if ((i+1) % 3 == 0) {
			outf << "\n";
		}
	}
	outf.close();    //Close the file at the end of the program

	delete[] bst;
	delete[] avg;
	delete[] wst;
	delete[] b;
	delete[] a;
	delete[] w;
	delete[] txt;
}