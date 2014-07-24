/**
 *time:O(n^2) space:O(n^2)
 */
 
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        int r1=0,r2=n-1,c1=0,c2=n-1,num=1;
        vector<vector<int> > ret(n,vector<int>(n,0));
        while(r1<=r2&&c1<=c2)
        {
            for(int j=c1;j<=c2;++j)ret[r1][j]=num++;
            if(++r1>r2)break;
            for(int i=r1;i<=r2;++i)ret[i][c2]=num++;
            if(c1>--c2)break;
            for(int j=c2;j>=c1;--j)ret[r2][j]=num++;
            if(r1>--r2)break;
            for(int i=r2;i>=r1;--i)ret[i][c1]=num++;
            if(++c1>c2)break;
        }
        return ret;
    }
};
