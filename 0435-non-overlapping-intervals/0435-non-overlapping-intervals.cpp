class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        if(intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b){
                 return a[1] < b[1];
             });

        int count = 0;

        int start1 = intervals[0][0];
        int end1   = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            int start2 = intervals[i][0];
            int end2   = intervals[i][1];

            if(start2 < end1){
                // overlap → remove current interval
                count++;
            } else {
                // no overlap → update previous interval
                start1 = start2;
                end1   = end2;
            }
        }
        return count;
    }
};
