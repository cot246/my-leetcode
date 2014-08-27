/**
 *Solution 1
 *time:O(n) space:O(1)
 */
 
class Solution {
public:
    string countAndSay(int n) {
        return dfs(string("1"),n-1);
    }
private:
    string dfs(string s,int n)
    {
        if(n==0)return s;
        if(s.size()==1)return dfs(string("11"),n-1);
        int len=1;
        string res;
        stringstream ss;
        for(int i=1;i<=s.size();++i)
        {
            if(i<s.size()&&s[i]==s[i-1])++len;
            else
            {
                ss<<len;
                res+=ss.str();
                res+=s[i-1];
                len=1;
                ss.str("");
            }
        }
        return dfs(res,n-1);
    }
};

/**
 *Solution 2
 *time:O(n) space:O(1)
 */
class Solution {
public:
    string countAndSay(int n) {
        return dfs(string("1"),n-1);
    }
private:
    string dfs(string s,int n)
    {
        if(n==0)return s;
        if(s.size()==1)return dfs(string("11"),n-1);
        int len=1;
        string res;
        for(int i=1;i<=s.size();++i)
        {
            if(i<s.size()&&s[i]==s[i-1])++len;
            else
            {
                res+=to_string(len);//to_string:C++11
                res+=s[i-1];
                len=1;
            }
        }
        return dfs(res,n-1);
    }
};
