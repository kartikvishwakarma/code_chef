#include <iostream>

using namespace std;

void merge(int A[], int l, int m, int r){
	int p1 = m-l+1;
	int p2 = r-m;

	int A1[p1];
	int A2[p2];

	for(int i=0; i<p1; i++){
		A1[i] = A[l+i];
	}

	for(int j=0; j<p2; j++){
		A2[j] = A[m+1+j];
	}

	int i=0; int j=0; int k=l;

	while(i<p1 && j<p2){
		if(A1[i]<=A2[j]){
			A[k] = A1[i];
			i++;
		}
		else{
			A[k] = A2[j];
			j++;
		}
		k++;
	}

	while(i<p1){
		A[k]=A1[i];
		i++;
		k++;
	}

	while(j<p2){
		A[k]=A2[j];
		j++;
		k++;
	}
}

void mergeSort(int A[], int l, int r){
	if(l<r){
		int m = l + (r-l)/2;

		mergeSort(A,l,m);
		mergeSort(A,m+1, r);

		merge(A, l, m, r);
	}
}

void show(int A[], int n){
	for(int i=0; i<n; i++)
		cout<<A[i]<<" ";
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int A[] = {4,1,6,2,8,4,3};
	int n = sizeof(A)/sizeof(A[0]);
	show(A, n);
	mergeSort(A, 0, n-1);
	show(A,n);
	return 0;
}