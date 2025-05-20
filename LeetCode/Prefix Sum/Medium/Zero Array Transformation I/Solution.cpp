// Prefix Sum
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diff(nums.size() + 1);

        for (const auto query : queries) {
            diff[query[0]]++;
            diff[query[1] + 1]--;
        }

        int cur = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cur += diff[i];
            if (nums[i] - cur > 0) return false;
        }
        return true;
    }
};