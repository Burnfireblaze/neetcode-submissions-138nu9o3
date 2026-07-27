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
    int minMeetingRooms(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(),
     [](auto &a, auto &b){
         return a.start < b.start;
     });
        vector<vector<Interval>> rooms;

        for (auto &meeting : intervals) {

            bool placed = false;

            for (auto &room : rooms) {

                if (room.back().end <= meeting.start) {

                    room.push_back(meeting);
                    placed = true;
                    break;
                }
            }

            if (!placed)
                rooms.push_back({meeting});
        }

        return rooms.size();
    }
};
