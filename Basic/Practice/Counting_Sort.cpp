#include<iostream>
using namespace std;

int *A = NULL;

void csort(int *A, int n, int k)
{
	
	int i;
	int C[k];
	int B[n];

	for(i = 1; i <= k; i++)
		C[i] = 0;
	
	for(i = 1; i <= n; i++)
		C[A[i]]++;
		
	for(i = 2; i <= k; i++)
		C[i] += C[i - 1];
		
	for(i = n; i >= 1; i--)
	{
		B[C[A[i]]] = A[i];
		C[A[i]] -= 1;
	}
	
	for(i = 1; i <= n; i++)
		A[i] = B[i];
}

int main()
{
	int n, k = -1;
	int i;
	cout << "\n\tEnter the no. of elements: ";
	cin >> n;
	
	A = new int[n];
	cout << "\n\tEnter "<< n <<" elements( >= 0 ): ";
	for(i = 1; i <= n; i++)
	{
		cin >> A[i];
		if((A[i] > k))
			k = A[i];
	}
	
	csort(A, n, k);
	
	cout << "\n\tSorted Array: ";
	for(i = 1; i <= n; i++)
		cout << A[i] << ' ';
		
	return 0;
}
