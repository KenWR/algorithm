// Topological Sort

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        size_t n = favorite.size();
        vector<int> inDegree(n, 0);

        for (int i = 0; i < n; ++i) {
            inDegree[favorite[i]]++;
        }

        queue<int> q;

        // 아무도 좋아하지 않는 사람들을 먼저큐에 삽입
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // 초대가 가장 길게 이어지는 노드 찾기
        vector<int> depth(n, 1);
        while (!q.empty()) {
            int person = q.front();
            q.pop();

            int personFavorite = favorite[person];
            depth[personFavorite] = max(depth[personFavorite], depth[person] + 1);

            if (--inDegree[personFavorite] == 0) {
                q.push(personFavorite);
            }
        }

        int longestCycle = 0;           // 가장 긴 사이클의 길이
        int twoCycleInvitations = 0;    // 길이가 2인 사이클에서 초대 가능한 최대 인원

        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) continue;

            int cycleLength = 0;
            int person = i;

            // 방문 표기 및 현재 사람으로부터의 초대 길이 구하기
            while (inDegree[person] != 0) {
                inDegree[person] = 0;
                cycleLength++;

                person = favorite[person];
            }

            if (cycleLength == 2) { // A->B, B->A 의 경우 처리
                twoCycleInvitations += depth[i] + depth[favorite[i]];
            }
            else {
                longestCycle = max(longestCycle, cycleLength);
            }
        }

        // A->B, B->C, C->B 의 경우에는 twoCycleInvitations 이 더 긺
        return max(twoCycleInvitations, longestCycle);
    }
};