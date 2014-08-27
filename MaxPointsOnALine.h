/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 
/**
*Solution 1
*暴力枚举，以点为中心
*time:O(n^2) space:O(n)
*/

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int len=points.size();
        if(len==0)return 0;
        if(len<=2)return len;
        int mx=2;
        for(int i=0;i<len-1;++i)
        {
            unordered_map<double,int> line;
            int same=1,vertical=0;
            for(int j=i+1;j<len;++j)
            {
                if(points[i].x==points[j].x&&points[i].y==points[j].y)++same;
                else if(points[i].x==points[j].x)++vertical;
                else
                {
                    double k=(double)(points[i].y-points[j].y)/(points[i].x-points[j].x);
                    if(line.find(k)!=line.end())++line[k];
                    else line[k]=1;
                }
            }
            for(auto it=line.begin();it!=line.end();++it)
            {
                vertical=max(vertical,it->second);
            }
            mx=max(mx,vertical+same);
        }
        return mx;
    }
};
