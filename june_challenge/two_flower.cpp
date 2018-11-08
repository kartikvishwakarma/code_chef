#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include<iterator>
#include <iostream>
#include <algorithm>
using namespace std;

int m[2007][2007],t=2;

void region(int r,int c){
    
   m[r][c]=t;
    for(int i=r-1;i<=r+1;i++){
        for(int j=c-1;j<=c+1;j++){
            if((i != r-1 && j != c-1) && m[i][j]==1){
                m[i][j]=t;
                region(i,j);
                
            }
        }
    }
    
    return;
}
    
int main() { 
    int r,c;
    set<int> items;
    cin>>r>>c;
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
         cin>>m[i][j];
         items.insert(m[i][j]);
        }
	}
	

 	for(int p = 0; p<pair.size(); p++){
 	for(int i=0; i<r, i++){
 		for(int j=0; j<c;j++){
      		if(m[i][j]==1 ||m[i][j]==2)
          		 m[i][j]=1;
     		else
         		m[i][j]=0;
         }
    }
    
    
        
        for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
        if(m[i][j]==1){
        region(i,j);
           t++;
         }         
        }            
    }    
    int ar[t+1]={0};
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
        ar[m[i][j]]+=1;
    }
    int max=0;
    for(int i=1;i<=t;i++)
        max=fmax(max,ar[i]);
    
    }
    cout<<max<<"\n";
        
    return 0;
}