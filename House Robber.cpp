class Solution {
public:
    int maxMoney(vector<int>& nums,int current,unordered_map<int,int>&memo)
    {
        if(current>=nums.size())
            return 0;
        int currentKey=current;
        if(memo.find(currentKey)!=memo.end())
            return memo[currentKey];
        int rob= nums[current]+maxMoney(nums,current+2,memo);
        int noRob=maxMoney(nums,current+1,memo);
        memo[current]=max(rob,noRob);
        return memo[current];
        
    }    
    int rob(vector<int>& nums) {
        unordered_map<int,int>memo;
        return maxMoney(nums,0,memo);
    }
};