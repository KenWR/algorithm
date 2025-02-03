class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int subarrayLength = 0;
        int increaseSubarray = 1, decreaseSubarray = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                increaseSubarray++;
                subarrayLength = max(subarrayLength, decreaseSubarray);
                decreaseSubarray = 1;
            }
            else if (nums[i - 1] > nums[i]) {
                decreaseSubarray++;
                subarrayLength = max(subarrayLength, increaseSubarray);
                increaseSubarray = 1;
            }
            else {
                subarrayLength = max(subarrayLength, decreaseSubarray);
                subarrayLength = max (subarrayLength, increaseSubarray);
                decreaseSubarray = 1;
                increaseSubarray = 1;
            }
        }

        subarrayLength = max(subarrayLength, decreaseSubarray);
        subarrayLength = max (subarrayLength, increaseSubarray);

        return subarrayLength;
    }
};