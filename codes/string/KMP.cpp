const int maxn = 1000000;
int f[maxn + 5];

int KMP(string a,string b){
	int i,j = 0,k = -1;
	f[0] = -1;
	while(j < b.size()){
		if(k == -1 || b[j] == b[k])f[++j] = ++k;
		else k = f[k];
	}
	i = j = 0;
	while(i < a.size()){
		if(j == -1 || a[i] == b[j])i++,j++;
		else j = f[j];
		if(j == b.size())return i-j;
	}
	return -1;
}

