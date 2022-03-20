class Solution {
public:
    int totalWays(vector<int>& nums,int CI,int target,unordered_map<string,int>&mp)
    {  if(CI==nums.size() && target==0)
          return 1;
     if(CI==nums.size() && target!=0)
         return 0;
     string currentKey=to_string(CI)+"_"+to_string(target);
     if(mp.find(currentKey)!=mp.end())
         return mp[currentKey];
     int posSign=totalWays(nums,CI+1,target-nums[CI],mp);
     int negSign=totalWays(nums,CI+1,target+nums[CI],mp);
     mp[currentKey]=posSign+negSign;
     return mp[currentKey];
        
    }    
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int>mp;
        return totalWays(nums,0,target,mp);
        
        
    }
};