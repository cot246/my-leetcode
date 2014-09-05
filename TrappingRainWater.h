/**
 *Solution 1
 *左右各遍历一次
 *time:O(n) space:O(n)
 */
class Solution {
public:
    int trap(int A[], int n) {
        if(n<3)return 0;
        vector<int> dp(n,0);
        int large=A[0];
        for(int i=1;i<n;++i)
        {
            large=max(large,A[i]);
            dp[i]=large;
        }
        large=A[n-1];
        for(int i=n-2;i>=0;--i)
        {
            large=max(large,A[i]);
            dp[i]=min(large,dp[i]);
        }
        int res=0;
        for(int i=1;i<n-1;++i)
        {
            if(dp[i]>A[i])res+=dp[i]-A[i];
        }
        return res;
    }
};
