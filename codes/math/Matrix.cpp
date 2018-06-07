#define MOD 1000000007

struct Matrix{
	lld n,m,M[5][5];
	Matrix(int _n,int _m):n(_n),m(_m){
		fill(&M[0][0],&M[4][5],0);
	}
	Matrix operator*(const Matrix &b){
		Matrix c = Matrix(n,b.m);
		for(int i = 0 ; i < c.n ; i++){
			for(int j = 0 ; j < c.m ; j++){
				for(int k = 0 ; k < m ; k++){
					c.M[i][j] = (c.M[i][j]+M[i][k]*b.M[k][j])%MOD;
				}
			}
		}
		return c;
	}
	Matrix operator^(lld b){
		Matrix c = Matrix(n,m);
		Matrix t = *this;
		for(int i = 0 ; i < c.n ; i++)c.M[i][i] = 1;
		while(b){
			if(b&1)c = c * t;
			t = t * t;
			b >>= 1;
		}
		return c;
	}
	void print(){
		for(int i = 0 ; i < n; i++){
			for(int j = 0 ; j < m ; j++){
				cout << M[i][j] << ' ';
			}cout << endl;
		}
	}
};


