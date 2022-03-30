class Solution {
public:
    int lengthofLCS(string s1,string s2,int i,int j,int m,int n,unordered_map<string,int>&memo)
    {
        if(i>=m || j>=n)
            return 0;
        
        int ans=0;
        string currentKey=to_string(i)+"_"+to_string(j);
        if(memo.find(currentKey)!=memo.end())
            return memo[currentKey];
        if(s1[i]==s2[j]){
            ans=1+lengthofLCS(s1,s2,i+1,j+1,m,n,memo);
        }
        else{
            int a=lengthofLCS(s1,s2,i,j+1,m,n,memo);
            int b=lengthofLCS(s1,s2,i+1,j,m,n,memo);
            ans=max(a,b);
        }
        return ans;
    }    
    int longestCommonSubsequence(string s1, string s2) {
        unordered_map<string,int>memo;
        return lengthofLCS(s1,s2,0,0,s1.size(),s2.size(),memo);
    }
};