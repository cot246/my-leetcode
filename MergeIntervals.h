 /**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 /**
 *time:O(nlogn) space:O(1)
 */
 
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.size()<2)return intervals;
        sort(intervals.begin(),intervals.end(),Solution::cmp);
        auto it=begin(intervals);
        auto pre=it;
        vector<Interval> res;
        for(;it!=end(intervals);++it)
        {
            if(pre->end<it->start)
            {
                res.push_back(*pre);
                pre=it;
            }
            else
            {
                if(pre->end<it->end)pre->end=it->end;
            }
        }
        res.push_back(*pre);
        return res;
    }
private:
    static bool cmp(Interval i1,Interval i2)
    {
        return i1.start<i2.start;
    }
};
