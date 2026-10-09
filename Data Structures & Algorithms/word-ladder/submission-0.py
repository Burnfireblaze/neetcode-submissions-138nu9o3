class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0

        bucket = defaultdict(list)

        for word in wordList:
            for i in range(len(word)):
                pattern = word[:i] + "*" + word[i+1:]
                bucket[pattern].append(word)
        
        queue = deque([(beginWord,1)])

        visited = {beginWord}

        while queue:
            curr,step = queue.popleft()

            if curr == endWord:
                return step
            for i in range(len(curr)):
                pattern = curr[:i]+ "*" + curr[i+1:]
                for fix in bucket[pattern]:
                    if fix not in visited:
                        visited.add(fix)
                        queue.append((fix, step+1))
        return 0