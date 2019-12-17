#define N 200005

struct DJS{
	int p[N];
	void init(){
		for(int i = 0 ; i < N ; i++)p[i] = i;
	}
	int query(int x){
		return x == p[x] ? x : p[x] = query(p[x]);
	}
	void unite(int x,int y){
		x = query(x),y = query(y);
		p[x] = y;
	}
	bool same(int x,int y){
		return query(x)==query(y);
	}
}djs;
