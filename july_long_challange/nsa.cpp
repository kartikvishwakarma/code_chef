#include <iostream>
#include <string>

using namespace std;

int main(){
	int t,i,min;
	string str, str1,str2;
	cin>>t;

	while(t--){
		cin>>str;

		int str_len = str.length(); 
		str1=str;

		min=100000000;
		for(i=0; i<str_len; i++){
			for(int j=97; j<=122; j++){
				str[i]= char(j);
				for(int k=0; k<str_len ; k++){
					int count=0;
					for(int l=k+1; l<str_len; l++){
						if(str_k<str_l)
							count++;
					}

					count=count+ abs( int(str1[i]-int(str[i])) );

					if(count<min)
						min=count;
				}
			}
		}
		cout<<min<<"\n";
	}
}
			

