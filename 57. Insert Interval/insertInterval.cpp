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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        int start=newInterval.start, end=newInterval.end, idx=0;
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i].start>=start && intervals[i].end<=end) continue;
            if((intervals[i].start<=start && intervals[i].end>=start) ||
               (intervals[i].start<=end && intervals[i].end>=end) ){
                start = min(start, intervals[i].start);
                end = max(end, intervals[i].end);
            }
            else{
                ans.push_back(intervals[i]);
                if(start>=intervals[i].start) idx=ans.size();
            }
        }
        ans.insert(ans.begin()+idx, Interval(start, end));
        return ans;
    }
};