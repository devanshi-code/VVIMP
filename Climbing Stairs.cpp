class Solution {
public:
    int totalways(int current,int target,unordered_map<int,int>&mp)
    {
        if(current==target)
            return 1;
        if(current>target)
            return 0;
        int currentKey=current;
        if(mp.find(currentKey)!=mp.end())
            return mp[current];
        int oneJump=totalways(current+1,target,mp);
        int twoJump=totalways(current+2,target,mp);
        mp[current]=oneJump+twoJump;
        return oneJump+twoJump;
    }    
    int climbStairs(int n) {
        unordered_map<int,int>mp;
        return totalways(0,n,mp);
    }
};