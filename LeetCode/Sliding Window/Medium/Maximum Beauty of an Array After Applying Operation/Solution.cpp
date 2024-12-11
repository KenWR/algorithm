// Sliding Window

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int largestNum = *max_element(nums.begin(), nums.end()) + 1;
        vector<int> numCount(largestNum, 0);
        
        for (const auto& num : nums) {
            numCount[num] += 1;
        }

        int range = k * 2;
        if (largestNum <= range) return nums.size();
        int count = 0;
        for (int i = 0; i <= range; ++i) {
            count += numCount[i];
        }

        int answer = count;
        for (int i = range + 1; i < largestNum; ++i) {
            count -= numCount[i - range - 1];
            count += numCount[i];
            answer = max(answer, count);
        }

        return answer;
    }
};