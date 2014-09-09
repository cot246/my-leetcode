/**
 *Solution 1
 *dp
 *time:O(n) space:O(n)
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        const int n=prices.size();
        if(n<2)return 0;
        vector<int> f(n,0);
        vector<int> g(n,0);
        int minVal=prices[0];
        for(int i=1;i<n;++i)
        {
            minVal=min(minVal,prices[i]);
            f[i]=max(f[i-1],prices[i]-minVal);
        }
        int maxVal=prices[n-1];
        for(int i=n-2;i>=0;--i)
        {
            maxVal=max(maxVal,prices[i]);
            g[i]=max(g[i+1],maxVal-prices[i]);
        }
        int max_profit=0;
        for(int i=0;i<n;++i)max_profit=max(max_profit,f[i]+g[i]);
        return max_profit;
    }
};
