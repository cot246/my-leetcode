/**
 *Solution 1
 *time:O(n) space:O(1)
 */
 
class Solution {
public:
    int reverse(int x) {
        if(x==0)return x;
        if(x<0)return -1*reverse(-1*x);
        string s("");
        while(x)
        {
            s.push_back(x%10+'0');
            x/=10;
        }
        stringstream ss;
        ss<<s;
        ss>>x;
        return x;
    }
};

/**
 *Solution 2
 *time:O(n) space:O(1)
 */
class Solution {
public:
    int reverse(int x) {
        if(x<0)return reverse(-x)*(-1);
        stringstream ss;
        ss<<x;
        string s=ss.str(),str(s.rbegin(),s.rend());
        ss.str("");
        int len =str.size();
        if(len==1)return x;
        // for(int i=0;i<len;++i)
        // {
        //     if(str[i]=='0')str.erase(i,1);
        //     else break;
        // }
        ss<<str;
        int ret;
        ss>>ret;
        return ret; 
    }
};

/**
 *Solution 3
 *time:O(n) space:O(1)
 */
class Solution {
public:
    int reverse(int x) {
        if(x==0)return x;
        if(x<0)return -1*reverse(-1*x);
        string s(to_string(x));
        string rs(s.rbegin(),s.rend());
        stringstream ss;
        ss<<rs;
        ss>>x;
        return x;
    }
};

/**
 *Solution 4
 *time:O(n) space:O(1)
 */
class Solution {
public:
    int reverse(int x) {
        int r=0;
        for(;x;x/=10)r=r*10+x%10;
        return r;
    }
};
