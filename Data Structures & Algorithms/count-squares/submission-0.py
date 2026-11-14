
class CountSquares:

    def __init__(self):
        # Dictionary to store point frequencies
        self.points = {}

    def add(self, point: List[int]) -> None:

        x, y = point

        # Store frequency of each point
        self.points[(x, y)] = self.points.get((x, y), 0) + 1

    def count(self, point: List[int]) -> int:

        x, y = point
        ans = 0

        # Check every stored point as a possible diagonal
        for (x1, y1), freq in self.points.items():

            # Diagonal must have equal horizontal and vertical distance
            if x == x1 or abs(x - x1) != abs(y - y1):
                continue

            # Find the remaining two corners
            p1 = (x1, y)
            p2 = (x, y1)

            # Count all possible combinations
            ans += (
                freq
                * self.points.get(p1, 0)
                * self.points.get(p2, 0)
            )

        return ans

