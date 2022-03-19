// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    
    int maxProfit(int wt[],int profit[],int currentItem,int capacity,int n)
     { 
       if(currentItem>=n)
       return 0;
       int currentItemWeigth=wt[currentItem];
       int currentItemPofit=profit[currentItem];
       int consider=0;
     if(currentItemWeight<=capacity) //calling consider function when we are considering current item
       consider=currentItemProfit+maxProfit(wt,profit,currentItem+1,capacity-currentItemWeight,n);
       
     int notConsider=maxProfit(wt,profit,currentItem+1,capacity,n);
      return max(Consider,notConsider);
     }
     //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int capacity, int wt[], int val[], int n) 
    { 
       // Your code here
       unordered_map<String,int>mp;
       return maxProfit(wt,val,0,capacity,n); // this function has first weight array , then values array,then starting value,total capacity of bag, total no of items
    } 
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends