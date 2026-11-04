
class Solution:
    def isHappy(self, n: int) -> bool:

        def getSum(num):
            total = 0

            while num > 0:
                digit = num % 10
                total += digit * digit
                num = num // 10

            return total

        slow = n
        fast = getSum(n)

        while fast != 1 and slow != fast:
            slow = getSum(slow)
            fast = getSum(getSum(fast))

        return fast == 1

        