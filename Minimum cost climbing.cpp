class Solution {
public:
    int findClimbs(vector<int>&cost,int current,unordered_map<int,int>&m)
    {
        if(current==cost.size())
            return 0;
        if(current>cost.size())
            return 1001;
        
        if(m.find(current)!=m.end())
            return m[current];
        int oneJump=cost[current]+findClimbs(cost,current+1,m);
        int twoJump=cost[current]+findClimbs(cost,current+2,m);
        int currentIndex=current; 
        m[currentIndex]=min(oneJump,twoJump);
        return min(oneJump,twoJump);
    }    
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int,int>m;
        int indexZero=findClimbs(cost,0,m);
        int indexOne=findClimbs(cost,1,m);
        return min(indexZero,indexOne);
    }
};