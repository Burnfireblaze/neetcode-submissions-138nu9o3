class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """

        stack = []

        n = len(temperatures)

        res = [0] * n

        for i in range(0,n):
            while stack and temperatures[i] > temperatures[stack[-1]]:
                prev = stack.pop()
                res[prev] = i - prev
            stack.append(i)

        return res