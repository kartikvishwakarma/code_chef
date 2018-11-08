#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &A) {
    int n = A.size();
    int res=0,i;
    
    res = (A[n-1]+1)/10;
    
    A[n-1] = (A[n-1]+1)%10;
    i=n-2;
    while(res && i>=0){
    	//cout<<A[i];
        res = (A[i]+1)/10;
        A[i] = (A[i]+1)%10;
        i--;
    }

    if(i<0 && res)
    	A.push_back(res);        
    return A;        
}


int main(){
	vector<int> A = {9,9,9,9};
	int n = A.size();
	A = plusOne(A);
	if(A.size()>n)
		cout<<A[n];
	for(int i=0; i<n; i++)
		cout<<A[i];
	cout<<"\n";

}