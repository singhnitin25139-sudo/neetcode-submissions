
from typing import List

class Solution:

    def encode(self, strs: List[str]) -> str:
        encoded_string = ""

        for word in strs:
            encoded_string += str(len(word)) + "#" + word

        return encoded_string

    def decode(self, s: str) -> List[str]:
        decoded_strings = []
        i = 0

        while i < len(s):
            j = i

            # Find the delimiter '#'
            while s[j] != '#':
                j += 1

            # Extract the length of the string
            length = int(s[i:j])

            # Extract the original string
            word = s[j + 1:j + 1 + length]
            decoded_strings.append(word)

            # Move to the next encoded string
            i = j + 1 + length

        return decoded_strings
