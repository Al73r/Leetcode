/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty()) return {};
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), Less);
        int i=1;
        int tmp1=intervals[0].start, tmp2=intervals[0].end;
        while(i<intervals.size()){
            if(tmp2>=intervals[i].start){
                tmp2 = max(tmp2, intervals[i].end);
            }
            else{
                ans.push_back(Interval(tmp1, tmp2));
                tmp1 = intervals[i].start;
                tmp2 = intervals[i].end;
            }
            i++;
        }
        ans.push_back(Interval(tmp1, tmp2));
        return ans;
    }
    static bool Less (const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
};