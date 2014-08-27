/**
 *Solution 1
 *dfs+增量法
 *time:O(n!) space:O(1)
 */
 
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        if(num.empty())return res;
        sort(begin(num),end(num));
        vector<int> v;
        vector<bool> b(num.size(),true);
        dfs(num,v,b);
        return res;
    }
private:
    vector<vector<int> > res;
    void dfs(vector<int> num,vector<int> &v,vector<bool> &b)
    {
        if(v.size()==num.size())res.push_back(v);
        for(int i=0;i<num.size();++i)
        {
            if(b[i])
            {
                v.push_back(num[i]);
                b[i]=false;
                dfs(num,v,b);
                b[i]=true;
                v.pop_back();
            }
        }
        return;
    }
};
