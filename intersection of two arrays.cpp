class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,boolean>memo;
        for(auto it:nums1)
        {
            if(memo.find(currentNum)!=memo.end())
                return memo[currentNum]=true;
        }    
    }
};