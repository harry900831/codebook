#define PB push_back
#define N 100005
pair<int,int> stu[N],lis[N];

struct BIT{
	int n;
	vector<int> p[2*N];
	vector<int> val[2*N];
	void init(int _n){
		n = _n;
	}
	void lisadd(int x,int k){
		while(x <= n){
			val[x].PB(k);
			x += x&-x;
		}
	}
	void lisquery(int x,int k){
		while(x > 0){
			val[x].PB(k);
			x -= x&-x;
		}
	}
	void lis(){
		for(int i = 0; i <= n; i++){
			val[i].PB(n);
			sort(val[i].begin(),val[i].end());
			val[i].resize(unique(val[i].begin(),val[i].end())-val[i].begin());
			p[i].resize(val[i].size()+3,0);
		}
	}
	void add(int x,int k){
		while(x <= n){
			int y = lower_bound(val[x].begin(),val[x].end(),k)-val[x].begin()+1;
			while(y < p[x].size()){
				p[x][y]++;
				y += y&-y;
			}
			x += x&-x;
		}
	}
	int query(int x,int k,int res = 0){
		while(x > 0){
			int y = lower_bound(val[x].begin(),val[x].end(),k)-val[x].begin()+1;
			while(y > 0){
				res += p[x][y];
				y -= y&-y;
			}
			x -= x&-x;
		}
		return res;
	}
}bit;
