#include<bits/stdc++.h>

using namespace std;

double var[11];
signed main()
{
    cout << fixed;
    cout << setprecision(2);
    for(int i = 1; i <= 11; i++)
    {
        cin >> var[i];
    }
    for(int i = 11; i >= 1; i--)
    {
        double ares = sqrt(abs(var[i]));
        double bres = pow(var[i], 3.0)*5.0;
        double res = ares + bres;
        if(res > 400)
        {
            cout << "f(" << (int) var[i] << ") = " << "MAGNA NIMIS!"<< endl;
        }
        else cout << "f(" << (int) var[i] << ") = " << res << endl;
    }
}