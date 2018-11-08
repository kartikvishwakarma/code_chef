    #include<bits/stdc++.h>
    using namespace std;
     
    typedef long long int lli;
    typedef vector< long long int> vi;
     
    vi subtract(vi a,vi b){
      vi ans;
      for(int i=0;i<3;++i){
        ans.push_back(a[i]-b[i]);
      }
      return ans;
    }
     
     
    lli dot(vi a,vi b){
      lli ans=0;
      for(int i=0;i<3;++i){
        ans+=a[i]*b[i];
      }
      return ans;
    }
     
     
    vi input(){
      lli x;
      vi a;
      for(int i=0;i<3;i++){
        cin>>x;
        a.push_back(x);
      }
      return a;
    }
     
     
    int main(){
      lli test;
      cin>>test;
     
      while(test--){
        //cout<<test<<"\n";
        vi p,q,d,c;
        lli r;
        lli cons1,cons2,cons3,cons4,cons5,cons6;
        vi cp,qp;
        p=input();
        q=input();
        d=input();
        c=input();
        cin>>r;
     
        cp=subtract(c,p);
        qp=subtract(q,p);
     
        cons1=dot(cp,cp);
        cons2=dot(cp,qp);
        cons3=dot(cp,d);
        cons4=dot(qp,qp);
        cons5=dot(qp,d);
        cons6=dot(d,d);
     
        long double X,Y,Z;
     
        X=(r*r*cons6-(cons1*cons6)+(cons3*cons3));
        Y=2*(r*r*cons5-(cons5*cons1)+(cons2*cons3));
        Z=(r*r*cons4-(cons1*cons4)+(cons2*cons2));
     
     
     
     
        long double t,t1,t2;
        
     
        if(X==0){
          t=(-1*Z)/Y;
          cout<<setprecision(12)<<t<<endl;
        }

        else if(X && Y==0 && Z){
          t = sqrt(-(long double)Z/X);
          cout<<setprecision(12)<<t<<endl;
        }

        else if(X && Y==0 && Z==0){
          t = 0;
          cout<<setprecision(12)<<t<<endl;
        }

        else if (X==0 && Y && Z==0){
          t = 0;
          cout<<setprecision(12)<<t<<endl;
        }
     
        else{
          t1=((-1*Y)+sqrt(Y*Y-(4*X*Z)) )/(2*X);
          t2=((-1*Y)-sqrt(Y*Y-(4*X*Z)))/(2*X);
          
          if(t1>=0 && t2<0)cout<<setprecision(12)<<t1<<endl;
          else if(t1<0 && t2>=0)cout<<setprecision(12)<<t2<<endl;
          else if(t1>=0 && t2>=0)cout<<setprecision(12)<<min(t1,t2)<<endl;
         
        }
     
      }
    return 0;
    }  