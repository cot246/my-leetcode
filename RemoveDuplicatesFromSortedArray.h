/**
 *Solution 1
 *time:O(n) space:O(1)
 */
 
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<2)return n;
        int i=0;
        for(int j=1;j<n;++j)
        {
            if(A[i]!=A[j])A[++i]=A[j];
        }
        return i+1;
    }
};

/**
 *Solution 2
 *time:O(n) space:O(1)
 *use distance and unique of STL
 */
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        return distance(A,unique(A,A+n));
    }
};
