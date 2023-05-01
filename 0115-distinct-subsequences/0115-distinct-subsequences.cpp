class Solution {
    
public:
    
    // int n=1000+1;
    // vector<vector<int>> dp(1001,vector<int>(1001,-1));
    
    int rec(int n,int m,string &s, string &t,vector<vector<int>> &dp){
        if(n==0&&m==0)return 1;
        
        if(n==0)return 0;
        
        if(m==0)return 1;
        
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        
        if(s[n-1]==t[m-1]){
            return dp[n][m]=rec(n-1,m-1,s,t,dp)+rec(n-1,m,s,t,dp);
        }
        
        return dp[n][m]=rec(n-1,m,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        
        // dp.resize(1000+1);
        // memset(dp,-1,sizeof(dp));
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return rec(n,m,s,t,dp);
    }
};