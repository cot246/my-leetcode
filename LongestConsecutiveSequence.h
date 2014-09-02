/**
 *Solution 1
 *time:O(n) space:O(n)
 */
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int ret=0;
        unordered_set<int> st;
        for(int i=0;i<num.size();++i)st.insert(num[i]);
        for(int i=0;i<num.size();++i)
        {
            int cnt=0;
            int cur=num[i];
            if(st.find(cur)!=st.end())
            {
                ++cnt;
                st.erase(cur);
                int pre=cur-1,next=cur+1;
                while(st.find(pre)!=st.end())
                {
                    st.erase(pre);
                    --pre;
                    ++cnt;
                }
                while(st.find(next)!=st.end())
                {
                    st.erase(next);
                    ++next;
                    ++cnt;
                }
            }
            ret=max(ret,cnt);
        }
        return ret;
    }
};
