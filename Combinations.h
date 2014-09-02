/**
 *dfs
 *time:O(n!) space:O(n)
 */
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        if(n<1||k<1||n<k)return res;
        dfs(0,n,k);
        return res;
    }
private:
    vector<vector<int> > res;
    vector<int> v;
    void dfs(int i,int n,int k)
    {
        if(v.size()==k)
        {
            res.push_back(v);
            return;
        }
        for(int j=i;j<n;++j)
        {
            v.push_back(j+1);
            dfs(j+1,n,k);
            v.pop_back();
        }
        return;
    }
};
