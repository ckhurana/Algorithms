#include<iostream>
using namespace std;

void merge(int *A, int a, int mid, int b)
{
	int x = mid - a + 1, y = b - mid;
	int *L = new int[x];
	int *R = new int[y];
	
	for(int i = 0; i < x; i++)
		L[i] = A[a + i];
	for(int i = 0; i < y; i++)
		R[i] = A[mid + 1 + i];
	
	/*	DEBUGGING
	cout<<"\n\nTEST\n";
	
	cout<<"\nx = "<<x;
	cout<<"\ny = "<<y<<endl;
	
	
	for(int i = 0; i < x; i++)
		cout<<L[i]<<' ';
	cout<<"\n";
	for(int i = 0; i < y; i++)
		cout<<R[i]<<' ';	
	*/
	
	int i = 0, j = 0, k = a;
	while(i < x && j < y)
	{
		if(L[i] <= R[j])
			A[k++] = L[i++];
		else
			A[k++] = R[j++];
	}
	
	while(i < x)
	{
		A[k++] = L[i++];
	}
	
	while(j < y)
	{
		A[k++] = R[j++];
	}
}

void mergeSort(int *A, int a, int b)
{
	int mid = (a + b) / 2;
	if(a < b)
	{
		mergeSort(A, a, mid);
		mergeSort(A, mid+1, b);
		merge(A, a, mid, b);
	}
}

int main()
{
	int n;										//Size of the array
	cout<<"Enter desired size of array: ";
	cin>>n;
	int *A = new int[n];
	
	cout<<"\nEnter "<<n<<" elements: ";
	for(int i = 0; i < n; i++)
		cin>>A[i];
		
	mergeSort(A, 0, n-1);
	
	cout<<"\nSorted Array: ";
	for(int i = 0; i < n; i++)
		cout<<A[i]<<' ';
	
	return 0;
}
