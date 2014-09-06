/**
 *Solution 1
 *dfs+剪枝
 *time:O(n!) space:O(n)
 */
 
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> v(n,-1);
        dfs(v,0,n);
        return res;
    }
private:
    vector<vector<string> > res;
    bool judge(vector<int> v,int row,int col)
    {
        for(int i=0;i<row;++i)
        {
            if(v[i]==col)return false;
            if(v[i]-col==i-row)return false;
            if(v[i]-col==row-i)return false;
        }
        return true;
    }
    void dfs(vector<int> v,int row,int n)
    {
        for(int i=0;i<n;++i)
        {
            if(judge(v,row,i))
            {
                v[row]=i;
                if(row+1>=n)
                {
                    string s(n,'.');
                    vector<string> vs(n,s);
                    for(int j=0;j<n;++j)vs[j][v[j]]='Q';
                    res.push_back(vs);
                    continue; 
                }
                dfs(v,row+1,n);
            }
        }
        return;
    }
};
