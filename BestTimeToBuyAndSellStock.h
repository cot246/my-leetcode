/**
 *Solution 1
 *从前往后动规地找最小值，并同步更新最大收益
 *time:O(n) space:O(1)
 */
 class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty())return 0;
        int dp=prices[0],maxP=prices[0],mx=0;
        for(int i=1;i<prices.size();++i)
        {
            if(prices[i]<dp)dp=prices[i];
            mx=max(mx,prices[i]-dp);
        }
        return mx;
    }
};
 
/**
 *Solution 2
 *从后往前动规地找最大值，并同步更新最大收益
 *time:O(n) space:O(1)
 */ 
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty())return 0;
        int len=prices.size()-1,dp=prices[len],mx=0;
        for(int i=len-1;i>=0;--i)
        {
            if(prices[i]>dp)dp=prices[i];
            mx=max(mx,dp-prices[i]);
        }
        return mx;
    }
};
