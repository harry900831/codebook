#define N 200005

https://www.cnblogs.com/dilthey/p/9366491.html?fbclid=IwAR0xQ1NK7LMlAxACaK_KMm7dcb27f6ooSGcyef8zYUw5780fmhOZbIH04Dk#d-3

struct BIT{
	int p[N],n;
	void init(int _n){
		n = _n;
		for(int i = 0 ; i <= n ; i++)p[i] = 0;
	}
	void update(int x,int t){
		while(x <= n)p[x] += t,x += x&-x;
	}
	int query(int x,int t = 0){
		while(x > 0)t += p[x],x -= x&-x;
		return t;
	}
}bit;



