/**
 *Solution 1
 *time:O(n) space:O(1)
 *左右夹逼，原生态代码
 */
 class Solution {
public:
    bool isPalindrome(string s) {
        int len=s.size();
        if(!len||len==1)return true;
        int l=0,r=len-1;
        while(l<r)
        {
            while(l<r&&!(s[l]>='0'&&s[l]<='9'||s[l]>='A'&&s[l]<='Z'||s[l]>='a'&&s[l]<='z'))++l;
            while(l<r&&!(s[r]>='0'&&s[r]<='9'||s[r]>='A'&&s[r]<='Z'||s[r]>='a'&&s[r]<='z'))--r;
            if(l<r)
            {
                if(s[l]!=s[r]&&abs(s[l]-s[r])!=32)
                    return false;
                else
                {
                    ++l;
                    --r;
                }
            }
        }
        if(l>=r)return true;
        else return false;
    }
};

/**
 *Solution 2
 *time:O(n) space:O(1)
 *左右夹逼，迭代器+字符函数
 */
 class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()==1)
        {
            return true;
        }
        for(string::iterator it=s.begin();it!=s.end();)
        {
            if((!isalpha(*it))&&(!isdigit(*it)))
            {
                it=s.erase(it);
            }
            else
            {
                ++it;
            }
        }
        if(s=="")
        {
            return true;
        }
        string::iterator i=s.begin();
        string::reverse_iterator j=s.rbegin();
        for(;i!=s.end(),j!=s.rend();++i,++j)
        {
            if(isdigit(*i)&&isdigit(*j))
            {
                if(*i==*j)
                {
                    continue;
                }
            }
            if(isalpha(*i)&&isalpha(*j))
            {
                if(tolower(*i)==tolower(*j))
                {
                    continue;
                }
                return false;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

/**
 *Solution 3
 *time:O(n) space:O(1)
 *左右夹逼，迭代器+字符函数
 */
class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        string::iterator beg=s.begin(),end=s.end()-1;
        while(beg<end)
        {
            if(!::isalnum(*beg))++beg;
            else if(!::isalnum(*end))--end;
            else if(*beg!=*end)return false;
            else
            {
                ++beg;
                --end;
            }
        }
        return true;
    }
};
