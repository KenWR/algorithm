class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> map;
        int tuple_count = 0;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                map[nums[i] * nums[j]] += 1;
            }
        }

        for (const auto& pair : map) {
            tuple_count += countTuple(pair.second);
        }

        return tuple_count;
    }

    int countTuple(int tuple_num) {
        if (tuple_num == 1) return 0;

        int count = 0;

        for (int i = 1; i < tuple_num; ++i) { count += i; }

        return (count * 8);
    }
};