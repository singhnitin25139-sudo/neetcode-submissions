
class Solution:
    def multiply(self, num1: str, num2: str) -> str:

        # Handle zero case
        if num1 == "0" or num2 == "0":
            return "0"

        m = len(num1)
        n = len(num2)

        # Result array
        result = [0] * (m + n)

        # Multiply digits from right to left
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):

                digit1 = ord(num1[i]) - ord('0')
                digit2 = ord(num2[j]) - ord('0')

                product = digit1 * digit2

                total = product + result[i + j + 1]

                result[i + j + 1] = total % 10
                result[i + j] += total // 10

        # Convert result array into string
        answer = ""

        for digit in result:
            if not (len(answer) == 0 and digit == 0):
                answer += str(digit)

        return answer

        