class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> r;
        unordered_map<int, int> count;
        for (const auto &n: nums1) {
            if (count.find(n) == count.end()) {
                count[n] = 1;
            } else {
                count[n] ++;
            }
        }
        for (const auto &n: nums2) {
            if (count.find(n) != count.end()) {
                if (count[n] > 0) {
                    r.push_back(n);
                    count[n] --;
                }
            }
        }
        return r;
    }
};