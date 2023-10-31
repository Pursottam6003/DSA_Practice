/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */

    static bool comp(vector <int> a,vector<int> &b)
    {
        return a[1] > b[1];
    }
    bool canAttendMeetings(vector<Interval> &intervals) {
        // Write your code here
        // sort the vector 
        sort(intervals.begin(),intervals.end(),comp);

        int prev=0;
    
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[prev][1] > intervals[i][0] )
            {
                prev = i;
            }
        }

        return true;
    
        }    
}