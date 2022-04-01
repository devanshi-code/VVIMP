class Solution {
public:
    int lengthofLCS(string &s,string &rev,int i,int j,int m,int n,int dp[1001][1001])
    {
        if(i>=m || j>=n)
            return 0;
        
        
        
        if(dp[i][j]!= -1)
           return dp[i][j];
        if(s[i]==rev[j]){
            dp[i][j]=1+lengthofLCS(s,rev,i+1,j+1,m,n,dp);
        }
        else{
            int a=lengthofLCS(s,rev,i,j+1,m,n,dp);
            int b=lengthofLCS(s,rev,i+1,j,m,n,dp);
            dp[i][j]=max(a,b);
        }
        return dp[i][j];
    }    
    int longestPalindromeSubseq(string s) {
       int dp[1001][1001];
       memset(dp,-1,sizeof(dp));
      string rev = string (s.rbegin() , s.rend());
       return lengthofLCS(s,rev,0,0,s.size(),s.size(),dp);
    }
};