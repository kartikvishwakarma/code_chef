#include <cstdio>

using namespace std;

typedef long long int ll;

int main(){
    int T,N;
    ll sum,K;

    scanf("%d", &T);

    while(T--){
        scanf("%d %lld", &N, &K);

        sum = (N*(N+1))/2 - 1;

        if(K == sum){
            for(int i=1; i<=N;i++){
                printf("%d ", i);
            }
            printf("\n");
        }
        else {

            ll diff = K - sum;

            if(diff <0)
                printf("-1\n");
            else {
                int swap_i, swap_j;
                bool out=false;

                for(int i=2; i<=N;i++){
                    
                    if (i+diff > N){
                        out = true;
                        printf("-1\n");
                        break;      
                    }
                    if(i+diff <=N){
                        swap_i = i;
                        swap_j = i+diff;
                        break;
                    }
                }

                if(!out){

                    bool flag = false;

                    for(int i=1; i<=N; i++){
                        if(i != 1 && i == swap_i){
                            printf("%d %d ", swap_j, i);
                            flag = true;
                        }
                        else if(flag && i == swap_j)
                            continue;
                        else printf("%d ", i);
                    }
                    printf("\n");
                }
            }
        }

    }
    return 0;
}