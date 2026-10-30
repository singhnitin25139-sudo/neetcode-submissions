
from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:

        ans = []

        top = 0
        bottom = len(matrix) - 1
        left = 0
        right = len(matrix[0]) - 1

        while top <= bottom and left <= right:

            # 1. Traverse from left to right
            for i in range(left, right + 1):
                ans.append(matrix[top][i])
            top += 1

            # 2. Traverse from top to bottom
            for i in range(top, bottom + 1):
                ans.append(matrix[i][right])
            right -= 1

            # 3. Traverse from right to left
            if top <= bottom:
                for i in range(right, left - 1, -1):
                    ans.append(matrix[bottom][i])
                bottom -= 1

            # 4. Traverse from bottom to top
            if left <= right:
                for i in range(bottom, top - 1, -1):
                    ans.append(matrix[i][left])
                left += 1

        return ans
