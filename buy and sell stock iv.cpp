class Solution {
public:
    int maximumProfit(vector<int>& prices,int current,bool canBuy,int transCount,vector<vector<vector<int>>>&vec)
{
    if(current>=prices.size() || transCount<=0)
            return 0;
    if(vec[current][canBuy][transCount]!=-1) 
        return vec[current][canBuy][transCount];
      
    if(canBuy==1)   
    {
        int idle=maximumProfit(prices,current+1,canBuy,transCount,vec);  
        int buy=-prices[current]+maximumProfit(prices,current+1,false,transCount,vec);
        return vec[current][canBuy][transCount]= max(idle,buy);
    }    
   else{
       int idle=maximumProfit(prices,current+1,canBuy,transCount,vec);
       int sell=prices[current]+maximumProfit(prices,current+1,true,transCount-1,vec);
       return vec[current][canBuy][transCount]= max(idle,sell);
   }
}       
    int maxProfit(int k,vector<int>& prices) {
         vector<vector<vector<int>>> vec(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));

        return maximumProfit(prices,0,1,k,vec);
    }
};