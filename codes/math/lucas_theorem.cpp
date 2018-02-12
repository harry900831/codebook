//C(a,b) % c= C(a/c,b/c) * C(a%c,b%c)
//if b>a C(a,b) = 0

int lucas(int a,int b,int c){
	lld tmp=1;
	while(x && y){
		tmp = (tmp * C(a,b)) % c;
		tmp %= c;
		a /= c;
		b /= c;
	}
	return tmp;
}


