class Solution {
public:
    int nthFib(int n,unordered_map<int,int>&mp)
    {
        if(n==0)
            return 0;
        if (n==1)
            return 1;
        int fibNo=n;
        if(mp.find(fibNo)!=mp.end())
            return mp[n];
        mp[n]=nthFib(n-1,mp) + nthFib(n-2,mp);
        
        return mp[n];
    }    
    int fib(int n) {
        unordered_map<int,int> mp;
        return nthFib(n,mp);
    }
};