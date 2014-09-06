/**
 *Solution 1
 *二维dp
 *time:O(n*m) space:O(n*m)
 */
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.size()<1)return 0;
        int rows=grid.size(),cols=grid[0].size();
        vector<vector<int> > dp(rows,vector<int>(cols,0));
        dp[0][0]=grid[0][0];
        for(int i=1;i<cols;++i)
        {
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        for(int i=1;i<rows;++i)
        {
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int i=1;i<rows;++i)
        {
            for(int j=1;j<cols;++j)
            {
                dp[i][j]=min(dp[i][j-1],dp[i-1][j])+grid[i][j];
            }
        }
        return dp[rows-1][cols-1];
    }
};

/**
 *Solution 2
 *一维dp+滚动数组
 *time:O(n*m) space:O(m)
 */
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.empty())return 0;
        int row=grid.size(),col=grid[0].size();
        vector<int> dp(grid[0].begin(),grid[0].end());
        for(int j=1;j<col;++j)dp[j]+=dp[j-1];
        for(int i=1;i<row;++i)
        {
            dp[0]+=grid[i][0];
            for(int j=1;j<col;++j)
            {
                dp[j]=min(dp[j-1],dp[j])+grid[i][j];
            }
        }
        return dp[col-1];
    }
};

/**
 *Solution 3
 *dfs+备忘录
 *time:O(n*m) space:O(n*m)
 */
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.empty())return 0;
        int row=grid.size(),col=grid[0].size();
        dp=vector<vector<int> > (row,vector<int>(col,-1));
        return dfs(grid,row-1,col-1);
    }
private:
    vector<vector<int> > dp;
    int getOrUpdate(vector<vector<int> > &grid,int i,int j)
    {
        if(i<0||j<0)return INT_MAX;
        if(dp[i][j]>=0)return dp[i][j];
        else return dp[i][j]=dfs(grid,i,j);
    }
    int dfs(vector<vector<int> > &grid,int i,int j)
    {
        if(i<0||j<0)return INT_MAX;
        if(i==0&&j==0)return grid[0][0];
        return min(getOrUpdate(grid,i-1,j),getOrUpdate(grid,i,j-1))+grid[i][j];
    }
};
