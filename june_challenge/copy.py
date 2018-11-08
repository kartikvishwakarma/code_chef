def dot(a,b):
    r = a[0]*b[0] + a[1]*b[1] + a[2]*b[2]
    return r
for _ in range(int(input())):
    x1,y1,z1,x2,y2,z2,d1,d2,d3,c1,c2,c3,r = map(float,input().split())
    a = x2-x1
    b = y2-y1
    c = z2-z1
    k = x1-c1
    l = y1-c2
    m = z1-c3
    term1 = (r**2)*(d1**2) + (r**2)*(d2**2) + (r**2)*(d3**2)
    term2 = (d1*l - d2*k)**2 + (d2*m - d3*l)**2 + (d3*k - d1*m)**2
    A = term1 - term2
    term11 = 2*(r**2)*(a*d1 + b*d2 + c*d3)
    term22 = 2*((a*l-b*k)*(d1*l-d2*k) + (b*m-c*l)*(d2*m-d3*l) + (c*k-a*m)*(d3*k-d1*m))
    B = term11-term22
    ter1 = (r**2)*(a**2 + b**2 + c**2)
    ter2 = (a*l-b*k)**2 + (b*m-c*l)**2 + (c*k-a*m)**2
    C = ter1-ter2
    #print(A,B,C)
    if A==0:
        t = -1*C/B
        print(t)
        continue
    else:
        t1 = (-1*B + (B**2 - 4*A*C)**0.5)/2*A
        t2 = (-1*B - (B**2 - 4*A*C)**0.5)/2*A
        t=0
        if t1<0:
            t=t2
        elif t2<0:
            t=t1
        elif t1>=0 and t2>=0:
            t=min(t1,t2)
        print(t)

	

