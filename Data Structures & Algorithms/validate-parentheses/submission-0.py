class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2 != 0:
            return False

        mapping = {
            ')': '(',
            '}': '{',
            ']': '['
        }

        stack = []

        for st in s:
            if st not in mapping:
                stack.append(st)
            elif st in mapping:
                if not stack or stack.pop() != mapping[st]:
                    return False
        return len(stack) == 0