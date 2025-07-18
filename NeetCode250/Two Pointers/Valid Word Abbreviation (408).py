class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        a, b = 0, 0
        while b < len(abbr):
            if not abbr[b].isalpha():
                r = b + 1
                while r < len(abbr) and not abbr[r].isalpha():
                    r += 1
                skip = abbr[b: r]
                if skip[0] == '0':
                    return False
                a += int(skip)
                b += len(skip)
                if a >= len(word):
                    if a != len(word) or b != len(abbr):
                        return False
                    break

            else:
                if word[a] != abbr[b]:
                    return False
                a += 1
                b += 1
        return True