class Solution {
public:
    int maximumProfit(vector<int>& prices,int current,bool canBuy,vector<vector<vector<int>>>&vec)
{
    if(current>=prices.size() )
            return 0;
    if(vec[current][canBuy]!=-1) 
        return vec[current][canBuy];
      
    if(canBuy==1)   
    {
        int idle=maximumProfit(prices,current+1,canBuy,vec);  
        int buy=-prices[current]+maximumProfit(prices,current+1,false,vec);
        return vec[current][canBuy]= max(idle,buy);
    }    
   else{
       int idle1=maximumProfit(prices,current+1,canBuy,vec);
       int sell=prices[current]+maximumProfit(prices,current+2,true,vec);
       return vec[current][canBuy]= max(idle1,sell);
   }
}       
    int maxProfit(vector<int>& prices) {
         vector<vector<int>>> vec(prices.size(),vector<int>(2,-1)));

        return maximumProfit(prices,0,1,vec);
    }
};