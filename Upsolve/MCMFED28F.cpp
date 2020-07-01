#include<bits/stdc++.h>
#define pll pair<long long, long long>
#define pb push_back

using namespace std;

const int N=52;

struct MinCostFlow{
    /*  Runtime: ToDo 
        Usage: MinCostFlow mcmf(totalNodes);
        mcmf.addEdge(u, v, capacity, cost); // directed edge
        auto ans = mcmf.getMinCostFlow(source, sink); // <flow, cost>
    */
    struct Edge{
        int u, v;
        long long cap, cost;

        Edge(int _u, int _v, long long _cap, long long _cost){
            u = _u; v = _v; cap = _cap; cost = _cost;
        }
    };

    int n, s, t;
    long long flow, cost;
    vector<vector<int> > graph;
    vector<Edge> e;
    vector<long long> dist;
    vector<int> parent;

    MinCostFlow(int _n){
        // 0-based indexing
        n = _n;
        graph.assign(n, vector<int> ());
    }

    void addEdge(int u, int v, long long cap, long long cost, bool directed = true){
        graph[u].push_back(e.size());
        e.push_back(Edge(u, v, cap, cost));

        graph[v].push_back(e.size());
        e.push_back(Edge(v, u, 0, -cost));

        if(!directed)
            addEdge(v, u, cap, cost, true);
    }

    pair<long long, long long> getMinCostFlow(int _s, int _t){
        s = _s; t = _t;
        flow = 0, cost = 0;

        while(SPFA()){
            flow += sendFlow(t, 1LL<<62);
        }

        return make_pair(flow, cost);
    }

    // not sure about negative cycle
    bool SPFA(){
        parent.assign(n, -1);
        dist.assign(n, 1LL<<62);        dist[s] = 0;
        vector<int> queuetime(n, 0);    queuetime[s] = 1;
        vector<bool> inqueue(n, 0);     inqueue[s] = true;
        queue<int> q;                   q.push(s);
        bool negativecycle = false;


        while(!q.empty() && !negativecycle){
            int u = q.front(); q.pop(); inqueue[u] = false;

            for(int i = 0; i < graph[u].size(); i++){
                int eIdx = graph[u][i];
                int v = e[eIdx].v, w = e[eIdx].cost, cap = e[eIdx].cap;

                if(dist[u] + w < dist[v] && cap > 0){
                    dist[v] = dist[u] + w;
                    parent[v] = eIdx;

                    if(!inqueue[v]){
                        q.push(v);
                        queuetime[v]++;
                        inqueue[v] = true;

                        if(queuetime[v] == n+2){
                            negativecycle = true;
                            break;
                        }
                    }
                }
            }
        }

        return dist[t] != (1LL<<62);
    }

    long long sendFlow(int v, long long curFlow){
        if(parent[v] == -1)
            return curFlow;
        int eIdx = parent[v];
        int u = e[eIdx].u, w = e[eIdx].cost;

        long long f = sendFlow(u, min(curFlow, e[eIdx].cap));

        cost += f*w;
        e[eIdx].cap -= f;
        e[eIdx^1].cap += f;

        return f;
    }
};

int n, q;
set<int> st[N];

int main()
{
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			st[i].insert(j);
		}
	}
	for(int i = 1; i <= q; i++)
	{
		int t, l, r, v;
		cin >> t >> l >> r >> v;
		if(t==1)
		{
			for(int j = 1; j < v; j++)
			{
				for(int k = l; k <= r; k++)
				{
					st[j].erase(k);
				}
			}
		}
		else
		{
			for(int j = v+1; j <= n; j++)
			{
				for(int k = l; k <= r; k++)
				{
					st[j].erase(k);
				}
			}
		}
	}
	MinCostFlow mcmf(2*n+3);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			mcmf.addEdge(1, 2*i, 1, 2*j-1);
		}
		for(auto it: st[i])
		{
			mcmf.addEdge(2*i, 2*it+1, 1, 0);
		}
		mcmf.addEdge(2*i+1, 2*n+2, 1, 0);
	}
	pll ans = mcmf.getMinCostFlow(1, 2*n+2);
	if(ans.first!=n)
	{
		cout << -1;
	}
	else cout << ans.second;
}
