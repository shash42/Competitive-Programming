    #include<bits/stdc++.h>
     
    #define pb push_back
    #define f first
    #define s second
    #define lint long long
    #define int long long
    #define mp make_pair
     
    const int N=2e5+5, INF=3e18;
     
    using namespace std;
     
    int n, ans;
    struct teacher
    {
        int a, b, t;
    } t[N];
     
    struct tsrt
    {
        bool operator()(const teacher &t1, const teacher &t2)
        {
            return t1.t > t2.t;
        }
    };
    struct tasrt
    {
        bool operator()(const teacher &t1, const teacher &t2)
        {
            if(t1.a==t2.a) return t1.t < t2.t;
            return t1.a < t2.a;
        }
    };
     
    priority_queue< teacher, vector < teacher >, tsrt> pq;
     
    signed main()
    {
        ios_base::sync_with_stdio(false); cin.tie(0);
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> t[i].a >> t[i].b >> t[i].t;
        }
        sort(t, t+n, tasrt());
     
        int tptr=0, currtm=0;    
        while(true)
        {
            while(tptr < n && currtm >= t[tptr].a)
                {
                    pq.push(t[tptr]);
                    tptr++;
                }
            while(pq.size() && pq.top().b < currtm + pq.top().t)
            {
                pq.pop();   
            }
            if(pq.size()==0 && tptr<n)
            {
                pq.push(t[tptr]);
                currtm=t[tptr].a;
                tptr++;
            } 
            if(tptr==n && pq.size()==0) break;
            teacher curr = pq.top();
          //  cout << curr.b << " " << currtm << " - " << ans  << " " << tptr << endl;
            int take;
            if(tptr>=n || curr.b <= t[tptr].a)
            {
                take = (curr.b - currtm) / curr.t;
                currtm +=  take*curr.t;
                ans+=take;
              //  pq.pop();
            }
            else
            {
                take = (t[tptr].a - currtm - 1LL) / curr.t;
                currtm += take*curr.t;
                ans += take;
                int mn = INF;
                int tmpptr=tptr;
                if(currtm + curr.t > curr.b) continue;
                while(tmpptr<n && t[tmpptr].a <= currtm + curr.t)
                {
                //  cout << tptr << endl;
                    mn = min(t[tmpptr].a + t[tmpptr].t, mn);
             //       pq.push(t[tptr]);
                    tmpptr++;
                }
                if(mn < currtm + curr.t)
                {
                    currtm = mn;
                    ans++;
                }
                else
                {
                    currtm += curr.t;
                    ans++;
                }
            }
        }
        cout << ans;
    }