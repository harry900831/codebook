#define N 100005

struct president_tree{
#define M ((l+r)>>1)
	int tot;
	struct Node{
		int l,r,val;
		Node(){
			l = r = val = 0;
		}
	}node[30*N];
	president_tree(){tot = 0;}
	void build(int l,int r,int &now){
		now = tot++;
		node[now] = Node();
		if(l == r)return;
		build(l,M,node[l].l);
		build(M+1,r,node[r].r);
	}
	void modify(int l,int r,int k,int pre,int &now){
		now = tot++;
		node[now] = node[pre];
		node[now].val++;
		if(l == r && l == k)return;
		if(k <= M)modify(l,M,k,node[pre].l,node[now].l);
		else modify(M+1,r,k,node[pre].r,node[now].r);
	}
	int query(int l,int r,int k,int pre,int now){
		if(l == r)return l;
		int sum = node[node[now].l].val-node[node[pre].l].val;
		if(sum >= k)return query(l,M,k,node[pre].l,node[now].l);
		return query(M+1,r,k-sum,node[pre].r,node[now].r);
	}	
#undef M
}preseg = PRESEG();
int root[N];


