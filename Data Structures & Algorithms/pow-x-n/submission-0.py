
class Solution:
    def myPow(self, x: float, n: int) -> float:

        # Handle negative power
        if n < 0:
            x = 1 / x
            n = -n

        ans = 1.0

        # Binary Exponentiation
        while n > 0:

            # If n is odd, multiply answer by x
            if n % 2 == 1:
                ans = ans * x

            # Square the base
            x = x * x

            # Divide power by 2
            n = n // 2

        return ans

        