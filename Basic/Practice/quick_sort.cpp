#include<iostream>
using namespace std;

int Partition(int *A, int p, int q)						//Partitioning Subroutine
{
	int x = A[p];										//Pivot
	int temp;
	int i = p, j;
	for(j = i + 1; j <= q; j++)
	{
		if(A[j] <= x)
		{
			i++;
			temp = A[j];
			A[j] = A[i];
			A[i] = temp;
		}
	}
	A[p] = A[i];
	A[i] = x;
	
	return i;
}

void Quicksort(int *A, int p, int q)
{
	int r = Partition(A, p, q);
	if(p < q)
	{
		Quicksort(A, p, r-1);
		Quicksort(A, r+1, q);
	}
}

int main()
{
	int m;
	int *A;
	cout << "\tEnter the number of elements: ";
	cin >> m;
	
	A = new int[m];
	
	cout<<"\n\tEnter the elements in the array: ";
	for(int i = 0; i < m; i++)
		cin >> A[i];
	
	Quicksort(A, 0, m-1);
	
	
	cout << "\n\tSorted array: \n\t\t";
	for(int i = 0; i < m; i++)
		cout << A[i] << ' ';
		
	return 0;
}
