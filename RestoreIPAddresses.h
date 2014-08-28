/**
 *Solution 1
 *dfs
 *time:O(n^4) space:O(n)
 */
 
 class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string ip;
        dfs(s,ip,0,0);
        return vs;
    }
private:
    vector<string> vs;
    void dfs(string s,string ip,int start,int step)
    {
        if(step==4&&s.size()==start)
        {
            vs.push_back(ip);
            return;
        }
        if(start+(4-step)*3<s.size())return;
        if(start+4-step>s.size())return;
        for(int i=1;i<=3;++i)
        {
            string tmp=s.substr(start,i);
            if(i>1&&tmp[0]=='0')break;
            if(i==3&&tmp>"255")continue;
            string curIP=ip+tmp;
            if(step!=3)curIP+='.';
            dfs(s,curIP,start+i,step+1);
        }
        return;
    }
};
