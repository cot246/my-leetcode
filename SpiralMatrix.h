/**
 *time:O(n^2) space:O(1)
 */
 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if(matrix.empty())return res;
        int row=matrix.size(),col=matrix[0].size();
        int ri=0,rj=row,ci=0,cj=col;
        while(true)
        {
            for(int c=ci;c!=cj;++c)res.push_back(matrix[ri][c]);
            if(++ri==rj)break;
            for(int r=ri;r!=rj;++r)res.push_back(matrix[r][cj-1]);
            if(ci==--cj)break;
            for(int c=cj-1;c!=ci-1;--c)res.push_back(matrix[rj-1][c]);
            if(ri==--rj)break;
            for(int r=rj-1;r!=ri-1;--r)res.push_back(matrix[r][ci]);
            if(++ci==cj)break;
        }
        return res;
    }
};
