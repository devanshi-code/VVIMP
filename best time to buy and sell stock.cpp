class Solution {
public:
    int maximumProfit(vector<int>& prices,int current,int canBuy,int transCount,int dp[1001][2][101])
{
    if(current>=prices.size() || transCount<=0)
            return 0;
    if(dp[current][canBuy][transCount]!=-1) 
        return dp[current][canBuy][transCount];
    int idle=maximumProfit(prices,current+1,canBuy,transCount,dp);    
    if(canBuy==1)   
    {
        
        int buy=-prices[current]+maximumProfit(prices,current+1,0,transCount,dp);
        return max(idle,buy);
    }    
   else{
       
       int sell=prices[current]+maximumProfit(prices,current+1,1,transCount-1,dp);
       return max(idle,sell);
   }
}       
    int maxProfit(vector<int>& prices) {
        int dp[1001][2][101];
        for(int i=0;i<1001;i++)
        {
            for(int j=0;j<2;j++)
            {
                for(int k1=0;k1<101;k1++)
                {
                    dp[i][j][k1]=-1;
                }
            }
        }

        return maximumProfit(prices,0,1,1,dp);
    }
};