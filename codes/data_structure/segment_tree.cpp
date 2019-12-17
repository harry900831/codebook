#define N 200005 
#define INF 2147483647
int a[N];

struct SEG{
#define m ((l+r)>>1)
	struct Node{
		int mx,tag;
		Node(){}
		Node(int val){
			mx = val;
			tag = 0;
		}
	}node[4*N];
	void pull(int id){
		node[id].mx = max(node[id<<1].mx,node[id<<1|1].mx);
	}
	void push(int id){
		int tmp = node[id].tag;
		if(tmp == 0)return;
		node[id].tag = 0;
		node[id<<1].mx += tmp;
		node[id<<1].tag += tmp;
		node[id<<1|1].mx += tmp;
		node[id<<1|1].tag += tmp;
	}
	void build(int l,int r,int id){
		if(l == r){
			node[id] = Node(a[l]);
			return;
		}
		build(l,m,id<<1);
		build(m+1,r,id<<1|1);
		pull(id);
	}
	void modify(int l,int r,int ll,int rr,int val,int id){
		if(r < ll || l > rr)return;
		if(l != r)push(id);
		if(l >= ll && r <= rr){
			node[id].mx += val;
			node[id].tag += val;
			return;
		}
		modify(l,m,ll,rr,val,id<<1);
		modify(m+1,r,ll,rr,val,id<<1|1);
		pull(id);
	}
	int query(int l,int r,int ll,int rr,int id){
		if(r < ll || l > rr)return -INF;
		if(l != r)push(id);
		if(l >= ll && r <= rr){
			return node[id].mx;
		}
		return max(query(l,m,ll,rr,id<<1),query(m+1,r,ll,rr,id<<1|1));
	}
#undef m
}seg;

