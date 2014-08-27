/**
 *Solution 1
 *先二分查找所在行，再二分查找所在列
 *time:O(logn) space:O(1)
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.empty())return false;
        int row=matrix.size(),col=matrix[0].size();
        int left=0,right=row-1,mid;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(matrix[mid][0]==target||matrix[mid][col-1]==target)return true;
            if(matrix[mid][0]<target&&matrix[mid][col-1]>target)
            {
                left=0,right=col-1;
                int m;
                while(left<=right)
                {
                    m=left+(right-left)/2;
                    if(matrix[mid][m]>target)right=m-1;
                    else if(matrix[mid][m]<target)left=m+1;
                    else return true;
                }
                return false;
            }
            if(matrix[mid][0]>target)right=mid-1;
            if(matrix[mid][col-1]<target)left=mid+1;
        }
        return false;
    }
};

/**
 *Solution 2
 *将矩阵看作一维数组进行二分查找
 *time:O(logn) space:O(1)
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.empty())return false;
        int row=matrix.size(),col=matrix[0].size();
        int left=0,right=row*col-1,mid;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            int val=matrix[mid/col][mid%col];
            if(val==target)return true;
            if(val>target)right=mid-1;
            if(val<target)left=mid+1;
        }
        return false;
    }
};
