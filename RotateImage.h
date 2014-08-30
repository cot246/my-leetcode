/**
 *Solution 1
 *time:O(n^2) space:O(1)
 */

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if(matrix.empty())return;
        int len=matrix.size();
        int range=len>>1;
        for(int i=0;i<range;++i)
        {
            for(int j=i;j<len-1-i;++j)
            {
                int tmp=matrix[i][j];
                matrix[i][j]=matrix[len-1-j][i];
                matrix[len-1-j][i]=matrix[len-1-i][len-1-j];
                matrix[len-1-i][len-1-j]=matrix[j][len-1-i];
                matrix[j][len-1-i]=tmp;
            }
        }
        return;
    }
};
