// https://leetcode.com/problems/maximum-score-after-applying-operations-on-a-tree

class Solution:
    def maximumScoreAfterOperations(self, edges: List[List[int]], values: List[int]) -> int:
        n = len(values)

        graph = [[] for _ in range(n)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        visited = [False] * n

        def dfs_min(node):
            visited[node] = True
            if sum(visited[x] for x in graph[node]) == len(graph[node]):
                return values[node]

            xs = []
            for child in graph[node]:
                if visited[child]:
                    continue
                x = dfs_min(child)
                xs.append(x)

            return min(values[node], sum(xs))
        
        return sum(values) - dfs_min(0)