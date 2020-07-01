#include<bits/stdc++.h>

using namespace std;

bool flag=false;
int a, b, c, d, e, f, L, R;

bool check(int x1, int y1, int x2, int y2, int X, int Y)
{
	if(x1>X or x2 > X or y1 > Y or y2 > Y) return false;
	//if(X-x2 > x1 or Y-y2 > y1) return false;
	return true;
}

void outp(int s1, int s2, int s3)
{
	int ax = a, ay = 0, bx = 0, by = b, cx = 0, cy = 0, fx = L, fy = R;
	if(s1)
	{
		swap(ax, ay);
		swap(bx, by);
	}
	if(s3)
	{
		swap(fx, fy);
	}
	int dx=fx - d, dy = fy, ex = fx, ey = fy - e;
	if(s2)
	{
		dx = fx;
		dy = fy - d;
		ex = fx - e;
		ey = fy; 
	}
	cout << bx << " " << by << endl << ax << " " << ay << endl << cx << " " << cy << endl;
	cout << ex << " " << ey << endl << dx << " " << dy << endl << fx << " " << fy << endl;  
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		flag = false;
		cin >> a >> b >> c >> d >> e >> f >> L >> R;
		flag = check(a, b, d, e, L, R);
		if(flag)
		{
			outp(0, 0, 0);
			continue;
		}
		flag = check(a, b, d, e, R, L);
		if(flag)
		{
			outp(0, 0, 1);
			continue;
		}
		flag = check(a, b, e, d, L, R);
		if(flag)
		{
			outp(0, 1, 0);
			continue;
		}
		flag = check(a, b, e, d, R, L);
		if(flag)
		{
			outp(0, 1, 1);
			continue;
		}
		flag = check(b, a, d, e, L, R);
		if(flag)
		{
			outp(1, 0, 0);
			continue;
		}
		flag = check(b, a, d, e, R, L);
		if(flag)
		{
			outp(1, 0, 1);
			continue;
		}
		flag = check(b, a, e, d, L, R);
		if(flag)
		{
			outp(1, 1, 0);
			continue;
		}
		flag = check(b, a, e, d, R, L);
		if(flag)
		{
			outp(1, 1, 1);
			continue;
		}
		cout << -1 << endl;
	}
}