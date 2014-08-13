/**
 *Solution 1
 *time:O(logn) space:O(1)
 *二分查找+左右滑动
 */
 
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        if(n<1)return vector<int>(2,-1);
        int left=0,right=n-1,mid;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(A[mid]>target)right=mid-1;
            else if(A[mid]<target)left=mid+1;
            else break;
        }
        if(A[mid]!=target)return vector<int>(2,-1);
        int i,j;
        for(i=mid;i>=left;--i)
        {
            if(A[i]!=target)break;
        }
        for(j=mid;j<=right;++j)
        {
            if(A[j]!=target)break;
        }
        vector<int> res;
        if(i<mid)res.push_back(i+1);
        else res.push_back(mid);
        if(j>mid)res.push_back(j-1);
        else res.push_back(mid);
        return res;
    }
};

/**
 *Solution 2
 *time:O(logn) space:O(1)
 *二分查找+变形二分查找
 */
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        if(n<1)return vector<int>(2,-1);
        int left=0,right=n-1,mid;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(A[mid]>target)right=mid-1;
            else if(A[mid]<target)left=mid+1;
            else break;
        }
        if(A[mid]!=target)return vector<int>(2,-1);
        int i=left,j=mid,k;
        while(i<=j)
        {
            k=i+(j-i)/2;
            if(A[k]==target)j=k-1;
            else i=k+1;
        }
        vector<int> res;
        res.push_back(i);
        i=mid,j=right;
        while(i<=j)
        {
            k=i+(j-i)/2;
            if(A[k]==target)i=k+1;
            else j=k-1;
        }
        res.push_back(j);
        return res;
    }
};
