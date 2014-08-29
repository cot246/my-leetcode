/**
 *Solution 1
 *dfs
 *time:O(n^2*m^2) space:O(1)
 */
 
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(board.empty())return false;
        int row=board.size(),col=board[0].size();
        for(int i=0;i<row;++i)
        {
            for(int j=0;j<col;++j)
            {
                if(board[i][j]==word[0]&&dfs(board,word,i,j,1))return true;
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char> > &b,string w,int i,int j,int k)
    {
        if(k==w.size())return true;
        char tmp=b[i][j];
        b[i][j]='#';
        if(i>0&&b[i-1][j]==w[k]&&dfs(b,w,i-1,j,k+1))return true;
        if(j>0&&b[i][j-1]==w[k]&&dfs(b,w,i,j-1,k+1))return true;
        if(i+1<b.size()&&b[i+1][j]==w[k]&&dfs(b,w,i+1,j,k+1))return true;
        if(j+1<b[0].size()&&b[i][j+1]==w[k]&&dfs(b,w,i,j+1,k+1))return true;
        b[i][j]=tmp;
        return false;
    }
};
