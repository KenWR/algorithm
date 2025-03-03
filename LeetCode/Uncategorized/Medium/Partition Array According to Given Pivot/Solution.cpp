class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> low, high;
        int same_pivot_count = 0;

        for (const auto num : nums) {
            if (num < pivot) low.push_back(num);
            else if (num > pivot) high.push_back(num);
            else ++same_pivot_count;
        }

        while (same_pivot_count--) low.push_back(pivot);

        low.insert(low.end(), high.begin(), high.end());

        return low;
    }
};