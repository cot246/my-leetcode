/**
 *Solution 1
 *recursive
 *time:O(3^n) space:O(n)
 */
 
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string s("");
        if(digits.empty())
        {
            res.push_back(s);
            return res;
        }
        vs.push_back("abc");
        vs.push_back("def");
        vs.push_back("ghi");
        vs.push_back("jkl");
        vs.push_back("mno");
        vs.push_back("pqrs");
        vs.push_back("tuv");
        vs.push_back("wxyz");
        dfs(s,digits,0);
        return res;
    }
private:
    vector<string> vs;
    vector<string> res;
    void dfs(string &s,string d,int n)
    {
        if(n==d.size())
        {
            res.push_back(s);
            return;
        }
        if(d[n]>'1'&&d[n]<='9')
        {
            string str(vs[d[n]-'2']);
            for(auto i=begin(str);i!=end(str);++i)
            {
                s.push_back(*i);
                dfs(s,d,n+1);
                s.pop_back();
            }
            return;
        }
        dfs(s,d,n+1);
        return;
    }
};

/**
 *Solution 2
 *iterative,神迭代
 *time:O(3^n) space:O(1)
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret(1,"");
        for(int i=0;i<digits.size();++i)
        {
            int sz=ret.size();
            for(int j=0;j<sz;++j)
            {
                const string &s(v[digits[i]-'2']);
                for(int k=0;k<s.size();++k)
                {
                    if(k!=s.size()-1)
                    {
                        ret.push_back(ret[j]+s[k]);
                    }
                    else
                    {
                        ret[j]+=s[k];
                    }
                }
            }
        }
        return ret;
    }
private:
    vector<string> v={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
};
