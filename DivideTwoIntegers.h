/**
 *Solution 1
 *time:O(logn) space:O(1)
 */
 
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0)return 0;
        long long a=abs((long long)(dividend));
        long long b=abs((long long )(divisor));
        if(a<b)return 0;
        int ret=0;
        if(b==1)ret=a;
        else
        {
            while(a>=b)
            {
                int cnt=0;
                while(a>=(b<<cnt))
                {
                    ret+=1<<cnt;
                    a-=b<<cnt;
                    ++cnt;
                }
            }
        }
        return (dividend>0)^(divisor>0)?-ret:ret;
    }
};
