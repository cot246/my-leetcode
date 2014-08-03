/**
 *time:O(n^2) space:O(1)
 *左右夹逼
 */
 
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(),num.end());
        int len=num.size();
        vector<vector<int> > ret;
        for(int i=0;i<len-2;++i)
        {
            int left=i+1,right=len-1;
            if(i>0&&num[i]==num[i-1])
            {
                continue;
            }
            while(left<right)
            {
                if(left>i+1&&num[left]==num[left-1])
                {
                    ++left;
                    continue;
                }
                if(right<len-1&&num[right]==num[right+1])
                {
                    --right;
                    continue;
                }
                if(num[i]+num[left]+num[right]==0)
                {
                    vector<int> vec;
                    vec.push_back(num[i]);
                    vec.push_back(num[left]);
                    vec.push_back(num[right]);
                    ret.push_back(vec);
                    ++left;
                    --right;
                    continue;
                }
                else if(num[i]+num[left]+num[right]>0)--right;
                else ++left;
            }
        }
        return ret;
    }
};
