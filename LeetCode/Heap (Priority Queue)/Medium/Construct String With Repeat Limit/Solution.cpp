// Heap (Priority Queue)

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> alphabet;
        for (const char& c : s) {
            alphabet[c]++;
        }

        priority_queue<char> maxHeap;
        for (const auto& [c, count] : alphabet) {
            maxHeap.push(c);
        }

        string result;

        while (!maxHeap.empty()) {
            char c = maxHeap.top();
            maxHeap.pop();
            int count = alphabet[c];

            int use = min(count, repeatLimit);
            result.append(use, c);

            alphabet[c] -= use;

            if (alphabet[c] > 0 && !maxHeap.empty()) {
                char nextCh = maxHeap.top();
                maxHeap.pop();

                result.push_back(nextCh);
                alphabet[nextCh]--;

                if (alphabet[nextCh] > 0) {
                    maxHeap.push(nextCh);
                }

                maxHeap.push(c);
            }
        }

        return result;
    }
};