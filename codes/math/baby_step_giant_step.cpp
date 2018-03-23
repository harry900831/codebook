// a^ans = b (MOD m)
long long BSGS(long long a, long long b ,long long m) {
	unordered_map <long long, int> mp;
	long long sq = sqrt(m),t = 1, x,y;
	for (int i = 0; i < sq; i++) {
		if (t == b) return i;
        	if (!mp[t]) mp[t] = i;
		t = (t * a) % m;
	}
	exgcd(t, m, x, y);
	x = (x + m) % m;
	for (int i = 0; i <= sq+1; i++) {
		if (mp[b])return i * sq + mp[b];
		b = (b * x) % m;
	}
	return -1;
}
