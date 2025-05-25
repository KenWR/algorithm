// Greedy
// Not solved by myself!
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            });

        priority_queue<int> heap; // 쿼리를 정렬해줄 우선순위 큐
        vector<int> deltaArray(nums.size() + 1, 0); // 인덱스 감소가 끝나는 지점 표시
        int operations = 0;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            operations += deltaArray[i];
            // 우선순위 큐에 쿼리를 nums의 인덱스를 기준으로 힙에 삽입.
            // 이렇게 되면 heap.top() 에는 
            // 특정 인덱스로 시작하는 쿼리들 중에서 범위가 가장 큰 쿼리가 존재하게 됨.
            while (j < queries.size() && queries[j][0] == i) {
                heap.push(queries[j][1]);
                ++j;
            }
            // nums[i] 가 0이 될 때까지 쿼리를 뽑아다 가져온다.
            // 그것도 가장 범위가 높으며 사용되지 않은 쿼리 순서대로.
            while (operations < nums[i] && !heap.empty() && heap.top() >= i) {
                operations += 1;
                deltaArray[heap.top() + 1] -= 1;
                heap.pop();
            }
            // 하지만 쿼리드를 다 뽑아썼음에도 불구하고 특정 인덱스의 값이 0이 되지 못했다면
            if (operations < nums[i]) {
                // 불가능 선언 및 종료
                return -1;
            }
        }
        return heap.size();
    }
};

// 이렇게되면 단 한번의 쿼리(q)와 숫자(n)들의 탐색으로 남은 쿼리 개수를 구할 수 있다.
// 거기에 우선순위 큐의 삽입시 발생하는 log q 만 추가하면 최종적으로
// O(n + q log q) 가 되겠다.