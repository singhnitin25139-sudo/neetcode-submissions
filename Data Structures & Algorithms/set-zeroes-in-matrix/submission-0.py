
from typing import List

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:

        m = len(matrix)
        n = len(matrix[0])

        # Check if first row contains zero
        first_row_zero = False

        # Check if first column contains zero
        first_col_zero = False

        for j in range(n):
            if matrix[0][j] == 0:
                first_row_zero = True

        for i in range(m):
            if matrix[i][0] == 0:
                first_col_zero = True

        # Mark rows and columns using first row and column
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0

        # Set marked rows to zero
        for i in range(1, m):
            if matrix[i][0] == 0:
                for j in range(1, n):
                    matrix[i][j] = 0

        # Set marked columns to zero
        for j in range(1, n):
            if matrix[0][j] == 0:
                for i in range(1, m):
                    matrix[i][j] = 0

        # Set first row to zero if required
        if first_row_zero:
            for j in range(n):
                matrix[0][j] = 0

        # Set first column to zero if required
        if first_col_zero:
            for i in range(m):
                matrix[i][0] = 0

        
        