// Name: Zehua Liu
// ID: 001086969
// The accepted inputs are as follow:
// 23h, 23a, 24, 26, 28, 30, 38, 41, 42, 43, 50, 52, 57, 59, 60

#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

void Initialize(string label[14]) { // The labels represent the real codenames of the buildings
									// The indexes are the recoded vertices in the weight matrix
	label[0] = "23h";
	label[1] = "23a";
	label[2] = "26";
	label[3] = "24";
	label[4] = "28";
	label[5] = "30";
	label[6] = "60";
	label[7] = "38";
	label[8] = "57";
	label[9] = "41";
	label[10] = "59";
	label[11] = "50";
	label[12] = "52";
	label[13] = "43";
	label[14] = "42";
}

void Dijkstra(int** W, int R[], int num, int start, int end) {
	bool* vis = new bool[num];  // Mark whether a vertix is visited
	int* dis = new int[num];    // Store the shortest distance of every vertices from the start point 
	int INF = 1000000;          // The virtual infinity
	for (int i = 0; i < num; i++) { // Initialize the visiting status and the distances
		vis[i] = false;
		dis[i] = INF;
	}
	dis[start] = 0;     // The distance between start and itself is always 0
	
	for (int i = 0; i < num; i++) {
		int u = -1;
		int min = INF;
	
		for (int j = 0; j < num; j++) {
			// Once a vertix has not been visited yet 
			// and the distance is smaller than the last smallest mark, visit it
			if (vis[j] == false && dis[j] < min) {  
				u = j;
				min = dis[j];  // The latest smallest mark
			}
		}

		if (u == -1) return;  // If we cannot find any other afjacent vertices, the function is done
		vis[u] = true;        // Mark the vertices visited
		for (int v = 0; v < num; v++) {
			// Find the vertix has shortest distance from the pre-visited one
			if (vis[v] == false && dis[u] + W[u][v] < dis[v]) {
				dis[v] = dis[u] + W[u][v];
				R[v] = u;    // Store the information into the route index array
			}
			
		}

	}
	cout << "The distance is: " << dis[end] << "\n"; // Output the distance

	delete[] vis;
	delete[] dis;
}

int main() {
	ifstream inf;
	int count = 0;
	int x;
	int maxint = 97;
	int* list = new int[maxint];
	inf.open("data.txt");
	if (inf.fail()) { 
		cerr << "Error: Could not open input file\n";
		exit(1); 
	} //activate the exception handling of inf stream
	inf.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	while (count < maxint) {
		//keep reading until reading maxints or                 
		//until a reading failure is caught.    
		try {
			inf >> x;
		}//Check for reading failure due to end of file or     
		 // due to reading a non‐integer value from the file.    
		catch (std::ifstream::failure e) {
			break;
		}
		list[count++] = x;
	}
	inf.close();//Close the file at the end of your program.    
	
	int num = list[0]; // The amount of the vertices
	int** W = new int* [num]; // The weight matrix for the vertices
	for (int i = 0; i < num; i++) {
		W[i] = new int[num];
	}
	// Initialize the weight matrix
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			W[i][j] = 1000000;
		}
	} 
	count = 1;

	// Since the graph is undirected, we may consider it as between every two vertices
	// there are both back and forth arrows, with equal weight
	while (count < maxint) {
		int x = list[count];
		int y = list[count + 1];
		int value = list[count + 2];
		W[x][y] = value;
		W[y][x] = value;
		count += 3;
	} 
	int* R = new int[30]; // The route index array used for store the route index
	for (int i = 0; i < 30; i++) { // Initialization
		R[i] = -1;
	}

	int start = 0;
	int end = 0;
	string* label = new string[15];   // The real codenames of the buildings
	Initialize(label);
	string Start;          // The real codenames of the start point
	string End;            // The real codenames of the end point
	cout << "Please input the START point\n";
	cout << "The accepted inputs are as follow:\n";
	cout << "23h, 23a, 24, 26, 28, 30, 38, 41, 42, 43, 50, 52, 57, 59, 60\n";
	cin >> Start;
	cout << "Please input the END point\n";
	cout << "The accepted inputs are as follow:\n";
	cout << "23h, 23a, 24, 26, 28, 30, 38, 41, 42, 43, 50, 52, 57, 59, 60\n";
	cin >> End;
	// Get the index of the start point
	for (int i = 0; i < num; i++) {
		if (Start.compare(label[i]) == 0) {
			start = i;
			break;
		}
	}
	// Get the index of the end point
	for (int i = 0; i < num; i++) {
		if (End.compare(label[i]) == 0) {
			end = i;
			break;
		}
	}
    
	Dijkstra(W, R, num, start, end);  // Execute Dijkstra's algorithm

	string* Route = new string[10];   // The real route array that store the real name of the buildings
	int p = end;
	Route[0] = label[end];
	count = 1;
	// Map back the indexes to the real code names
	while (R[p] != -1) {
		Route[count] = label[R[p]];
		count++;
		p = R[p];
	}

	// The raw route starts from the end and the end is the start
	// So, output the route in reverse order
	for (int i = 6; i >= 0; i--) {
		if (!Route[i].empty()) {
			cout << " -> " << Route[i];
		}
	}
	
	delete[] list;
	for (int i = 0; i < num; i++) {
		delete[] W[i];
	}
	delete[] W;
	delete[] R;
	delete[] label;
	delete[] Route;
}