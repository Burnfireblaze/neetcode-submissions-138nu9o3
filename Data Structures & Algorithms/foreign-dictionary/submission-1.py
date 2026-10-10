class Solution:
    def foreignDictionary(self, words: List[str]) -> str:
        adj = {c:set() for w in words for c in w}

        for i in range(len(words) -1):
            w1, w2 = words[i], words[i+1]
            min_len = min(len(w1), len(w2))

            if len(w1) > len(w2) and w1[:min_len] == w2[:min_len]:
                return ""
            
            for i in range(min_len):
                if w1[i] != w2[i]:
                    adj[w1[i]].add(w2[i])
                    break
        visited = {}
        res = []
        def dfs(c):
            if c in visited:
                return visited[c]
            
            visited[c] = True
            for nei in adj[c]:
                if dfs(nei):
                    return True
            visited[c] = False
            res.append(c)
        
        for c in adj:
            if dfs(c):
                return ""
        res.reverse()
        return "".join(res)
        
