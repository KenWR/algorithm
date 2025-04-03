class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<long long> value_of_duolet(nums.size(), 0);
        long long answer = -1;

        int largest_i = 0;
        for (int i = 1; i < nums.size() - 1; ++i) {
            largest_i = max(nums[i - 1], largest_i);
            value_of_duolet[i] = largest_i - nums[i];
        }

        int largest_k = 0;
        for (int i = nums.size() - 1; i >= 2; --i) {
            largest_k = max(nums[i], largest_k);
            long long result = value_of_duolet[i - 1] * largest_k;
            answer = max(result, answer);
        }
        return answer > 0 ? answer : 0;
    }
};