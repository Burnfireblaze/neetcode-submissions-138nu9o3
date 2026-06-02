class TrieNode(object):
    def __init__(self):
        self.children = {}
        self.word = None
class Solution:

    def __init__(self):
        self.root = TrieNode()


    def buildTree(self, words):
        for word in words:
            node = self.root

            for ch in word:
                if ch not in node.children:
                    node.children[ch] = TrieNode()

                node = node.children[ch]

            node.word = word


    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:

        self.buildTree(words)

        rows = len(board)
        cols = len(board[0])
        result = []


        def dfs(r, c, node):

            # invalid positions
            if (
                r < 0 or r >= rows or
                c < 0 or c >= cols
            ):
                return


            char = board[r][c]


            # current path does not exist in Trie
            if char not in node.children:
                return


            # move inside Trie
            node = node.children[char]


            # found a complete word
            if node.word:
                result.append(node.word)

                # avoid duplicates
                node.word = None


            # mark visited
            board[r][c] = "#"


            dfs(r+1, c, node)
            dfs(r-1, c, node)
            dfs(r, c+1, node)
            dfs(r, c-1, node)


            # restore
            board[r][c] = char


        for r in range(rows):
            for c in range(cols):
                dfs(r, c, self.root)


        return result
    
        