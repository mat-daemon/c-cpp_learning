#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef void (*gen)(int*, int);
void generate_random(int*, int);
void generate_sorted(int*, int);
void generate_sorted_reverse(int*, int);
void generate_almost_sorted(int*, int);
void generate_almost_sorted_reverse(int*, int);
void insertionSort(int*, int);
void printArray(int*, int);
double timetest (int*, int, gen);




void generate_random(int* arr, int n) {
	//	You can experiment with the modulo value.
	//	The bigger number the less duplicates in the array.
	for(int i = 0; i < n; ++i) arr[i] = rand() % 1000000;
}

void generate_sorted(int* arr, int n) {
	for(int i = 0; i < n; ++i) arr[i] = i;
}

void generate_sorted_reverse(int* arr, int n) {
	for(int i = 0; i < n; ++i) arr[i] = n - i;
}

void generate_almost_sorted(int* arr, int n) {
	//	initialize sorted array
	for(int i = 0; i < n; ++i) arr[i] = i;
	//	Make some swaps to disturb the order
	//	Experiment with different # of swaps
	for(int i = 0; i < 100; ++i) {
		int j = rand() % n;
		int k = rand() % n;
		while(j == k) k = rand() % n;
		swap(&arr[j], &arr[k]);
	}
}

void generate_almost_sorted_reverse(int* arr, int n) {
	//	initialize array sorted in reverse order
	for(int i = 0; i < n; ++i) arr[i] = n - i;
	//	Make some swaps to disturb the order
	//	Experiment with different # of swaps
	for(int i = 0; i < 100; ++i) {
		int j = rand() % n;
		int k = rand() % n;
		while(j == k) k = rand() % n;
		swap(&arr[j], &arr[k]);
	}
}

void insertionSort(int* arr, int n) {
	for(int i = 1; i < n; ++i) {
		int x = arr[i];
		int j = i - 1;
		while(j >= 0 && arr[j] > x) {
			arr[j+1] = arr[j];
			--j;
		}
		arr[j+1] = x;
	}
}

void printArray(int* arr, int n) {
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

double timetest (int* arr, int n, gen fgen) {

	clock_t t0, t1;
	fgen(arr, n);

	//	Wait for clock() roll over before starting
	t0 = clock();
	while (t0 == (t1 = clock()));

	t0 = t1;
	quickSort(arr, 0, n);
	t1 = clock();

	return (t1 - t0) * (1.0 / CLOCKS_PER_SEC);
}



void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[100000];
    printf("%.12f" ,timetest(arr, 100000, generate_almost_sorted_reverse));

}
