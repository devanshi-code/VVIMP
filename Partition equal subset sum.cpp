class Solution {
public:
    bool isPossible(vector<int>& nums,int currentIndex,int targetSum,unordered_map<string,int>&memo)
    {
        if(targetSum==0)
            return true;
        if(currentIndex>=nums.size())
            return false;
        string currentKey=to_string(currentIndex)+"_"+to_string(targetSum);
        if(memo.find(currentKey)!=memo.end())
           return memo[currentKey];
        bool consider=false;
        if(nums[currentIndex]<=targetSum)
        {  consider=isPossible(nums,currentIndex+1,targetSum-nums[currentIndex],memo);  }
        if(consider)
        {
            memo[currentKey]=consider;
            return true;
        }    
        bool notConsider=isPossible(nums,currentIndex+1,targetSum,memo);
        memo[currentKey]=consider||notConsider;
        return memo[currentKey];
    }    
    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        for(auto i:nums)
            totalSum+=i;
        if(totalSum%2!=0)
            return false;
        unordered_map<string,int>memo;
        return isPossible(nums,0,totalSum/2,memo);
    }
};