/**
 *Solution 1: 二维dp
 *time:O(n*m) space:O(n*m)
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.empty())return 0;
        int row=obstacleGrid.size(),col=obstacleGrid[0].size();
        vector<vector<int> > dp(row,vector<int>(col,0));
        for(int j=0;j<col;++j)
        {
            if(!obstacleGrid[0][j])dp[0][j]=1;
            else break;
        }
        for(int i=0;i<row;++i)
        {
            if(!obstacleGrid[i][0])dp[i][0]=1;
            else break;
        }
        for(int i=1;i<row;++i)
        {
            for(int j=1;j<col;++j)
            {
                if(!obstacleGrid[i][j])dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[row-1][col-1];
    }
};

/**
 *Solution 2: 一维dp
 *time:O(n*m) space:O(n)
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.empty())return 0;
        int row=obstacleGrid.size(),col=obstacleGrid[0].size();
        vector<int> dp(col,0);
        bool flag=false;
        for(int j=0;j<col;++j)
        {
            if(!flag)
            {
                if(obstacleGrid[0][j]==0)dp[j]=1;
                else flag=true;
            }
        }
        for(int i=1;i<row;++i)
        {
            if(obstacleGrid[i][0]==1)dp[0]=0;
            for(int j=1;j<col;++j)
            {
                if(obstacleGrid[i][j]==0)dp[j]+=dp[j-1];
                else dp[j]=0;
            }
        }
        return dp[col-1];
    }
};

/**
 *Solution 3: 二维dp，复用obstacleGrid数组
 *time:O(n*m) space:O(1)
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.empty())return 0;
        int row=obstacleGrid.size(),col=obstacleGrid[0].size();
        bool flag=false;
        for(int j=0;j<col;++j)
        {
            if(!flag)
            {
                if(obstacleGrid[0][j]==0)obstacleGrid[0][j]=1;
                else
                {
                    flag=true;
                    obstacleGrid[0][j]=-1;
                }
            }
            else obstacleGrid[0][j]=-1;
        }
        if(row==1)return obstacleGrid[row-1][col-1]>0?1:0;
        if(obstacleGrid[0][0]==1)flag=false;
        else flag=true;
        for(int i=1;i<row;++i)
        {
            if(!flag)
            {
                if(obstacleGrid[i][0]==0)obstacleGrid[i][0]=1;
                else
                {
                    flag=true;
                    obstacleGrid[i][0]=-1;
                }
            }
            else obstacleGrid[i][0]=-1;
        }
        if(col==1)return obstacleGrid[row-1][col-1]>0?1:0;
        for(int i=1;i<row;++i)
        {
            for(int j=1;j<col;++j)
            {
                if(obstacleGrid[i][j]==1)obstacleGrid[i][j]=-1;
                else 
                {
                    if(obstacleGrid[i-1][j]>0)obstacleGrid[i][j]+=obstacleGrid[i-1][j];
                    if(obstacleGrid[i][j-1]>0)obstacleGrid[i][j]+=obstacleGrid[i][j-1];
                }
            }
        }
        return obstacleGrid[row-1][col-1]>0?obstacleGrid[row-1][col-1]:0;
    }
};

/**
 *Solution 4: dfs+备忘录
 *time:O(n*m) space:O(n*m)
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.empty())return 0;
        int row=obstacleGrid.size(),col=obstacleGrid[0].size();
        dp=vector<vector<int> >(row+1,vector<int>(col+1,-1));
        return dfs(obstacleGrid,row,col);
    }
private:
    int dfs(vector<vector<int> > &o,int i,int j)
    {
        if(i<1||j<1)return dp[i][j]=0;
        if(o[i-1][j-1])return dp[i][j]=0;
        if(i==1&&j==1)return dp[i][j]=1;
        if(dp[i][j]==-1)dp[i][j]=dfs(o,i-1,j)+dfs(o,i,j-1);
        return dp[i][j];
    }
    vector<vector<int> > dp;
};

/**
 *Solution 5: dfs+备忘录+复用obstacleGrid
 *time:O(n*m) space:O(1)
 */
