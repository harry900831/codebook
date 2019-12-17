#define N 100005

pair<int,int> E[N];
vector< pair<int,int> > v[N]; //{to,id}
bitset<N> vis;
int low[N];
int depth[N];
int bridge[N];

void DFS(int now,int fa,int t){
	vis[now] = 1;
	depth[now] = t;
	low[now] = t;
	for(auto i : v[now]){
		if(vis[i.F]){
			if(i.F != fa)low[now] = min(low[now],low[i.F]);
		}
		else {
			DFS(i.F,now,t+1);
			low[now] = min(low[now],low[i.F]);
			if(low[i.F] > depth[now])bridge[i.S] = 1;
		}
	}
}

