 /**
 * Solution 1
 * time: O(n) space: O(1)
 * 
 */
class Solution {
public:
    void reverseWords(string &s)
    {
        string res("");
        for(int i=s.size()-1;i>=0;--i)
        {
            while(i>=0&&s[i]==' ')--i;
            if(i<0)break;
            if(!res.empty())res.push_back(' ');
            string str;
            while(i>=0&&s[i]!=' ')str.push_back(s[i--]);
            reverse(str.begin(),str.end());
            res.append(str);
        }
        s=res;
        return;
    }
};

 /**
 * Solution 2
 * time: O(n) space: O(1)
 * 利用stringstream+getline来分割单词
 */
class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty())return;
        string s1(""),s2("");
        stringstream ss(s);
        while(getline(ss,s2,' '))
        {
            if(s2=="")continue;
            string s3(s2.rbegin(),s2.rend());
            s1+=s3;
            s1+=' ';
        }
        if(s1.empty())
        {
            s="";
            return;
        }
        string s4(s1.rbegin(),s1.rend());
        s=s4.substr(1);
        return;
    }
};
