// Monotonic Deque
// Not my solve!!
// studying...

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int> maxQ, minQ; // 현재 window에서의 최대, 최소 인덱스
        long long count = 0;
        int left = 0;

        for (int i = 0; i < nums.size(); i++) { // 윈도우 크기 오른쪽으로 하나씩 늘려가며

            // ==============================
            // 여기가 Monotonic Deque로 알고리즘에 맞게 단조로운 큐를 관리
            // 큐에는 최대값, 최소값이 단조롭게 담기며 이 두개의 큐를 이용하여 윈도우 내의 하위 배열 개수를 구한다

            // 점점 작아지는 최대값 목록 작성
            while (!maxQ.empty() && nums[maxQ.back()] < nums[i]) {
                maxQ.pop_back();
            }
            maxQ.push_back(i);

            // 점점 커지는 최소값 목록 작성
            while (!minQ.empty() && nums[minQ.back()] > nums[i]) {
                minQ.pop_back();
            }
            minQ.push_back(i);
            // ==============================

            // 윈도우 축소 작업: 최대값과 최소값 차이가 2가 넘으면
            while (!maxQ.empty() && !minQ.empty() && nums[maxQ.front()] - nums[minQ.front()] > 2) {
                // 여기서 이제 최대, 최소값의 인덱스 차이를 통해 어느쪽에서 균형이 깨졌는지 알 수 있음
                if (maxQ.front() < minQ.front()) {
                    left = maxQ.front() + 1;
                    maxQ.pop_front();
                }
                else {
                    left = minQ.front() + 1;
                    minQ.pop_front();
                }
            }
            // 유효 서브 배열 개수를 추가
            count += i - left + 1;
        }

        return count;
    }
};