
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:

        # Step 1: Sort intervals by ending time
        intervals.sort(key=lambda x: x[1])

        count = 0
        prev_end = intervals[0][1]

        # Step 2: Traverse remaining intervals
        for i in range(1, len(intervals)):

            # Step 3: Check if current interval overlaps
            if intervals[i][0] < prev_end:

                # Remove overlapping interval
                count += 1

            else:

                # Keep current interval
                prev_end = intervals[i][1]

        return count
