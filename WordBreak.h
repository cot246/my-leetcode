/**
 *Solution 1
 *dp
 *time:O(n^2) space:O(n)
 */
 
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        for(int i=1;i<=s.size();++i)
        {
            for(int j=i-1;j>=0;--j)
            {
                if(dp[j]&&dict.find(s.substr(j,i-j))!=dict.end())
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

/**
 *Solution 2
 *dfs，穷举dict，超时
 *time:O(2^n) space:O(n)
 */
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        auto endOfDIct=end(dict);
        for(auto it=dict.begin();it!=endOfDIct;++it)
        {
            int len=it->size();
            if(s.substr(0,len)==*it&&wordBreak(s.substr(len),dict))return true;
        }
        return false;
    }
};

/**
 *Solution 3
 *dfs，穷举substr，超时
 *time:O(2^n) space:O(n)
 */
 class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        for(int i=1;i<=s.size();++i)
        {
            if(dict.find(s.substr(0,i))!=dict.end()&&wordBreak(s.substr(i),dict))return true;
        }
        return false;
    }
};
