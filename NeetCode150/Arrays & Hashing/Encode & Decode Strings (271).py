from typing import List

class Solution:

    def encode(self, strs: List[str]) -> str:
        if strs == []:
            print('tt')
            return -1
        print("enc", ','.join(strs))
        return '~'.join(strs)
    def decode(self, s: str) -> List[str]:
        print("dec", str.split(','))
        if s == -1:
            return []
        return s.split('~')