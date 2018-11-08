    #include <iostream>
     
    using namespace std;
    typedef long int li;
     
    void lottery(li a[], int n, int k){
    	li len=0, max_len=0;
    	li sum=0;
    	int i;
    	for(i=0;i<n;i++){
    		if(sum+a[i] <=k){
    			sum+=a[i];
    			len++;
    		}
    		else if(sum!=0){
    			sum=sum-a[i-len]+a[i];
    		}
    		max_len = max(max_len,len);
    	}
    	cout<<max_len<<" "<<suml<<"\n";
    }

     
    int main(){
    	li t,n,k;
    	cin>>t;
     
    	while(t--){
    		cin>>n>>k;
    		li a[n];
    		for(int i=0;i<n;i++)
    			cin>>a[i];
     
    		lottery(a,n,k);
    	}
    }  