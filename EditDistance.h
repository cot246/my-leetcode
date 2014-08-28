/**
 *Solution 1
 *二维dp
 *状态转移方程 D(i,j)=min { D(i-1, j) +1, D(i, j-1) +1 , D(i-1, j-1) + s1[i]==s2[j] ? 0 : 1}
 *time:O(n*m) space:O(n*m)
 */
 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1=word1.size(),len2=word2.size();
        vector<vector<int> > dp(len1+1,vector<int>(len2+1,0));
        for(int i=0;i<len1+1;++i)dp[i][0]=i;
        for(int j=0;j<len2+1;++j)dp[0][j]=j;
        for(int i=1;i<len1+1;++i)
        {
            for(int j=1;j<len2+1;++j)
            {
                if(word1[i-1]==word2[j-1])dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;//增、删、改
            }
        }
        return dp[len1][len2];
    }
};

/**
 *Solution 2
 *二维dp+滚动数组
 *time:O(n*m) space:O(n)
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size()<word2.size())return minDistance(word2,word1);
        vector<int> dp(word2.size()+1,0);
        for(int i=0;i<word2.size()+1;++i)dp[i]=i;
        for(int i=1;i<word1.size()+1;++i)
        {
            int upper_left=dp[0];//左上方
            dp[0]=i;//第一个滚动
            for(int j=1;j<word2.size()+1;++j)
            {
                int upper=dp[j];//上方
                if(word1[i-1]==word2[j-1])dp[j]=upper_left;
                else dp[j]=min(min(upper_left,upper),dp[j-1])+1;//增、删、改
                upper_left=upper;
            }
        }
        return dp[word2.size()];
    }
};
