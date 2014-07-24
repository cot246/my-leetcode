/**
 *time:O(n) space:O(n)
 *Manacher's Algorithm, it's a amazing algorithm.
 */

class Solution {
public:
    string longestPalindrome(string s) {
        const int N=s.size();
        string T="@";
        for(int i=0;i<N;++i)T+="#"+s.substr(i,1);
        T+="#$";
        const int M=T.size();
        int P[M];
        int C=0,R=0;
        for(int i=1;i<M-1;++i)
        {
            P[i]=R>i?min(P[2*C-i],R-i):0;
            while(T[i-1-P[i]]==T[i+1+P[i]])++P[i];
            if(P[i]+i>R)
            {
                R=P[i]+i;
                C=i;
            }
        }
        int len=0,center=0;
        for(int i=1;i<M-1;++i)
        {
            if(P[i]>len)
            {
                len=P[i];
                center=i;
            }
        }
        return s.substr((center-1-len)/2,len);
    }
};
