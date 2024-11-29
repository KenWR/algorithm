class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n, vector<int>(1, 0));
        vector<int> res;

        for (int i = 0; i < graph.size(); ++i) {
            graph[i][0] = i + 1;
        }

        for (const auto& query : queries) {
            graph[query[0]].push_back(query[1]);
            res.push_back(bfs(graph, n, res));
        }
        
        return res;
    }

    int bfs(vector<vector<int>>& graph, int n, vector<int>& res) {
        deque<pair<int, int>> dq;
        vector<bool> visited(n, 0);
        int distance = n - 1;

        dq.push_back(make_pair(0, 0));
        while(!dq.empty()) {
            pair<int, int> currentRoad = dq.front();
            dq.pop_front();
            if (visited[currentRoad.first]) continue;
            visited[currentRoad.first] = true;
            for (const auto nextRoad : graph[currentRoad.first]) {
                if (nextRoad == n) return currentRoad.second;
                if (!res.empty() && currentRoad.second >= res.back()) return res.back();
                dq.push_back(make_pair(nextRoad, currentRoad.second + 1));
            }
        }
        return n - 1;
    }
};