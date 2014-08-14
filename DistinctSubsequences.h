/**
 *Solution 1
 *time:O(m*n) space:O(m*n)
 *二维dp，状态转移方程dp[i][j]=s[j-1]==t[i-1]?dp[i][j-1]+dp[i-1][j-1]:dp[i][j-1];
 */
class Solution {
public:
    int numDistinct(string s, string t) {
        int lens=s.size(),lent=t.size();
        if(lens<lent)return 0;
        vector<vector<int> > dp(lent+1,vector<int>(lens+1,0));
        for(int i=0;i<=lens;++i)dp[0][i]=1;
        for(int i=1;i<=lent;++i)
        {
            for(int j=1;j<=lens;++j)
            {
                dp[i][j]=dp[i][j-1];
                if(s[j-1]==t[i-1])dp[i][j]+=dp[i-1][j-1];
            }
        }
        return dp[lent][lens];
    }
};
