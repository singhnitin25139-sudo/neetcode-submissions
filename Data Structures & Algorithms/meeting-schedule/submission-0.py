"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:

        # Step 1: Sort meetings by starting time
        intervals.sort(key=lambda x: x.start)

        # Step 2: Check consecutive meetings
        for i in range(1, len(intervals)):

            # Step 3: Check if meetings overlap
            if intervals[i].start < intervals[i - 1].end:
                return False

        # No overlapping meetings
        return True
