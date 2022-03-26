class Solution {
public:
    int totalWays(int currentRow,int currentCol,int m,int n,vector<vector<int>>& obstacleGrid,unordered_map<string,int>&memo)
    {
         if(currentRow==m-1 && currentCol==n-1 && obstacleGrid[currentRow][currentCol]!=1)
             return 1;
        if(currentRow>=m || currentCol>=n || obstacleGrid[currentRow][currentCol]==1)
            return 0;
        string currentKey=to_string(currentRow)+"-"+to_string(currentCol);
        if(memo.find(currentKey)!=memo.end())
            return memo[currentKey];
        int rightMove=totalWays(currentRow,currentCol+1,m,n,obstacleGrid,memo);
        int downMove=totalWays(currentRow+1,currentCol,m,n,obstacleGrid,memo);
        memo[currentKey]=rightMove+downMove;
        return memo[currentKey];
        
    }    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        unordered_map<string,int>memo;
        return totalWays(0,0,obstacleGrid.size(),obstacleGrid[0].size(),obstacleGrid,memo);
    }
};