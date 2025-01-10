class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> universal(26, 0);

        for(const auto& word : words2) {
            vector<int> count(26, 0);
            for(int i = 0; i < word.size(); i++) {
                count[word[i] - 'a']++;
            }
            for(int i = 0; i < count.size(); i++) {
                universal[i] = max(universal[i], count[i]);
            }
        }

        vector<string> answer;
        for(const auto& word : words1) {
            vector<int> count(26, 0);
            bool isSubset = true;

            for(int i = 0; i < word.size(); i++) {
                count[word[i] - 'a']++;
            }
            for(int i = 0; i < count.size(); i++) {
                if (universal[i] > count[i]) {
                    isSubset = false;
                    break;
                }
            }
            if (isSubset) answer.push_back(word);
        }

        return answer;
    }
};