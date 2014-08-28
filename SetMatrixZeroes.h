/**
 *Solution 1
 *time:O(n*m) space:O(1)
 */
 
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.empty())return;
        int row=matrix.size(),col=matrix[0].size();
        bool row1=false,col1=false;
        for(int j=0;j<col;++j)
        {
            if(!matrix[0][j])
            {
                row1=true;
                break;
            }
        }
        for(int i=0;i<row;++i)
        {
            if(!matrix[i][0])
            {
                col1=true;
                break;
            }
        }
        for(int i=1;i<row;++i)
        {
            for(int j=1;j<col;++j)
            {
                if(!matrix[i][j])
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<row;++i)
        {
            for(int j=1;j<col;++j)if(!matrix[i][0]||!matrix[0][j])matrix[i][j]=0;
        }
        if(row1)
        {
            for(int j=0;j<col;++j)matrix[0][j]=0;
        }
        if(col1)
        {
            for(int i=0;i<row;++i)matrix[i][0]=0;
        }
        return;
    }
};
