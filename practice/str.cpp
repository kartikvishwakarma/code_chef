    #include <cstdio>
     
    using namespace std;
     
    const int size = (int)1e6 + 5;
    int a[size],b[size];
     
    bool all9digit(int a[], int n){
    	for(int i=0; i<n;i++){
    		if(a[i] != 9)
    			return false;
    	}
    	return true;
    }
     
     
    void next_palindrom_util(int a[], int n){
    	int mid = n/2;
    	int i = mid-1;
    	int j = (n%2)?mid+1:mid;
     
    	bool isleftsmall = false;
     
    	while(i>=0 && a[i]==a[j]){
    		i--; j++;
    	}
     
    	if(i<0 || a[i] < a[j])
    		isleftsmall = true;
     
    	while(i>=0){
    		a[j++] = a[i--];
    	}
     
    	if(isleftsmall){
    		int carry = 1;
    		i = mid-1;
    		if(n%2){
    			j = mid+1;
    			a[mid]+=carry;
    			carry = a[mid]/10;
    			a[mid] = a[mid]%10;
    		}
    		else 
    			j = mid;
     
    		while(i>=0){
    			a[i] += carry;
    			carry = a[i]/10;
    			a[i] = a[i]%10;
    			a[j++] = a[i--]; 
    		}
    	}
    }
     
    void next_palindrom(int a[], int n){
    	if(all9digit(a,n)){
    		printf("1");
    		for(int i=1;i<n;i++)
    			printf("0");
    		printf("1\n");
    	}
     
    	else {
    		next_palindrom_util(a,n);
     
    		for(int i=0; i<n;i++)
    			printf("%d ", a[i]);
    		printf("\n");
    	}
     
    }
     
    int main(int argc, char const *argv[])
    {
    	/* code */
    	int T, K,N;
    	scanf("%d", &T);
     
    	while(T--){
    		scanf("%d", &K);
    		int i=0;
    		while(K){
    			a[i++] = K%10;
    			K=K/10;
    		}
    		N = i;
     
    		for(int i=0; i<N;i++){
    			b[N-i-1] = a[i];
    		}
     
    		next_palindrom(b,N);
     
     
    	}
     
    	return 0;
    } 

