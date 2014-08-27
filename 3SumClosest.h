/**
 *Solution 1
 *先排序再左右夹逼
 *time:O(n^2) space:O(1)
 */
 
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        int len=num.size();
        if(len<3)return 0;
        int closest=num[0]+num[1]+num[2]-target;
        for(int i=0;i<len-2;++i)
        {
            int left=i+1,right=len-1;
            while(left<right)
            {
                int cur=num[i]+num[left]+num[right];
                if(abs(closest)>abs(cur-target))closest=cur-target;
                else if(cur==target)return target;
                else if(cur<target)++left;
                else --right;
            }
        }
        return target+closest;
    }
};
