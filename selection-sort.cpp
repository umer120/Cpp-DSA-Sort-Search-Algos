#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	const int N = 10;
	int A[10] = { 24, 17, 45, 98, 100, 67, 55, 31, 88, 2 };

	cout << "Array A before sorting is: \n";
	for (int i = 0; i < N; i++){
		cout << A[i] << " ";
	}

	int smallSub = 0;
	for (int i = 0; i < N; i++){
		smallSub = i;
		for (int j = i + 1; j < N; j++){
			if (A[j] < A[smallSub]){
				smallSub = j;
			}
		}
		swap(A[i], A[smallSub]);
	}

	cout << "\n\nSorted Array A is: \n";
	for (int i = 0; i < N; i++){
		cout << A[i] << " ";
	}

	return 0;
}