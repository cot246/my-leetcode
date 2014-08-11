/**
 * Solution 1
 *time:O(2^n) space:O(n)
 *位向量+dfs
 */
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(),S.end());
        int len=S.size();
        vector<vector<int> > vv;
        for(int i=0;i<(1<<len);++i)
        {
            vector<bool> bin=dec2bin(i,len);
            vector<int> v;
            for(int j=0;j<len;++j)
            {
                if(bin[j])v.push_back(S[j]);
            }
            vv.push_back(v);
        }
        return vv;
    }
private:
    vector<bool> dec2bin(int n,int len)
    {
        vector<bool> res(len,false);
        for(int i=0;i<len;++i)
        {
            if(n)
            {
                if(n%2!=0)res[i]=true;
                n=n>>1;
            }
            else break;
        }
        return res;
    }
};

/**
 * Solution 2
 *time:O(2^n) space:O(n)
 *增量法+dfs
 */
 class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(),S.end());
        int len=S.size();
        vector<vector<int> > vv;
        vector<bool> flag(len,false);
        while(true)
        {
            vector<int> v;
            for(int i=0;i<len;++i)
            {
                if(flag[i])v.push_back(S[i]);
            }
            vv.push_back(v);
            bool inc=true;
            for(int i=0;inc&&i<len;++i)
            {
                inc&=flag[i];
                flag[i]=!flag[i];
            }
            if(inc)break;
        }
        return vv;
    }
};
