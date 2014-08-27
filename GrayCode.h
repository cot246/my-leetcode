/**
 *Solution 1
 *time:O(2^n) space:O(1)
 */
 
class Solution {
public:
    vector<int> grayCode(int n) {
        int len=(1<<n);
        vector<int> res;
        for(int i=0;i<len;++i)res.push_back((i>>1)^i);
        return res;
    }
};
