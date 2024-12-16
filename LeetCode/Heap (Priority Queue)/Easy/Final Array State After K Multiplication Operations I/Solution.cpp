// Heap (Priority Queue)

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        auto comp = [](pair<int, int>& pair1, pair<int, int>& pair2) {
            if (pair1.first == pair2.first) return pair1.second > pair2.second;
            return pair1.first > pair2.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> minHeap;
        
        for (int i = 0; i < nums.size(); i++) {
            minHeap.push(make_pair(nums[i], i));
        }

        for (int i = 0; i < k; i++) {
            int value = minHeap.top().first;
            int index = minHeap.top().second;
            minHeap.pop();

            value *= multiplier;
            nums[index] = value;
            minHeap.push(make_pair(value, index));
        }

        return nums;
    }
};