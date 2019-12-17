#define N 200005
#define lgN 20
#define INF 2147483647

struct Node{
	int to,w;
};
vector<Node> v[N];
int p[N][lgN],mx[N][lgN],in[N],out[N],t;
//out[0] = INF
void DFS(int now,int fa,int val){
	in[now] = ++t;
	p[now][0] = fa;
	mx[now][0] = val;
	for(int i = 1 ; i < lgN ; i++){
		p[now][i] = p[p[now][i-1]][i-1];
		mx[now][i] = max(mx[now][i-1],mx[p[now][i-1]][i-1]);
	}
	for(auto i : v[now]){
		if(i.to != fa)DFS(i.to,now,i.w);
	}
	out[now] = t;
}

bool isfa(int a,int b){return in[a] <= in[b] && out[a] >= out[b];}
int LCA(int a,int b){
	if(isfa(b,a))return b;
	if(isfa(a,b))return a;
	for(int i = lgN-1 ; i >= 0 ; i--){
		if(!isfa(p[a][i],b))a = p[a][i];
	}
	return p[a][0];
}
int getmx(int a,int b){
// b is a's ancestor
	if(a == b)return -INF;
	int tmp = -INF;
	for(int i = lgN-1 ; i >= 0 ; i--){
		if(!isfa(p[a][i],b)){
			tmp = max(mx[a][i],tmp);
			a = p[a][i];
		}
	}
	return max(tmp,mx[a][0]);
}

