class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        
        for (const auto &num : nums) {
            sum += num;
        }

        if (sum % 2 == 1) {
            return false;
        }

        bitset<10001> bit(1);
        for (auto i : nums) {
            bit |= bit << i;
            if (bit[sum / 2])
                return true;
        }

        return bit[sum / 2];
    }
};