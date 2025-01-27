// Breadth-First Search

// Floyd-Warshall과 위상 정렬로 풀수 있다고 함 나중에 추가적으로 풀어볼 것

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // prerequisites[i][1] 강의를 들으려면 prerequisites[i][0]를 들어야 함
        // 그래서 queries[j][0] 강의가 queries[j][1] 강의를 전제로 두는가?
        // 즉 그래프의 여러 부분 내에서 속해있는가를 구하는 문제
        
        // 2 <= numCourses <= 100 으로 꽤 적고
        // 1 <= queries.length <= 10^4 로 꽤 긴걸 볼 수 있다

        // 이를 통해 우리가 최적화 해야하는 것이 
        // queries의 두 요소가 동일한 연결되는 부분집합 내에 존재하는지를 찾는 것임을 알 수 있다

        // 이제 풀이 방식을 정해야한다
        // 간선들을 가지고 풀이를하는데,
        // 들어오는 간선 (인덱스가 전제조건 코스, 요소들이 해당 코스를 들으면 들을 수 있는 코스들)
        // 나가는 간선 (인덱스가 들을 수 있는 코스, 요소들이 인덱스의 전제 조건 코스)
        // 위 둘 중 어느 것을 기준으로 잡느냐에 따라 풀이가 달라진다

        // graph가 cycle을 가지지 않는다는데 그러면 트리 구조가 되지 않나?
        // 그렇다면 부분 트리에서 특정 요소를 빠르게 찾을 수 있는 알고리즘이 뭐가 있을까?
        // 이진트리가 아니기에 쓸만한 알고리즘은 몇가지 없을것이다

        // 들어오는 간선을 기준으로 numCourses * numCourses 그래프 만들고 
        // 인덱스 참조를 통해 요소 하나씩 대입해가며 찾는것이 먼저 떠올랐다
        // 하지만 이보다는 부분 트리들을 나열해 놓고 여기서 찾는 것이 더빠르지 않나 싶었다

        // 아니면 트리를 전부 탐색하면서 인덱스로부터 해당 요소로 접근할 수 있는지 미리 계산하는 방법도 있다
        // vector<vector<bool>> isPossible(numCourses, vector<int>(numCourses, false));
        // isPossible[0] == 시작 노드
        // isPossible[0][i] == 노드 i와 연결되어 있는지 여부를 체크
        // cycle은 존재하지 않으므로 BFS로 탐색해가며 방문 여부를 체크하면 될 것이다

        // BFS 탐색을 위한 그래프 생성
        vector<vector<int>> graph(numCourses);

        for (int i = 0; i < prerequisites.size(); ++i) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        // BFS로 각 노드들의 연결 여부 확인
        vector<vector<bool>> isPossible(numCourses, vector<bool>(numCourses, false));
        bfs(numCourses, graph, isPossible);

        vector<bool> answer(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            answer[i] = isPossible[queries[i][0]][queries[i][1]];
        }

        return answer;
    }

    void    bfs(int numCourses, vector<vector<int>> graph, vector<vector<bool>> &isPossible) {
        deque<int> dq;

        for (int index = 0; index < numCourses; ++index) {
            vector<bool> visited(numCourses, false);
            for (int i = 0; i < graph[index].size(); ++i) {
                dq.push_back(graph[index][i]);
            }

            while (!dq.empty()) {
                int curNode = dq.front();
                dq.pop_front();
                if (visited[curNode] == true) continue;
                else if (visited[curNode] == false) visited[curNode] = true;

                isPossible[index][curNode] = true;
                for (int i = 0; i < graph[curNode].size(); ++i) {
                    dq.push_back(graph[curNode][i]);
                }
            }
        }
    }
};