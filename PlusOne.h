/**
 *Solution 1
 *time:O(n) space:O(1)
 *若有进位最后一位为0
 */
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int len=digits.size(),inc=1;
        for(int i=len-1;i>=0;--i)
        {
            int cur=digits[i]+inc;
            digits[i]=cur%10;
            inc=cur/10;
            if(inc<1)return digits;
        }
        if(inc>0)
        {
            digits.push_back(0);
            digits[0]=1;
        }
        return digits;
    }
};
