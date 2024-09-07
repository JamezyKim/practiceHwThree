#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char** sort_strings(const char* A[], int n);
int* insertion_sort(int* arr, int n);

//Sort string
bool multipleElementsSort_stringReturnResult();
//Insertion sort
bool multipleElementsInsertion_sortReturnEqualArray();
bool singleElementInsertion_sortReturnEqualArray();
bool negativeElementInsertion_sortReturnEqualArray();
bool duplicateElementInsertion_sortReturnEqualArray();

typedef struct {
	int elements[100];
	int size;
}set_t;

int main() {

	//Insertion sort
	printf("multipleElementsInsertion_sortReturnEqualArray: %d\n", multipleElementsInsertion_sortReturnEqualArray());
	printf("singleElementInsertion_sortReturnEqualArray: %d\n", singleElementInsertion_sortReturnEqualArray());
	printf("negativeElementInsertion_sortReturnEqualArray: %d\n", negativeElementInsertion_sortReturnEqualArray());
	printf("duplicateElementInsertion_sortReturnEqualArray: %d\n", duplicateElementInsertion_sortReturnEqualArray());

	//Sort string
	printf("multipleElementsSort_stringReturnResult: %d", multipleElementsSort_stringReturnResult());

	return 0;
}

set_t* set_create_empty() {
	set_t* newNode = (set_t*)malloc(sizeof(set_t));
	if (newNode == NULL) {
		return NULL;
	}
	newNode->size = 0;

	return newNode;
}

int set_size(set_t* A) {
	if (A == NULL) {
		return;
	}

	int result = A->size;

	return result;
}

void set_insert(set_t* A, int x) {

	if (A == NULL) {
		return;
	}
	if (A->size >= 100) {
		return;
	}

	for (int i = 0; i < A->size; i++) {
		if (A->elements[i] == x) {
			return;
		}
	}

	A->elements[A->size] = x;
	A->size++;

	return;
}

void set_remove(set_t* A, int x) {

	for (int i = 0; i < A->size; i++) {
		if (A->elements[i] == x) {
			for (int j = i; j < A->size - 1; j++) {
				A->elements[j] = A->elements[j + 1];
			}
			A->size = A->size - 1;
			return;
		}
	}
}

bool set_contains(set_t* A, int x) {

	for (int i = 0; i < A->size; i++) {
		if (A->elements[i] == x) {
			return true;
		}
	}
	return false;

}

int set_map(set_t* A, int (*f)(int)) {
	int counter = 0;
	for (int i = 0; i < A->size; i++) {
		A->elements[i] = f(A->elements[i]);

		for (int j = 0; j < i; j++) {
			if (A->elements[j] == A->elements[i]) {
				set_remove(A, A->elements[i]);
				i--;
				break;
			}
		}
		counter++;
	}
	return counter;
}

void set_free(set_t* A) {

	A->size = 0;

	return;
}

int find(int* A, int n, bool (*pred)(int)) {

	for (int i = 0; i < n; i++) {
		if (pred(A[i]) == true) {
			return i;
		}
	}
	return -1;
}

int count(int* A, int n, bool (*pred)(int)) {
	int counter = 0;
	for (int i = 0; i < n; i++) {
		if (pred(A[i]) == true) {
			counter++;
		}
	}
	return counter;
}

void map(int* A, int n, int (*f)(int)) {

	for (int i = 0; i < n; i++) {
		A[i] = f(A[i]);
	}

	return;
}

int reduce(int* A, int n, int (*f)(int, int)) {
	int accumulator = A[0];

	if (n == 0) {
		return 0;
	}

	for (int i = 1; i < n; i++) {
		accumulator = f(accumulator, A[i]);
	}

	return accumulator;
}

int* insertion_sort(int* arr, int num) {
	int temp;
	int alter;

	if (num <= 1) {
		return arr;
	}

	for (int i = 0; i < num; i++) {
		alter = 0;
		temp = arr[i];

		for (int j = i; j > 0; j--) {
			if (arr[j] < arr[j - 1]) {
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				alter++;
			}
		}


		//printf("Insert %d: ", temp);

		//printf(": %d swaps\n", alter);
	}

	return arr;
}

void print(const char* A[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%s ", A[i]);
	}
}



char** sort_strings(const char* A[], int n) {

	const char* temp;
	char** result = (char**)malloc(sizeof(char*));

	if (n <= 1) {
		return NULL;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strlen(A[i]) > strlen(A[j])) {
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;

			}
			else {
				if (strcmp(A[i], A[j]) > 0 && strlen(A[i]) >= strlen(A[j])) {
					temp = A[i];
					A[i] = A[j];
					A[j] = temp;

				}
			}
		}

	}
	for (int i = 0; i < n; i++) {
		result[i] = A[i];
	}
	//print(A, n);



	return result;
}

bool duplicateElementInsertion_sortReturnEqualArray() {
	//arrange
	int arr[] = { 9,-1,8,8,-5,7 };
	int num = 6;
	int* actualResult = insertion_sort(arr, num);
	//act
	int expectedResult[] = { -5,-1,7,8,8,9 };

	//assert
	for (int i = 0; i < num; i++) {
		if (actualResult[i] != expectedResult[i]) {
			return false;
		}
	}
	return true;
}

bool negativeElementInsertion_sortReturnEqualArray() {
	//arrange
	int arr[] = { 9,-1,8,-5,7 };
	int num = 5;
	int* actualResult = insertion_sort(arr, num);
	//act
	int expectedResult[] = { -5,-1,7,8,9 };

	//assert
	for (int i = 0; i < num; i++) {
		if (actualResult[i] != expectedResult[i]) {
			return false;
		}
	}
	return true;
}

bool singleElementInsertion_sortReturnEqualArray() {
	//arrange
	int arr[] = { 9 };
	int num = 1;
	int* actualResult = insertion_sort(arr, num);
	//act
	int expectedResult[] = { 9 };

	//assert
	for (int i = 0; i < num; i++) {
		if (actualResult[i] != expectedResult[i]) {
			return false;
		}
	}
	return true;
}

bool multipleElementsInsertion_sortReturnEqualArray() {
	//arrange
	int arr[] = { 4, 3, 6, 1, 2, 5 };
	int num = 6;
	int* actualResult = insertion_sort(arr, num);
	//act
	int expectedResult[] = { 1,2,3,4,5,6 };

	//assert
	for (int i = 0; i < num; i++) {
		if (actualResult[i] != expectedResult[i]) {
			return false;
		}
	}
	return true;
}

bool multipleElementsSort_stringReturnResult() {
	//arrange
	const char* A[] = { "Wx", "ab", "Zde", "6_@7h", "7", "hij", "hhh", "b" };
	int n = 8;
	char** actualResult = sort_strings(A, n);

	//act
	char* expectedResult[] = { "7","b","Wx","ab","Zde","hij","hhh","6_@7h" };

	//assert
	for (int i = 0; i < n; i++) {
		if (actualResult[i] != expectedResult[i]) {
			return false;
		}
	}

	return;
}