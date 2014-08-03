/**
 *Solution 1: dp+滚动数组
 *time:O(n*m) space:O(n)
 *f[i][j]=f[i-1][j]+f[i][j-1]
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {
                dp[j]+=dp[j-1];
            }
        }
        return dp[n-1];
    }
};

/**
 *Solution 2: dp
 *time:O(n*m) space:O(n*m)
 *f[i][j]=f[i-1][j]+f[i][j-1]
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
    	vector<vector<int> > vv(m,vector<int>(n,1));
	    for(int i=1;i<m;++i)
    	{
    		for(int j=1;j<n;++j)
    		{
    			vv[i][j]=vv[i-1][j]+vv[i][j-1];
    		}
    	}
    	return vv[m-1][n-1];
    }
};

/**
 *Solution 3: dfs+备忘录
 *time:O(n*m) space:O(n*m)
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        this->f=vector<vector<int> >(m+1,vector<int>(n+1,0));
        return dfs(m,n);
    }
private:
    vector<vector<int> > f;
    int dfs(int m,int n)
    {
        if(m<1||n<1)return 0;
        if(m==1||n==1)return 1;
        return getOrUpdate(m-1,n)+getOrUpdate(m,n-1);
    }
    int getOrUpdate(int m,int n)
    {
        if(f[m][n]>0)return f[m][n];
        else return f[m][n]=dfs(m,n);
    }
};

/**
 *Solution 4: dfs
 *超时
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<1||n<1)return 0;
        if(m==1||n==1)return 1;
    	return uniquePaths(m-1,n)+uniquePaths(m,n-1);
    }
};
