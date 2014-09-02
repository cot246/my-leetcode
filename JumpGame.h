/**
 *time:O(n) space:O(1)
 */
 
class Solution {
public:
    bool canJump(int A[], int n) {
        int longest=0;
        for(int i=0;i<n-1;++i)
        {
            longest=max(longest,A[i]+i);
            if(longest<i+1)return false;
            if(longest>n-2)return true;
        }
        return true;
    }
};
