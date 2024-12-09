// Binary Search

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> notSpecial;
        vector<bool> answer(queries.size(), true);

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] % 2 == nums[i] % 2) notSpecial.push_back(i - 1); 
        }
        
        for (int i = 0; i < queries.size(); ++i) {
            int left = 0;
            int right = notSpecial.size() - 1;
            while (left <= right) {
                int middle = left + (right - left) / 2;
                
                if (notSpecial[middle] < queries[i][0]) left = middle + 1;
                else if (notSpecial[middle] >= queries[i][1]) right = middle - 1;
                else {
                    answer[i] = false;
                    break;
                }
            }
        }

        return answer;
    }
};