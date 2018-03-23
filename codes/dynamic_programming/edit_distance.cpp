//1-base
int dp[2005][2005];

int edit_distance(string a,string b){
    int n = a.size(),m = b.size();
    for(int i = 0 ; i <= n ; i++)dp[i][0] = i;
    for(int j = 0 ; j <= m ; j++)dp[0][j] = j;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            dp[i][j] = a[i-1]==b[j-1] ? dp[i-1][j-1] : min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
        }
    }
    return dp[n][m];
}
