/// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxProfit(int wt[],int val[],int currentItem,int capacity,int n,int dp[][1002])
    {
        if(capacity==0 )
         return 0;
        if(currentItem>=n)
           return 0;
       
        if(dp[currentItem][capacity]!= -1)
          return dp[currentItem][capacity];
        int consider=0;
        if(wt[currentItem]<=capacity)
        { 
            consider= val[currentItem] +maxProfit(wt,val,currentItem,capacity-wt[currentItem],n,dp);
        }
        int notConsider=maxProfit(wt,val,currentItem+1,capacity,n,dp);
        dp[currentItem][capacity]= max(consider,notConsider);
        return max(consider,notConsider);
    }
    int knapSack(int N, int capacity, int val[], int wt[])
    { 
        // code here
      int dp[1002][1002];
      memset(dp,-1,sizeof(dp));
      return maxProfit(wt,val,0,capacity,N,dp);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends