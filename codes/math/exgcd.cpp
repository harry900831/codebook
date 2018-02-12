//a * x + b * y = gcd(a,b)
// a % b inverse = b + x

int exgcd(int a,int b,int &x,int &y){
	if(b){
		int tmp = exgcd(b,a%b,y,x);
		y -= a/b*x;
		return tmp;
	}
	x = 1,y = 0;
	return a;
}


void exgcd(int a,int b,int &x,int &y){
    if(!b)x = 1,y = 0;
    else exgcd(b,a%b,y,x),y -= a/b*x;
}

