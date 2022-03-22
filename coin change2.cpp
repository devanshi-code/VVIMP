class Solution {
public:
    int totalWays(vector<int>& coins,int current,int amount,vector<vector<int>> &dp)
    {
        if(amount==0)
            return 1;
        if(current>=coins.size())
            return 0;
        
        if(dp[current][amount]!= -1)
          return dp[current][amount];
        int consider=0;
        if(coins[current]<=amount){
            consider=totalWays(coins,current,amount-coins[current],dp);
    } 
    int notConsider=totalWays(coins,current+1,amount,dp);
    dp[current][amount] = consider+notConsider;
    return consider+notConsider;
} 
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        return totalWays(coins,0,amount,dp);
    }
};