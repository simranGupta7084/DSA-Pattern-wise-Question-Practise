class Solution:
    def compress(self, chars: List[str]) -> int:
        n = len(chars)
        read = 0
        write = 0

        while read < n:
            curr_char = chars[read]
            count = 0

            # Read and coount characters
            while read < n and chars[read] == curr_char:
                count += 1
                read += 1

            # Write the character
            chars[write] = curr_char
            write += 1

            # Write the frequency
            if count > 1:
                for digit in str(count):
                    chars[write] = digit
                    write += 1

        return write
        