class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool beforeParity = nums[0] % 2;

        for (int i = 1; i < nums.size(); ++i) {
            bool currentParity = nums[i] % 2;

            if (beforeParity == currentParity) return false;
            beforeParity = currentParity;
        }

        return true;
    }
};