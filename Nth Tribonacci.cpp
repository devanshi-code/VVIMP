class Solution {
public:
    int nthtribonacci(int n,unordered_map<int,int>&memo)
    {
        if(n==0)
         return 0;
        if(n==1)
         return 1;
        if(n==2) return 1; // should include this definitely
        int currentKey=n;
        if(memo.find(currentKey)!=memo.end()) //checking key is present or not
           return memo[currentKey];
        memo[n]=nthtribonacci(n-1,memo)+nthtribonacci(n-2,memo)+nthtribonacci(n-3,memo);//adding key
        return memo[n]; 
    }    
    int tribonacci(int n) {
        unordered_map<int,int>memo;
        return nthtribonacci(n,memo);
            
            
    }
};