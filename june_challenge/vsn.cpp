#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	//printf("%d\n", INT_MAX);
	int T;
	ll Px, Py, Pz;
	ll Qx, Qy, Qz;
	ll Qx_t, Qy_t, Qz_t;
	ll dx, dy, dz;
	ll cx, cy, cz, r;
	ll kx, ky, kz;
	ll bx, by, bz;
	long double t;

	cin>>T;

	while(T--){
		cin>>Px>>Py>>Pz;
		cin>>Qx>>Qy>>Qz;
		cin>>dx>>dy>>dz;
		cin>>cx>>cy>>cz>>r;

		kx = Qx-Px;
		ky = Qy-Py;
		kz = Qz-Pz;

		bx = cx-Px;
		by = cy-Py;
		bz = cz-Pz;

		ll const1 = bx*bx + by*by + bz*bz;
		ll const2 = bx*kx + by*ky + bz*kz;
		ll const3 = bx*dx + by*dy + bz*dz;
		ll const4 = kx*kx + ky*ky + kz*kz;
		ll const5 = kx*dx + ky*dy + kz*dz;
		ll const6 = dx*dx + dy*dy + dz*dz;

		
		ll X = (r*r*const6 - const1*const6 + const3*const3);
		ll Y = 2*(r*r*const5 - const5*const1 + const2*const3);
		ll Z = (r*r*const4 - const1*const4 + const2*const2);

		//printf("%lld %lld %lld\n",X,Y,Z);
		if (X==0 && Y && Z)
			t = -(double)Z/Y;
		else if(X && Y==0 && Z)
			t = sqrt(-(long double)Z/X);
		else if(X && Y==0 && Z==0)
			t = 0;
		else if (X==0 && Y && Z==0)
			t = 0;
		else{
			long double t1 = (-Y + sqrt((Y*Y - 4*X*Z)) )/(2*X);
			long double t2 = (-Y - sqrt((Y*Y - 4*X*Z)) )/(2*X);

			if(t1<0)
				t = t2;
			else if(t2<0)
				t = t1;

			else if (t1>=t2)
				t = t2;
			else
				t = t1;
		
		}
		cout<<fixed<<setprecision(12)<<t<<"\n";
	}
	return 0;
}