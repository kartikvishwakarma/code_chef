#include <cstdio>

//using namespace std;

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void heapify(int a[], int n, int i){
	int ele = i;
	int l = 2*i+1;
	int r = 2*i+2;
	
	if(l<n && a[l]>a[ele]){
		ele = l;
		//heapify(a,n,l);
	}
	
	if(r<n && a[r]>a[ele]){
		ele = r;
		//heapify(a,n,r);
	}

	if(ele != i){
		swap(&a[i], &a[ele]);
		heapify(a,n,ele);
	}
}
/*
void heapify(int a[], int n, int i){
	int larg = i;
	int l = 2*i+1;
	int r = 2*i+2;

	if(l<n && a[l]>a[larg])
		larg = l;

	if(r<n && a[r]>a[larg])
		larg = r;

	if(larg != i){
		swap(&a[i], &a[larg]);
		heapify(a, n,larg);
	}
}
*/

void build_heap(int a[], int n){
	for(int i=n/2-1; i>=0; i--){
		heapify(a,n,i);
	}
}
/*
void heap_sort(int a[], int n){
	build_heap(a,n);

	for(int i=0;i<n;i++){
		int p = a[n-i-1];
		a[n-i-1] = a[0];
		a[0] = p;
		heapify(a,n-i-1,0);
		//build_heap(a,n-i-1);

	}
}
*/
void show(int a[], int n){
	printf("\n");
	for(int i=0;i<n;i++)
		printf("%d ", a[i]);
	printf("\n");
}

void heap_sort(int a[], int n){
	build_heap(a,n);

	for(int i=n-1; i>=0; i--){
		swap(&a[0], &a[i]);
		heapify(a,i,0);
		show(a,i);
	}
}



int main(){
	int a[] = {2,5,3,2,2};
	//int a[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(a)/sizeof(a[0]);
	show(a,n);
	heap_sort(a,n);
	//build_heap(a,n);
	//show(a,n);
} 