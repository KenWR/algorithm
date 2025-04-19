// Binary Search

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long answer = 0;

        sort(nums.begin(), nums.end());

        int prev = nums.front() + 1;
        int count_of_fair_pairs = 0;
        auto prev_iter_lower = nums.end();
        for (int i = 0; i < nums.size() - 1; ++i) {
            auto current = nums.begin() + i;
            if (prev == nums[i]) {
                if (prev_iter_lower <= current) {
                    count_of_fair_pairs = std::max(0, count_of_fair_pairs - 1);
                }
                answer += count_of_fair_pairs;
                continue;
            }

            long long value_lower = lower - nums[i];
            long long value_upper = upper - nums[i];

            auto iter_lower = lower_bound(current + 1, nums.end(), value_lower);
            auto iter_upper = upper_bound(current + 1, nums.end(), value_upper);

            count_of_fair_pairs = distance(iter_lower, iter_upper);
            answer += count_of_fair_pairs;
            prev_iter_lower = iter_lower;
            prev = nums[i];
        }
        return answer;
    }
};

// nums를 정렬하고 배열의 시작부터 i로 고정하고 
// nums[i] + nums[j] 가 lower를 충족하는 j를 이분 탐색으로 찾는다.
// 그 후 upper를 충족하는 j의 개수를 탐색하고
// i를 증가시키며 nums[i] 의 값이 이전과 동일한 경우 이전에 찾은 j의 값을 FairPairs의 개수에 포함 시킨다.
// 만약 j 개수 범위에 새로 증가된 i의 값이 포함된다면 j의 개수를 1 감소한다.

// 정렬에 n log(n)
// 이분탐색에 n log(n)
// 총 n log(n) 으로 1초당 약 1억(10^8) 연산을 기준으로
// n = 10^5, log n ≈ 17, 100000 * 17 -> 0.017 
// 여러 부가적인 요소들을 더하면 0.025초 내외가 되겠다.