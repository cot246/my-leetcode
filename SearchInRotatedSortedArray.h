/**
 *time:O(logn) space:O(1)
 *二分查找，注意边界
 */

class Solution {
public:
    int search(int A[], int n, int target) {
        if(!n)return -1;
        int l=0,r=n-1,m;
        while(l<=r)
        {
            m=(l+r)/2;
            if(target==A[m])return m;
            if(A[m]<A[r])
            {
                if(target>A[m]&&target<=A[r])l=m+1;
                else r=m-1;
            }
            else
            {
                if(target>=A[l]&&target<A[m])r=m-1;
                else l=m+1;
            }
        }
        return -1;
    }
};
