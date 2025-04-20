#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Student {
private:
	int regNo;
	float CGPA;

public:
	Student(){}

	Student(int regNo, float CGPA) : regNo(regNo), CGPA(CGPA) {}

	int getRegNo() const {
		return regNo;
	}

	float getCGPA() const {
		return CGPA;
	}

	int linearSearch(float key, int size) const {
		for (int i = 0; i < size; ++i) {
			if (CGPA == key) {
				return i;
			}
		}
		return -1; 
	}

	int binarySearch(float key, int size) const {
		int low = 0;
		int high = size - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (CGPA == key) {
				return mid;
			}
			else if (CGPA < key) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		return -1;
	}
};

int main() {
	const int numStudents = 10;
	Student students[numStudents];

	for (int i = 0; i < numStudents; ++i) {
		int regNo = rand() % 10000; 
		float CGPA = static_cast<float>(rand()) / RAND_MAX * 4.0f; 
		students[i] = Student(regNo, CGPA);
	}

	sort(students, students + numStudents, [](const Student& a, const Student& b) {
		return a.getCGPA() < b.getCGPA();
	});

	float key = 3.0f; 
	int linearIndex = students[0].linearSearch(key, numStudents);
	int binaryIndex = students[0].binarySearch(key, numStudents);

	if (linearIndex != -1) {
		cout << "Linear search: Found at index " << linearIndex << endl;
	}
	else {
		cout << "Linear search: Not found" << endl;
	}

	if (binaryIndex != -1) {
		cout << "Binary search: Found at index " << binaryIndex << endl;
	}
	else {
		cout << "Binary search: Not found" << endl;
	}

	return 0;
}
