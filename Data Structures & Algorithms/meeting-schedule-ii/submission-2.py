"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRoomsBrute(self, intervals: List[Interval]) -> int:
        if not intervals:
            return 0
        intervals = sorted(intervals, key=lambda i: i.start)
        best = 0
        for i in range(len(intervals)):
            count = 1
            for j in range(i):
                if intervals[j].end > intervals[i].start:
                    count += 1
            best = max(best, count)
        return best
    def minMeetingRooms(self, intervals):
        intervals = sorted(intervals, key=lambda i: i.start)
        rooms = []
        for interval in intervals:
            if rooms and rooms[0] <= interval.start:
                heapq.heapreplace(rooms, interval.end)
            else:
                heapq.heappush(rooms, interval.end)
        return len(rooms)