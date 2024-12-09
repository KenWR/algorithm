class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> notSpecial;
        vector<bool> answer(queries.size(), true);

        for (int i = 1; i < nums.size(); ++i) {
            bool beforeParity = nums[i - 1] % 2;
            bool nowParity = nums[i] % 2;
            if (beforeParity == nowParity) notSpecial.push_back(i - 1); 
        }
        
        for (int i = 0; i < queries.size(); ++i) {
            for (int j = 0; j < notSpecial.size(); ++j) {
                if (queries[i][0] <= notSpecial[j] && notSpecial[j] < queries[i][1]) {
                    answer[i] = false;
                    break;
                }
            }
        }

        return answer;
    }
};