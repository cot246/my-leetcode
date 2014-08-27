/**
 *Solution 1
 *dfs+增量法
 *time:O(n!) space:O(1)
 */
 
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        if(num.empty())return ret;
        if(num.size()==1)
        {
            ret.push_back(num);
            return ret;
        }
        sort(num.begin(),num.end());
        vector<int> vec;
        vector<bool> flag(num.size(),false);
        dfs(num,vec,flag);
        return ret;
    }
private:
    vector<vector<int> > ret;
    void dfs(vector<int> n,vector<int> &v,vector<bool> &flag)
    {
        if(v.size()==n.size())
        {
            ret.push_back(v);
            return;
        }
        for(int i=0;i<n.size();++i)
        {
            if(flag[i]||(i>0&&!flag[i-1]&&n[i]==n[i-1]))continue;
            flag[i]=true;
            v.push_back(n[i]);
            dfs(n,v,flag);
            v.pop_back();
            flag[i]=false;
        }
        return;
    }
};
