// https://leetcode.com/problems/shortest-path-with-alternating-colors

import queue

class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:

        # creating adjacency list with two vectors for each node, one through red edges and other through blue
        gph = [[[], []] for _ in range(n)]
        # first vector (index 0) represents red
        for ed in redEdges:
            gph[ed[0]][0].append(ed[1])
        # second vector (index 1) represents blue
        for ed in blueEdges:
            gph[ed[0]][1].append(ed[1])

        # creating distance and visited vectors, each index is a vector of size 2
        # (index 0) represents visit / distance though red index
        # (index 1) represents visit / distance though blue index
        vis = [[0, 0] for _ in range(n)]
        d = [[int(1e9), int(1e9)] for _ in range(n)]

        # first item is the node, second item indicates the color we visited it through
        q = queue.Queue()

        # setting source index
        vis[0][0] = vis[0][1] = 1
        q.put([0, 0])
        q.put([0, 1])
        d[0][0] = d[0][1] = 0

        # BFS
        while not q.empty():
            u, f = q.get()
            # getting distance of current node
            cd = d[u][f]
            # flipping f, because we need to visit neighbours though other color edges
            f = 1 - f
            for x in gph[u][f]:
                if not vis[x][f]:
                    # updating distance / visited for flipped f, since we are visiting though other color
                    vis[x][f] = 1
                    q.put([x, f])
                    d[x][f] = cd + 1

        ret = [min(d[i][0], d[i][1]) for i in range(n)]
        ret = [x if x != int(1e9) else -1 for x in ret]
        return ret