/**
 * Solution 1
 * time: O(n) space: O(1)
 * 细节实现题，要考虑周全，有很多corner case。代码太丑，还需要再优化。
 */
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        if(L<1)return words;
        vector<string> ret;
        int szLine=L,szVec=words.size();
        string str("");
        int start=0;
        for(int i=0;i<szVec;++i)
        {
            int szWord=words[i].size();
            if(szLine>szWord)
            {
                if(i==szVec-1)
                {
                    if(start==i)
                    {
                        string s(szLine-szWord,' ');
                        str=words[i]+s;
                        ret.push_back(str);
                        return ret;
                    }
                    for(int j=start;j<=i;++j)str+=words[j];
                    szLine-=words[i].size();
                    if(szLine>0)str+=string(szLine,' ');
                    ret.push_back(str);
                    return ret;
                }
                szLine-=szWord+1;
                words[i]+=' ';
            }
            else if(szLine==szWord)
            {
                for(int j=start;j<=i;++j)str+=words[j];
                ret.push_back(str);
                start=i+1;
                str="";
                szLine=L;
            }
            else
            {
                ++szLine;
                words[i-1].erase(words[i-1].end()-1);
                int num=i-start;
                bool flag=false;
                if(num>1)
                {
                    --num;
                    flag=true;
                }
                int rem=szLine%num;
                int shang=szLine/num;
                int j=0;
                if(rem>0)
                {
                    string s1(1+shang,' ');
                    for(;j<rem;++j)str+=words[start+j]+s1;
                }
                string s2(shang,' ');
                for(;j<num;++j)str+=words[start+j]+s2;
                if(flag)str+=words[start+j];
                ret.push_back(str);
                str="";
                szLine=L-szWord-1;
                start=i;
                words[i]+=' ';
                if(i==szVec-1)
                {
                    ++szLine;
                    words[i].erase(words[i].end()-1);
                    str+=words[i];
                    if(szLine>0)str+=string(szLine,' ');
                    ret.push_back(str);
                    return ret;
                }
            }
        }
        return ret;
    }
};
