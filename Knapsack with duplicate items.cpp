// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxProfit(int wt[],int val[],int currentItem,int capacity,int n,vector<vector<int>>&mp)
    {
        if(capacity==0 )
         return 0;
        if(currentItem>=n)
           return -1;
        int currentItemWeight=wt[currentItem];
        int currentItemProfit=val[currentItem];
        if(mp[currentItem][capacity]!=-1)
          return mp[currentItem][capacity];
        int consider=0;
        if(currentItemWeight<=capacity)
        { consider=currentItemProfit+maxProfit(wt,val,currentItem,capacity-currentItemWeight,n,mp);}
        int notConsider=maxProfit(wt,val,currentItem+1,capacity,n,mp);
        mp[currentItem][capacity]= max(consider,notConsider);
        return max(consider,notConsider);
    }
    int knapSack(int n, int capacity, int val[], int wt[])
    { vector<vector<int>>mp(1002,vector<int>(1002,-1));
        int profit = maxProfit(wt,val,capacity,n,0,mp);
        if(profit == -1) return 0;
        return profit;
        // code here
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