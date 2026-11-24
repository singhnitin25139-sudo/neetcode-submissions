
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:

        # Step 1: Sort intervals based on starting point
        intervals.sort(key=lambda x: x[0])

        result = []

        # Step 2: Traverse all intervals
        for interval in intervals:

            # Step 3: Check if intervals overlap
            if not result or interval[0] > result[-1][1]:

                # No overlap, add new interval
                result.append(interval)

            else:

                # Overlapping intervals, merge them
                result[-1][1] = max(result[-1][1], interval[1])

        return result
