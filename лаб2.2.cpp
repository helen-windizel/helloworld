#include <iostream>
#include <cstdlib>
#include <cmath>
 
using namespace std;
 
int partition(int * A, int left, int right)
{
    int k = left + rand() % (right - left + 1);
    int pivot = A[k];
 
    int i = left;
    int j = right;
 
    while (i <= j) {
        while (A[i] < pivot) i++;
        while (A[j] > pivot) j--;
        if (i >= j) break;
        swap(A[i++], A[j--]);
    }
 
    return j;
}
 
void quicksort(int * A, int left, int right)
{
    if (left < right) {
        int q = partition(A, left, right);
        quicksort(A, left, q);
        quicksort(A, q + 1, right);
    }
}
 
int main()
{
    int A[] = {10, 8, 6, 4, 9, 7, 1, 5, 3};
    quicksort(A, 0, 8);
 
    for (int i = 0; i <= 8; i++) cout << A[i] << " ";
 
    return 0;
}