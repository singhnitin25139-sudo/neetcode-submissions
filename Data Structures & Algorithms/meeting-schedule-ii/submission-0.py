"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""


class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:

        # Step 1: Sort meetings by starting time
        intervals.sort(key=lambda x: x.start)

        # Step 2: Create a min heap
        minHeap = []

        # Step 3: Traverse all meetings
        for interval in intervals:

            # Step 4: If a room is free, remove its ending time
            if minHeap and minHeap[0] <= interval.start:
                heapq.heappop(minHeap)

            # Step 5: Allocate a room for current meeting
            heapq.heappush(minHeap, interval.end)

        # Step 6: Heap size represents minimum rooms required
        return len(minHeap)
