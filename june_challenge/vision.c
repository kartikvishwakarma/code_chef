#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>

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

	scanf("%d", &T);

	while(T--){
		scanf("%lld %lld %lld", &Px, &Py, &Pz);
		scanf("%lld %lld %lld", &Qx, &Qy, &Qz);
		scanf("%lld %lld %lld", &dx, &dy, &dz);
		scanf("%lld %lld %lld %lld", &cx, &cy, &cz, &r);

		
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

		//printf("%lld %lld %lld %lld %lld %lld\n", const1,const2,const3,const4,const5,const6);
		/* 
		ll alpha = bz*(ky-kx) + by*(kx-kz) + bx*(kz-ky);
		ll beta = bz*(dy-dx) + by*(dx-dz) + bx*(dz-dy);

		ll a = beta*beta - (r*r)*(dx*dx + dy*dy + dz*dz);
		ll b = 2*(alpha*beta - (r*r)*(kx*dx + ky*dy + kz*dz));
		ll c = (alpha*alpha) - (r*r)*(kx*kx + ky*ky + kz*kz);

		if (a == 0)
			t = -(double)b/c;
		else{
			double t1 = ( -b + sqrt(b*b - 4*a*c) ) / (double)(2*a);
			double t2 = ( -b - sqrt(b*b - 4*a*c) ) / (double)(2*a);

			//printf("%.10lf  %.10lf\n", t1, t2);

			if (t1<0)
				t = t2;
			else if(t2 < 0)
				t = t1;
			else if(t1>t2)
				t = t2;
			else if(t2>t1)
				t = t1;
		}

		printf("%.10lf\n", t);
		}
		*/

		ll X = (r*r*const6 - const1*const6 + const3*const3);
		ll Y = 2*(r*r*const5 - const5*const1 + const2*const3);
		ll Z = (r*r*const4 - const1*const4 + const2*const2);
		X = 2; Y=0; Z=4;
		//printf("%lld %lld %lld\n",X,Y,Z);
		if (X==0)
			t = -(long double)Z/Y;
		else if(Y==0)
			t = sqrt(-(long double)Z/X);
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
		printf("%.12llf\n", t);
	}
	return 0;
}