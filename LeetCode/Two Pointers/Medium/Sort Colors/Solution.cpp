// Two Pointers
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); ++i) {
            while (i < nums.size() && nums[i] == 0) {
                i++;
            }
            for (size_t j = i + 1; j < nums.size(); ++j) {
                if (nums[j] == 0) {
                    swap(nums[i++], nums[j]);
                }
            }

            while (i < nums.size() && nums[i] == 1) {
                i++;
            }
            for (size_t j = i + 1; j < nums.size(); ++j) {
                if (nums[j] == 1) {
                    swap(nums[i++], nums[j]);
                }
            }
        }
    }
};