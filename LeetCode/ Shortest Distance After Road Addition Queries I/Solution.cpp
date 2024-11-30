class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        graph = [[i+1] for i in range(n-1)] + [[]]
        dist = list(range(n))
        def process_query(a, b):
            graph[a].append(b)
            if dist[a] + 1 < dist[b]:
                dist[b] = dist[a] + 1
                stack = [b]
                while stack:
                    x = stack.pop()
                    for y in graph[x]:
                        if dist[x] + 1 < dist[y]:
                            dist[y] = dist[x] + 1
                            stack.append(y)

            return dist[n-1]

        return [process_query(a, b) for a, b in queries]