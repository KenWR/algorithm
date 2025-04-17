class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        vector<vector<int>> num_count(101, vector<int>());
        int answer = 0;

        for (int i = 0; i < nums.size(); ++i) {
            num_count[nums[i]].push_back(i);
        }

        for (const auto &count : num_count) {
            for (int i = 0, j = 1; i < count.size(); ++j) {
                if (j == count.size()) {
                    i++;
                    j = i;
                    continue;
                }

                if ((count[i] * count[j]) % k == 0) {
                    answer++;
                }
            }
        }
        return answer;
    }
};