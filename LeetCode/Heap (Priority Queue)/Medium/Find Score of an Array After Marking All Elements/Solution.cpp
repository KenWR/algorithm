// Heap (Priority Queue)

class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<bool> marked(nums.size());
        long long score = 0;

        auto comp = [](pair<int, int>& pair1, pair<int, int>& pair2) {
            if (pair1.first != pair2.first) return pair1.first > pair2.first;
            return pair1.second > pair2.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> heapNums;

        for (int i = 0; i < nums.size(); ++i) {
            heapNums.push(make_pair(nums[i], i));
        }
        
        while (!heapNums.empty()) {
            int num = heapNums.top().first;
            int index = heapNums.top().second;
            heapNums.pop();

            if (!marked[index]) {
                score += num;
                marked[index] = true;

                if (index != 0) marked[index - 1] =true;
                if (index != nums.size() - 1) marked[index + 1] = true;
            }
        }

        return score;
    }
};