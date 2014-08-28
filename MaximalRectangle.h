/**
 *Solution 1
 *二维dp
 *time:O(n^2) space:O(n^2)
 */
 
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty())return 0;
        int row=matrix.size(),col=matrix[0].size();
        vector<vector<int> > dp(row,vector<int>(col,0));
        for(int i=0;i<row;++i)
        {
            if(matrix[i][0]=='1')dp[i][0]=1;
        }
        for(int i=0;i<row;++i)
        {
            for(int j=1;j<col;++j)
            {
                if(matrix[i][j]=='1')dp[i][j]=dp[i][j-1]+1;
            }
        }
        int area=0;
        for(int i=row-1;i>=0;--i)
        {
            for(int j=col-1;j>=0;--j)
            {
                if((i+1)*(j+1)<=area)break;
                int width=dp[i][j];
                for(int k=i;k>=0&&width>0;--k)
                {
                    if((i+1)*width<=area)break;
                    if(dp[k][j]<width)width=dp[k][j];
                    area=max(area,(i-k+1)*width);
                }
            }
        }
        return area;
    }
};

/**
 *Solution 1
 *一维dp
 *time:O(n^2) space:O(n)
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty())return 0;
        int row=matrix.size(),col=matrix[0].size();
        vector<int> H(col,0);
        vector<int> L(col,0);
        vector<int> R(col,col);
        int area=0;
        for(int i=0;i<row;++i)
        {
            int left=0,right=col;
            //从左往右计算L(i,j)
            for(int j=0;j<col;++j)
            {
                if(matrix[i][j]=='1')
                {
                    ++H[j];
                    L[j]=max(L[j],left);
                }
                else
                {
                    left=j+1;
                    H[j]=0;L[j]=0;R[j]=col;
                }
            }
            //从右往左计算R(i,j)
            for(int j=col-1;j>=0;--j)
            {
                if(matrix[i][j]=='1')
                {
                    R[j]=min(R[j],right);
                    area=max(area,H[j]*(R[j]-L[j]));
                }
                else right=j;
            }
        }
        return area;
    }
};
