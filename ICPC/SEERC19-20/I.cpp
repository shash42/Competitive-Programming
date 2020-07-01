#include <bits/stdc++.h>

using namespace std ;

const int N = 1002 ;
int a[N], b[N] ;
bool usedA[N], usedB[N] ; 

multiset < int > A, B, mapped, bCopy ;
int n ;

int main()
{
	cin >> n ;
	for(int i  = 0; i < n; i++) {
		cin >> a[i] ;
		A.insert(a[i]);
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i] ;
		B.insert(b[i]);
	}

	// memset(usedA, 0, sizeof(usedA)); memset(usedB, 0, sizeof(usedB));

	/*
	for(int cnt = 1; cnt < n; cnt++)
	{
		int minDif = 2e9, mxDif = -1e9, num = -1, dif ;


		minDif = 1e9 ; 
		for(int q : A)
		{
			dif = 1e9 ;
			auto high = B.upper_bound(q);
			auto low = B.upper_bound(q);
			if(low != B.begin()) {
			    advance(low, -1);
			    dif = min(dif, abs(*low - q));
			}
			if(high != B.end())
				dif = min(dif, abs(*high - 	q));

			if(dif < minDif) minDif = dif, num = q ;
			cout << dif << " : " << minDif << endl ; 
		}
		A.erase(A.find(num));
		cout << num << "   " ;

		mxDif = -1e9 ; 
		for(int p : B)
		{
			dif = max(abs(p - *A.begin()), abs(p - *A.rbegin()) ) ;
			if(dif > mxDif) mxDif = dif, num = p ; 
		}
		B.erase(B.find(num));
		
		cout << num << endl ; 
	}
	*/



	for(int cnt = 1; cnt < n; cnt++)
	{
		int minDif = 2e9, mxDif = -1e9, num = 0, dif ;

		num = *A.begin() ; 
		minDif = 1e9 ; 
		for(int q : A)
		{
			dif = 1e9 ;
			auto high = B.upper_bound(q);
			auto low = B.upper_bound(q);
			if(low != B.begin()) {
			    advance(low, -1);
			    dif = min(dif, abs(*low - q));
			}
			if(high != B.end())
				dif = min(dif, abs(*high - 	q));

			if(dif < minDif) minDif = dif, num = q ;
			// cout << dif << " : " << minDif << endl ; 
		}
		A.erase(A.find(num));
		//   cout << num << " " ;

		mapped.clear();
		bCopy.clear();

		for(int z : B) bCopy.insert(z);

		mxDif = -1e9 ; 
		for(int q : A)
		{
			dif = 1e9 ; int best = 0 ; 
			auto high = B.upper_bound(q);
			auto low = B.upper_bound(q);
			if(low != B.begin()) {
			    advance(low, -1);
			    if(abs(*low - q) < dif)
			    	best = *low, dif = abs(*low - q);
			}
			if(high != B.end())
			    if(abs(*high - q) < dif)
			    	best = *high, dif = abs(*high - q);

			mapped.insert(best);
		}
		// cout << "ODIDNDIN\n" ; 
		for(int p : mapped) if(bCopy.find(p) != bCopy.end()) bCopy.erase(bCopy.find(p));
			// cout << "YODODDD \n\n" ; 
		B.erase(B.find(*bCopy.begin()));
		
		// cout << *bCopy.begin() << endl ; 
	}

	/*
	for(int cnt = 1; cnt < n; cnt++)
	{
		int minDif = 2e9, mxDif = -1e9, num = -1, dif ;
		for(int p : A)
		{
			dif = max(abs(p - *B.begin()), abs(p - *B.rbegin()) ) ;
			if(dif < minDif) minDif = dif, num = p ; 
		}
		A.erase(A.find(num));
		cout << num << "   " ;
		mxDif = -1e9 ; 
		for(int q : B)
		{
			dif = 1e9 ;
			auto high = A.upper_bound(q);
			auto low = A.upper_bound(q);
			if(low != A.begin()) {
			    advance(low, -1);
			    dif = min(dif, abs(*low - q));
			}
			if(high != A.end())
				dif = min(dif, abs(*high - 	q));

			if(dif > mxDif) mxDif = dif, num = q ;
		}
		B.erase(B.find(num));

		cout << num << endl ; 
	}
	*/

	int ans = abs(*A.begin() - *B.begin());
	cout << ans ; 
}
/*
5
1 50 54 55 55
53 101 102 102 104 
5
10 20 30 40 50
11 18 30 43 47
5
1 2 3 4 100
4 5 6 7 1000
*/