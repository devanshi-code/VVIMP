class Solution {
public:
    int lengthofLCS(string &s1,string &s2,int i,int j,int m,int n,int dp[1001][1001])
    {
        if(i>=m || j>=n)
            return 0;
        
        
        
        if(dp[i][j]!= -1)
           return dp[i][j];
        if(s1[i]==s2[j]){
            dp[i][j]=1+lengthofLCS(s1,s2,i+1,j+1,m,n,dp);
        }
        else{
            int a=lengthofLCS(s1,s2,i,j+1,m,n,dp);
            int b=lengthofLCS(s1,s2,i+1,j,m,n,dp);
            dp[i][j]=max(a,b);
        }
        return dp[i][j];
    }    
    int longestCommonSubsequence(string s1, string s2) {
       int dp[1001][1001];
       memset(dp,-1,sizeof(dp));
       return lengthofLCS(s1,s2,0,0,s1.size(),s2.size(),dp);
    }
};
