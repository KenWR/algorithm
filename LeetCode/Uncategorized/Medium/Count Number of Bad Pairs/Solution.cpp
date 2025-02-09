class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        vector<int> gaps(nums.size(), 0);
        long long total_pairs = nums.size() * (nums.size() - 1) / 2;
        long long good_pairs = 0;

        for (int i = 0; i < gaps.size(); ++i) {
            gaps[i] = nums[i] - i;
        }

        sort(gaps.begin(), gaps.end());
        long long count = 1;
        for (int i = 1; i < gaps.size(); ++i) {
            if (gaps[i - 1] == gaps[i]) count++;
            else {
                good_pairs += count * (count - 1) / 2;
                count = 1;
            }
        }
        good_pairs += count * (count - 1) / 2;

        return total_pairs - good_pairs;
    }
};