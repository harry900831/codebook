typedef pair<double,double> Pair;
Pair p[100005],st[100005];

double cross(Pair o,Pair a,Pair b){
	return (a.F-o.F)*(b.S-o.S)-(a.S-o.S)*(b.F-o.F);
}
int convex_hull(){
	sort(p,p+n);
	int num = 0;
	for(int i = 0 ; i < n ; i++){
		while(num >= 2 && cross(st[num-2],st[num-1],p[i]) <= 0)num--;
		st[num++] = p[i];
	}
	for(int i = n-2, t = num; i >= 0 ; i--){
		while(num > t && cross(st[num-2],st[num-1],p[i]) <= 0)num--;
		st[num++] = p[i];
	}
	return num-1;
}
