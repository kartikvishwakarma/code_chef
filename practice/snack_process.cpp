#include <iostream>

using namespace std;

bool snacks(char str[], int n){

	char curr = 'H';

	for(int i=0; i<n; i++){
		if(str[i] != '.'){
			if(curr=='T' && str[i]=='T')
				curr = 'H';
			else if(curr=='H' && str[i] == 'H')
				curr = 'T';
			
			else 
				return false;
			/*else 
				return false;*/
		}
	}

	if(curr == 'T')
		return false;
	
	return true;
}

int main(){
	int t,n;
	cin>>t;

	while(t--){
		cin>>n;
		char str[n];

		for(int i=0; i<n; i++)
			cin>>str[i];

		bool ans = snacks(str, n);

		cout<<(ans?"Valid\n":"Invalid\n");
	}
}